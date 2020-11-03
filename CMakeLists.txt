cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
project(ideal-gas)

# This tells the compiler to not aggressively optimize and
# to include debugging information so that the debugger
# can properly read what's going on.
set(CMAKE_BUILD_TYPE Debug)

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

# Let's nicely support folders in IDE's
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Warning flags
if(MSVC)
    # warning level 3 and all warnings as errors
    add_compile_options(/W3 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wpedantic -Werror)
endif()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)

# FetchContent_MakeAvailable was not added until CMake 3.14
if(${CMAKE_VERSION} VERSION_LESS 3.14)
    include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.x
)

# Adds Catch2 testing library
#FetchContent_MakeAvailable(catch2)
FetchContent_GetProperties(catch2)
if(NOT catch2_POPULATED)
    FetchContent_Populate(catch2)
    #add_library(catch2 INTERFACE tests/image_processor_tests.cpp)
    add_library(catch2 INTERFACE)
    target_include_directories(catch2 INTERFACE ${catch2_SOURCE_DIR}/single_include)
endif()

get_filename_component(CINDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../" ABSOLUTE)
message(${CINDER_PATH})
get_filename_component(APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/" ABSOLUTE)

include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

list(APPEND CORE_SOURCE_FILES src/core/particle.cpp src/core/image_parser.cpp src/core/model_trainer.cpp)


list(APPEND SOURCE_FILES    ${CORE_SOURCE_FILES}
                            #src/core/image_processor.cpp
                            #src/core/image.cpp
                            src/visualizer/naive_bayes_app.cc
                            src/visualizer/sketchpad.cc)

list(APPEND TEST_FILES tests/image_tests.cc tests/image_parser_tests.cpp tests/model_trainer_tests.cpp tests/image_classifier_tests.cpp)

add_executable(train-model apps/main.cc ${CORE_SOURCE_FILES} src/core/model_trainer.cpp include/core/image_classifier.h src/core/image_classifier.cpp)
target_include_directories(train-model PRIVATE include)

ci_make_app(
        APP_NAME        sketchpad-classifier
        CINDER_PATH     ${CINDER_PATH}
        SOURCES         apps/cinder_app_main.cc ${SOURCE_FILES}
        INCLUDES        include
)

ci_make_app(
        APP_NAME        naive-bayes-test
        CINDER_PATH     ${CINDER_PATH}
        SOURCES         tests/test_main.cc ${SOURCE_FILES} ${TEST_FILES}
        INCLUDES        include
        LIBRARIES       catch2
)

if(MSVC)
    set_property(TARGET naive-bayes-test APPEND_STRING PROPERTY LINK_FLAGS " /SUBSYSTEM:CONSOLE")
endif()