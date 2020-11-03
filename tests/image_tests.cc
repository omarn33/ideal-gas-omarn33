#include <core/particle.h>

#include <catch2/catch.hpp>
#include <fstream>
#include <iostream>

TEST_CASE("Image Testing") {

  SECTION("Image length is less than or equal to 0")
  {
    std::ifstream image_file;
    image_file.open("C:\\Users\\Omar\\Desktop\\cinder_0.9.2_vc2015\\my-projects\\naivebayes-omarn33\\data\\trainingimages");

    REQUIRE(true);
  }

  SECTION("Image Length is greater than 0")
  {
    REQUIRE(true);
  }

  SECTION("Test that 2d contains sample numbers")
  {
    REQUIRE(true);
  }

  SECTION("Check that 28 x 28 image parses correctly")
  {
    REQUIRE(true);
  }
}



/*
TODO: Rename this test file. You'll also need to modify CMakeLists.txt.

You can (and should) create more test files; this project is too big
for all tests to be in the same file. Remember that, for each file (foo.cc)
containing non-trivial code, you should have a corresponding test file
(foo_test.cc)

Make sure to add any files that you create to CMakeLists.txt.

TODO Delete this comment and the placeholder test before submitting your code.
*/
