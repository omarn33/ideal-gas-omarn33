#pragma once

#include <visualizer/ideal_gas_simulator.h>
#include <core/particle.h>
#include <map>
#include <vector>

namespace idealgas {

class ParticlePhysics {
private:
    std::vector<Particle> particles_;
    size_t number_of_particles_;
    std::vector<char> kDimensions = {'x', 'y'};
    glm::vec2 container_top_left_corner_;
    glm::vec2 container_bottom_right_corner_;

    friend visualizer::IdealGasSimulator;

public:
    ParticlePhysics() = default;

    /**
     * Constructor that takes in takes in particles and initializes container boundaries
     * @param particles The various particles in the container
     * @param top_left_corner vec2 representing the coordinate of the top left corner of the container
     * @param bottom_right_corner vec2 representing the coordinate of the bottom right corner of the container
     */
    ParticlePhysics(std::vector<Particle> particles, glm::vec2 top_left_corner, glm::vec2 bottom_right_corner);

    /**
     * Calculates the position of the particle after any collision (with wall or other particle)
     * @param particle The Particle that collided
     */
    void CalculatePositionAfterCollision(Particle& particle);

    /**
     * Calculates the velocity of the particle after a wall collision for a given axis
     * @param particle The particle that collided
     * @param direction char representing the axis in which the collision occurred (x or y)
     */
    void CalculateVelocityAfterWallCollision(Particle& particle, char direction);

    /**
     * Determines if a particle collided with the container wall for a given axis
     * @param particle The particle that collided
     * @param direction char representing the axis in which the collision may have occurred (x or y)
     * @return true if the particle collided with the wall, false otherwise
     */
    bool HasParticleCollidedWithWall(Particle particle, char direction);

    /** Getter Methods */
    std::vector<Particle> GetParticlesVector();

    /** Setter Methods */
    void SetParticlesVector(std::vector<Particle>& particles);

};

}  // namespace idealgas
