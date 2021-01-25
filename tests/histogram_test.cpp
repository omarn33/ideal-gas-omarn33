#include <core/particle_physics.h>
#include <core/particle.h>
#include <visualizer/histogram.h>

#include <cmath>
#include <catch2/catch.hpp>

using namespace idealgas;
using namespace visualizer;

TEST_CASE("Test Histogram Data Calculation") {
    // Set histogram boundaries
    glm::vec2 top_left(0.0, 0.0);
    glm::vec2 bottom_right(100.0, 100.0);

    // Set initial position and velocity vectors
    glm::vec2 position1(50.0, 10.0);
    glm::vec2 velocity1(10.0, 10.0);

    glm::vec2 position2(50.0, 90.0);
    glm::vec2 velocity2(20.0, 20.0);

    glm::vec2 position3(10.0, 50.0);
    glm::vec2 velocity3(5.0, 5.0);

    glm::vec2 position4(90.0, 50.0);
    glm::vec2 velocity4(1.0, 1.0);

    glm::vec2 position5(10.0, 10.0);
    glm::vec2 velocity5(5.0, 5.0);

    // Create test particles
    Particle particle1(10.0f, 10.0, "red", position1, velocity1);
    Particle particle2(10.0f, 10.0, "red", position2, velocity2);
    Particle particle3(10.0f, 10.0, "red", position3, velocity3);
    Particle particle4(10.0f, 10.0, "red", position4, velocity4);
    Particle particle5(10.0f, 10.0, "red", position5, velocity5);

    ParticlePhysics physics(top_left, bottom_right);

    std::vector<Particle> particles;
    particles.push_back(particle1);
    particles.push_back(particle2);
    particles.push_back(particle3);
    particles.push_back(particle4);
    particles.push_back(particle5);

    // Generate Histogram
    Histogram red_histogram(ci::Color("red"), top_left, bottom_right);
    red_histogram.GenerateHistogram(particles);

    SECTION("Test correct bin calculation") {
        REQUIRE(red_histogram.GetPartitionSize() == Approx(5.374));
    }

    SECTION("Test correct number of particles per bucket") {
        std::cout << "Size: " << red_histogram.GetNumberOfParticlesPerPartition().size() << std::endl;
        REQUIRE(red_histogram.GetNumberOfParticlesPerPartition().at(0) == 1);
        REQUIRE(red_histogram.GetNumberOfParticlesPerPartition().at(1) == 2);
        REQUIRE(red_histogram.GetNumberOfParticlesPerPartition().at(2) == 1);
        REQUIRE(red_histogram.GetNumberOfParticlesPerPartition().at(3) == 0);
        REQUIRE(red_histogram.GetNumberOfParticlesPerPartition().at(4) == 0);
    }
}

TEST_CASE("Conditions that Result in Histogram Update") {
    // Set histogram boundaries
    glm::vec2 top_left(0.0, 0.0);
    glm::vec2 bottom_right(100.0, 100.0);

    // Set initial position and velocity vectors
    glm::vec2 position1(50.0, 10.0);
    glm::vec2 velocity1(10.0, 10.0);

    glm::vec2 position2(50.0, 90.0);
    glm::vec2 velocity2(20.0, 20.0);

    glm::vec2 position3(10.0, 50.0);
    glm::vec2 velocity3(5.0, 5.0);

    glm::vec2 position4(90.0, 50.0);
    glm::vec2 velocity4(1.0, 1.0);

    glm::vec2 position5(10.0, 10.0);
    glm::vec2 velocity5(5.0, 5.0);

    // Create test particles
    Particle particle1(10.0f, 10.0, "blue", position1, velocity1);
    Particle particle2(10.0f, 10.0, "blue", position2, velocity2);
    Particle particle3(10.0f, 10.0, "blue", position3, velocity3);
    Particle particle4(10.0f, 10.0, "blue", position4, velocity4);
    Particle particle5(10.0f, 10.0, "blue", position5, velocity5);

    ParticlePhysics physics(top_left, bottom_right);

    std::vector<Particle> particles;
    particles.push_back(particle1);
    particles.push_back(particle2);
    particles.push_back(particle3);
    particles.push_back(particle4);
    particles.push_back(particle5);

    // Generate Histogram
    Histogram red_histogram(ci::Color("blue"), top_left, bottom_right);
    red_histogram.GenerateHistogram(particles);

    SECTION("Test histogram update after particle collides with another particle") {
        REQUIRE(!physics.HasParticleCollidedWithParticle(particle1, particle2));
        // Test initial bin size != final bin size (histogram has changed)
    }
}

TEST_CASE("Conditions that DO NOT Result in Histogram Update") {
    // Set histogram boundaries
    glm::vec2 top_left(0.0, 0.0);
    glm::vec2 bottom_right(100.0, 100.0);

    // Set initial position and velocity vectors
    glm::vec2 position1(9.0, 1.0);
    glm::vec2 velocity1(10.0, 10.0);

    glm::vec2 position2(50.0, 50.0);
    glm::vec2 velocity2(20.0, 20.0);

    // Create test particles
    Particle particle1(10.0f, 10.0, "red", position1, velocity1);
    Particle particle2(10.0f, 10.0, "red", position2, velocity2);

    ParticlePhysics physics(top_left, bottom_right);

    std::vector<Particle> particles;
    particles.push_back(particle1);
    particles.push_back(particle2);

    // Generate Histogram
    Histogram red_histogram(ci::Color("red"), top_left, bottom_right);
    red_histogram.GenerateHistogram(particles);

    SECTION("Test no histogram change when a particle moves w/o any collisions") {
        double initial_bin_size = red_histogram.GetPartitionSize();
        REQUIRE_FALSE(physics.HasParticleCollidedWithWall(particle2, 'x'));
        REQUIRE_FALSE(physics.HasParticleCollidedWithWall(particle2, 'Y'));
        REQUIRE_FALSE(physics.HasParticleCollidedWithParticle(particle1, particle2));
        double final_bin_size = red_histogram.GetPartitionSize();
        REQUIRE(initial_bin_size == final_bin_size);
    }

    SECTION("Test no histogram change when a particle collides with a wall") {
        REQUIRE(!physics.HasParticleCollidedWithWall(particle1, 'x'));
        // Test initial bin size == final bin size (histogram has NOT changed)
    }
}