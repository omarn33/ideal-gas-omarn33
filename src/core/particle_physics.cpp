#include <core/particle_physics.h>

#include <vector>
#include <iostream>

namespace idealgas {

    ParticlePhysics::ParticlePhysics(std::vector<Particle> particles, glm::vec2 top_left_corner,
                                     glm::vec2 bottom_right_corner) {
        particles_ = particles;
        number_of_particles_ = particles.size();
        container_top_left_corner_ = top_left_corner;
        container_bottom_right_corner_ = bottom_right_corner;
    }

    void ParticlePhysics::CalculatePositionAfterCollision(Particle& particle)
    {
        particle.SetPosition(particle.GetPosition() + particle.GetVelocity());
    }

    void ParticlePhysics::CalculateVelocityAfterWallCollision(Particle& particle, char direction) {
        direction = tolower(direction);
        size_t collision_axis = -1;

        // Determine appropriate axis based on parameter
        for (size_t axis = 0; axis < kDimensions.size(); ++axis) {
            if (kDimensions.at(axis) == direction) {
                collision_axis = axis;
            }
        }

        float x_velocity = particle.GetVelocity().x;
        float y_velocity = particle.GetVelocity().y;

        // Reflect particle velocity in the x-direction
        if (collision_axis == 0) {
            std::cout << "Updated x-velocity" << std::endl;
            x_velocity *= -1;
        }

        // Reflect particle velocity in the y-direction
        if (collision_axis == 1) {
            std::cout << "Updated y-velocity" << std::endl;
            y_velocity *= -1;
        }

        // Update particle velocity
        std::cout << "x-velocity: " << x_velocity << std::endl;
        std::cout << "y-velocity: " << y_velocity << std::endl;
        particle.SetVelocity(glm::vec2{x_velocity, y_velocity});
    }

    bool ParticlePhysics::HasParticleCollidedWithWall(Particle particle, char direction) {
        direction = tolower(direction);
        size_t collision_axis = -1;

        // Determine appropriate axis based on parameter
        for (size_t axis = 0; axis < kDimensions.size(); ++axis) {
            if (kDimensions.at(axis) == direction) {
                collision_axis = axis;
            }
        }

        // Verify an appropriate axis was entered
        if (collision_axis == -1) {
            return false;
        }

        // Obtain the particle's x and y velocities
        float x_velocity = particle.GetVelocity().x;
        float y_velocity = particle.GetVelocity().y;

        // Determine if the particle collided with the top/bottom wall of the container
        if (collision_axis == 1) {
            if ((particle.GetPosition().y - particle.GetRadius() <= container_top_left_corner_.y) && (y_velocity < 0)) {
                return true;
            } else if ((particle.GetPosition().y + particle.GetRadius() >= container_bottom_right_corner_.y) && (y_velocity > 0)) {
                return true;
            } else {
                return false;
            }
        }

        // Determine if the particle collided with the left/right wall of the container
        if (collision_axis == 0) {
            if ((particle.GetPosition().x - particle.GetRadius() <= container_top_left_corner_.x) && (x_velocity < 0)) {
                return true;
            } else if ((particle.GetPosition().x + particle.GetRadius() >= container_bottom_right_corner_.x) && (x_velocity > 0)) {
                return true;
            } else {
                return false;
            }
        }

        return false;
    }
}  // namespace idealgas
