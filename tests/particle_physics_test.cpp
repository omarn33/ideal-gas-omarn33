#include <core/particle_physics.h>
#include <core/particle.h>

#include <catch2/catch.hpp>
#include <iostream>

using namespace idealgas;

TEST_CASE("Verify Condition Where Particles Bounce within Container") {
    // Set container boundaries
    glm::vec2 top_left(0.0, 0.0);
    glm::vec2 bottom_right(100.0, 100.0);

    // Set initial position and velocity vectors
    glm::vec2 position1(50.0, 10.0);
    glm::vec2 velocity1(1.0, -1.0);

    glm::vec2 position2(50.0, 90.0);
    glm::vec2 velocity2(1.0, 1.0);

    glm::vec2 position3(10.0, 50.0);
    glm::vec2 velocity3(-1.0, 1.0);

    glm::vec2 position4(90.0, 50.0);
    glm::vec2 velocity4(1.0, 1.0);

    glm::vec2 position5(10.0, 10.0);
    glm::vec2 velocity5(-1.0, -1.0);

    glm::vec2 position6(90.0, 90.0);
    glm::vec2 velocity6(1.0, 1.0);

    // Particle created to bounce off upper boundary
    Particle upper_particle(10.0f, 10.0, "white", position1, velocity1);

    // Particle created to bounce off lower boundary
    Particle lower_particle(10.0f, 10.0, "white", position2, velocity2);

    // Particle created to bounce off left boundary
    Particle left_particle(10.0f, 10.0, "white", position3, velocity3);

    // Particle created to bounce off right boundary
    Particle right_particle(10.0f, 10.0, "white", position4, velocity4);

    // Particle created to bounce off upper left corner boundary (positive x and y velocities)
    Particle upper_corner_particle(10.0f, 10.0, "white", position5, velocity5);

    // Particle created to bounce off lower right corner boundary (negative x and y velocities)
    Particle lower_corner_particle(10.0f, 10.0, "white", position6, velocity6);

    // Vector of Particles
    std::vector<Particle> particles = {upper_particle, lower_particle, right_particle, left_particle, upper_corner_particle, lower_corner_particle};

    ParticlePhysics physics(particles, top_left, bottom_right);

    REQUIRE(particles.size() == 6);

    SECTION("Test particle bouncing off upper boundary")
    {
        REQUIRE(physics.HasCollidedWithWall(upper_particle, 'y'));
    }

    SECTION("Test particle bouncing off lower boundary") {
        REQUIRE(physics.HasCollidedWithWall(lower_particle, 'y'));
    }

    SECTION("Test particle bouncing off left boundary") {
        REQUIRE(physics.HasCollidedWithWall(left_particle, 'x'));
    }

    SECTION("Test particle bounces off right boundary") {
        REQUIRE(physics.HasCollidedWithWall(right_particle, 'x'));
    }

    SECTION("Test particle bouncing off upper right corner boundary") {
        REQUIRE(physics.HasCollidedWithWall(upper_corner_particle, 'x'));
        REQUIRE(physics.HasCollidedWithWall(upper_corner_particle, 'y'));
    }

    SECTION("Test particle bouncing off bottom left corner boundary") {
        REQUIRE(physics.HasCollidedWithWall(lower_corner_particle, 'x'));
        REQUIRE(physics.HasCollidedWithWall(lower_corner_particle, 'y'));
    }
}

