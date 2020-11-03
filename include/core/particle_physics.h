#pragma once

#include <core/particle.h>
#include <map>
#include <vector>

namespace idealgas {

class ParticlePhysics {
private:
    std::vector<Particle> particles_;
    size_t number_of_particles_;
    const std::vector<char> kDirections = {'x', 'y'};
    glm::vec2 container_top_left_corner_;
    glm::vec2 container_bottom_right_corner_;


public:
    ParticlePhysics(std::vector<Particle> particles, glm::vec2 top_left_corner, glm::vec2 bottom_right_corner);

    void UpdateVelocityAfterWallCollision(Particle particle, char direction);
    bool HasCollidedWithWall(Particle particle, char direction);
};

}  // namespace idealgas
