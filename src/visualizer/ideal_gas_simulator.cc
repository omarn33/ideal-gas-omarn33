#include <visualizer/ideal_gas_simulator.h>
#include <iostream>
#include <cinder/gl/gl.h>

namespace idealgas {

    namespace visualizer {

        IdealGasSimulator::IdealGasSimulator(glm::vec2 top_left_corner, glm::vec2 bottom_right_corner) : physics_(
                ParticlePhysics(top_left_corner, bottom_right_corner)) {

            container_top_left_corner_ = top_left_corner;
            container_bottom_right_corner_ = bottom_right_corner;

            // Set default particle values
            particle_radius_ = 30.0f;
            particle_mass_ = 1.0;
            particle_color_ = ci::Color("gray");
            initial_position_ = {(bottom_right_corner.x - top_left_corner.x) / 2,
                                 (bottom_right_corner.y - top_left_corner.y) / 2};
            initial_velocity_ = {10.0, 9.0};
        }

        void IdealGasSimulator::Draw() {
            // Draw the container
            ci::gl::color(ci::Color("white"));
            ci::gl::drawStrokedRect(ci::Rectf(container_top_left_corner_,
                                              container_bottom_right_corner_), container_stroke_);

            // Draw particles
            for (size_t particle = 0; particle < particles_.size(); ++particle) {
                ci::gl::color(particles_.at(particle).GetColor());
                ci::gl::drawSolidCircle(particles_.at(particle).GetPosition(),
                                        particles_.at(particle).GetRadius());
            }
        }

        void IdealGasSimulator::Update() {

            // Determine if a particle collided with the container
            for (size_t particle = 0; particle < particles_.size(); ++particle) {
                // Determine if a particle collided with the container in a corner
                if (physics_.HasParticleCollidedWithWall(particles_.at(particle), 'x') &&
                    physics_.HasParticleCollidedWithWall(particles_.at(particle), 'y')) {

                    physics_.CalculateVelocityAfterWallCollision(particles_.at(particle), 'x');
                    physics_.CalculateVelocityAfterWallCollision(particles_.at(particle), 'y');
                }
                    // Determine if a particle collided with the left/right container boundary
                else if (physics_.HasParticleCollidedWithWall(particles_.at(particle), 'x')) {
                    physics_.CalculateVelocityAfterWallCollision(particles_.at(particle), 'x');
                }
                    // Determine if a particle collided with the left/right container boundary
                else if (physics_.HasParticleCollidedWithWall(particles_.at(particle), 'y')) {
                    physics_.CalculateVelocityAfterWallCollision(particles_.at(particle), 'y');
                }

                // Update particle position
                physics_.CalculatePositionAfterCollision(particles_.at(particle));
            }

            // Determine if a particle collided with another particle
            for (size_t particle1 = 0; particle1 < particles_.size(); ++particle1) {
                for (size_t particle2 = particle1 + 1; particle2 < particles_.size(); ++particle2) {
                    if (physics_.HasParticleCollidedWithParticle(particles_.at(particle1), particles_.at(particle2))) {
                        std::cout << "---------COLLISION---------" << std::endl;
                        physics_.CalculateVelocityAfterParticleCollision(particles_.at(particle1),
                                                                         particles_.at(particle2));

                        // Update particle positions
                        physics_.CalculatePositionAfterCollision(particles_.at(particle1));
                        physics_.CalculatePositionAfterCollision(particles_.at(particle2));
                    }
                }
            }
        }

        void IdealGasSimulator::AddParticle() {
            // Create new particle
            //Particle particle(particle_radius_, particle_mass_, particle_color_, initial_position_, initial_velocity_);
            //particles_.push_back(particle);
            particles_.push_back(GenerateRandomParticle());
        }

        Particle IdealGasSimulator::GenerateRandomParticle()
        {
            // Generate a random radius
            int radius; //= GenerateRandomNumber(20, 50);
            int x_velocity;
            int y_velocity;

            int randomNumber = GenerateRandomNumber(1, 3);
            if(randomNumber == 1)
            {
                radius = 20;
                particle_color_ = ci::Color("red");

                x_velocity = 20;
                y_velocity = 20;
            }
            else if (randomNumber == 2)
            {
                radius = 40;
                particle_color_ = ci::Color("blue");

                x_velocity = 10;
                y_velocity = 10;
            }
            else
            {
                radius = 80;
                particle_color_ = ci::Color("green");

                x_velocity = 5;
                y_velocity = 5;
            }

            // Generate a random position
            int x_coordinate = GenerateRandomNumber(container_top_left_corner_.x, container_bottom_right_corner_.x);
            int y_coordinate = GenerateRandomNumber(container_top_left_corner_.y, container_bottom_right_corner_.y);

            // Generate a random velocity
            //int x_velocity = 5;//GenerateRandomNumber(-20, 20);
            //int y_velocity = 5;//GenerateRandomNumber(-20, 20);

            // Create Particle
            Particle particle(float(radius), particle_mass_, particle_color_, glm::vec2 {x_coordinate, y_coordinate}, glm::vec2 {x_velocity, y_velocity});
            return particle;
        }

        int IdealGasSimulator::GenerateRandomNumber(int lower, int upper)
        {
            int random_number_ = ((rand() % (upper - lower + 1)) + lower);
            std::cout << "Random Number: " << random_number_ << std::endl;
            return random_number_;
        }

        void IdealGasSimulator::ClearParticles() {
            particles_.clear();
        }
    } // namespace visualizer

} // namespace idealgas