TEST_CASE("Verify Conditions Where Particles do NOT Bounce within Container") {
    // Set container boundaries
    glm::vec2 top_left(0.0, 0.0);
    glm::vec2 bottom_right(100.0, 100.0);

    // Set initial position and velocity vectors
    glm::vec2 position1(50.0, 10.0);
    glm::vec2 velocity1(1.0, 1.0);

    glm::vec2 position2(50.0, 90.0);
    glm::vec2 velocity2(1.0, -1.0);

    glm::vec2 position3(10.0, 50.0);
    glm::vec2 velocity3(1.0, 1.0);

    glm::vec2 position4(90.0, 50.0);
    glm::vec2 velocity4(-1.0, 1.0);

    glm::vec2 position5(10.0, 10.0);
    glm::vec2 velocity5(1.0, 1.0);

    glm::vec2 position6(90.0, 90.0);
    glm::vec2 velocity6(-1.0, -1.0);

    glm::vec2 position7(50.0, 50.0);
    glm::vec2 velocity7(1.0, 1.0);

    // Particle created to NOT bounce in the middle of the container
    Particle middle_particle(10.0f, 10.0, "white", position7, velocity7);

    // Particle created to NOT bounce off upper boundary
    Particle upper_particle(10.0f, 10.0, "white", position1, velocity1);

    // Particle created to NOT bounce off lower boundary
    Particle lower_particle(10.0f, 10.0, "white", position2, velocity2);

    // Particle created to NOT bounce off left boundary
    Particle left_particle(10.0f, 10.0, "white", position3, velocity3);

    // Particle created to NOT bounce off right boundary
    Particle right_particle(10.0f, 10.0, "white", position4, velocity4);

    // Particle created to NOT bounce off upper left corner boundary (positive x and y velocities)
    Particle upper_corner_particle(10.0f, 10.0, "white", position5, velocity5);

    // Particle created to NOT bounce off lower right corner boundary (negative x and y velocities)
    Particle lower_corner_particle(10.0f, 10.0, "white", position6, velocity6);

    // Vector of Particles
    std::vector<Particle> particles = {middle_particle, upper_particle, lower_particle, right_particle, left_particle, upper_corner_particle, lower_corner_particle};

    ParticlePhysics physics(particles, top_left, bottom_right);

    REQUIRE(particles.size() == 7);

    SECTION("Test particle does not bounce in the middle of the container")
    {
        REQUIRE(!physics.HasCollidedWithWall(upper_particle, 'x'));
        REQUIRE(!physics.HasCollidedWithWall(upper_particle, 'y'));
    }

    SECTION("Test particle does not bounce off upper boundary given +y velocity")
    {
        REQUIRE(!physics.HasCollidedWithWall(upper_particle, 'y'));
    }

    SECTION("Test particle does not bounce off lower boundary given -y velocity") {
        REQUIRE(!physics.HasCollidedWithWall(lower_particle, 'y'));
    }

    SECTION("Test particle does not bounce off left boundary given +x velocity") {
        REQUIRE(!physics.HasCollidedWithWall(left_particle, 'x'));
    }

    SECTION("Test particle does not bounce off right boundary given -x velocity") {
        REQUIRE(!physics.HasCollidedWithWall(right_particle, 'x'));
    }

    SECTION("Test particle does not bounce off upper right corner given +x and +y velocity") {
        REQUIRE(!physics.HasCollidedWithWall(upper_corner_particle, 'x'));
        REQUIRE(!physics.HasCollidedWithWall(upper_corner_particle, 'y'));
    }

    SECTION("Test particle does not bounce off upper right corner given -x and -y velocity") {
        REQUIRE(!physics.HasCollidedWithWall(lower_corner_particle, 'x'));
        REQUIRE(!physics.HasCollidedWithWall(lower_corner_particle, 'y'));
    }
}

TEST_CASE("Verify Velocity After Wall Collision") {
    // Set container boundaries
    glm::vec2 top_left(0.0, 0.0);
    glm::vec2 bottom_right(100.0, 100.0);

    // Set initial position and velocity vectors
    glm::vec2 position1(50.0, 10.0);
    glm::vec2 velocity1(1.0, -1.0);

    glm::vec2 position2(50.0, 90.0);
    glm::vec2 velocity2(1.0, 1.0);

    glm::vec2 position3(10.0, 50.0);
    glm::vec2 velocity3(-1.0, 1.0);

    glm::vec2 position4(90.0, 50.0);
    glm::vec2 velocity4(1.0, 1.0);

    glm::vec2 position5(10.0, 10.0);
    glm::vec2 velocity5(-1.0, -1.0);

    glm::vec2 position6(90.0, 90.0);
    glm::vec2 velocity6(1.0, 1.0);

    // Particle created to bounce off upper boundary
    Particle upper_particle(10.0f, 10.0, "white", position1, velocity1);

    // Particle created to bounce off lower boundary
    Particle lower_particle(10.0f, 10.0, "white", position2, velocity2);

    // Particle created to bounce off left boundary
    Particle left_particle(10.0f, 10.0, "white", position3, velocity3);

    // Particle created to bounce off right boundary
    Particle right_particle(10.0f, 10.0, "white", position4, velocity4);

    // Particle created to bounce off upper left corner boundary (positive x and y velocities)
    Particle upper_corner_particle(10.0f, 10.0, "white", position5, velocity5);

    // Particle created to bounce off lower right corner boundary (negative x and y velocities)
    Particle lower_corner_particle(10.0f, 10.0, "white", position6, velocity6);

    // Vector of Particles
    std::vector<Particle> particles = {upper_particle, lower_particle, right_particle, left_particle, upper_corner_particle, lower_corner_particle};

    ParticlePhysics physics(particles, top_left, bottom_right);

    REQUIRE(particles.size() == 6);

    SECTION("Test velocity after particle bounced off upper boundary")
    {
        REQUIRE(physics.HasCollidedWithWall(upper_particle, 'y'));
        physics.CalculateVelocityAfterWallCollision(upper_particle, 'y');
        REQUIRE(lower_particle.GetVelocity().y == 1.0f);
    }

    SECTION("Test velocity after particle bounced off lower boundary") {
        REQUIRE(physics.HasCollidedWithWall(lower_particle, 'y'));
        physics.CalculateVelocityAfterWallCollision(lower_particle, 'y');
        REQUIRE(lower_particle.GetVelocity().y == -1.0f);
    }

    SECTION("Test velocity after particle bounced off left boundary") {
        REQUIRE(physics.HasCollidedWithWall(left_particle, 'x'));
        physics.CalculateVelocityAfterWallCollision(left_particle, 'x');
        REQUIRE(left_particle.GetVelocity().x == 1.0f);
    }

    SECTION("Test velocity after particle bounced off right boundary") {
        REQUIRE(physics.HasCollidedWithWall(right_particle, 'x'));
        physics.CalculateVelocityAfterWallCollision(right_particle, 'x');
        REQUIRE(right_particle.GetVelocity().x == -1.0f);
    }

    SECTION("Test velocity after particle bounced off the upper left corner") {
        REQUIRE(physics.HasCollidedWithWall(upper_corner_particle, 'x'));
        REQUIRE(physics.HasCollidedWithWall(upper_corner_particle, 'y'));
        physics.CalculateVelocityAfterWallCollision(upper_corner_particle, 'x');
        physics.CalculateVelocityAfterWallCollision(upper_corner_particle, 'y');
        REQUIRE(upper_corner_particle.GetVelocity().x == 1.0f);
        REQUIRE(upper_corner_particle.GetVelocity().y == 1.0f);
    }

    SECTION("Test velocity after particle bounced off the bottom right corner") {
        REQUIRE(physics.HasCollidedWithWall(lower_corner_particle, 'x'));
        REQUIRE(physics.HasCollidedWithWall(lower_corner_particle, 'y'));
        physics.CalculateVelocityAfterWallCollision(lower_corner_particle, 'x');
        physics.CalculateVelocityAfterWallCollision(lower_corner_particle, 'y');
        REQUIRE(lower_corner_particle.GetVelocity().x == -1.0f);
        REQUIRE(lower_corner_particle.GetVelocity().y == -1.0f);
    }
}