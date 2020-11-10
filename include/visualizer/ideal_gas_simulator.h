#pragma once

#include <core/particle_physics.h>
//#include <cinder/gl/gl.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cinder/Color.h>

namespace idealgas {

    namespace visualizer {

        class IdealGasSimulator {

        private:
            /** Coordinates for container */
            glm::vec2 container_top_left_corner_;
            glm::vec2 container_bottom_right_corner_;

            /** Container attributes */
            const std::string container_color_ = "white";
            const float container_stroke_ = 20.0f;

            /** Default Particle */
            float particle_radius_;
            double particle_mass_;
            ci::Color particle_color_;
            glm::vec2 initial_position_;
            glm::vec2 initial_velocity_;

            /** Red Particle Atrributes */
            const float red_particle_radius_ = 10.0f;
            const double red_particle_mass_ = 10.0;
            const ci::Color red_particle_color_ = ci::Color("red");

            /** Blue Particle Atrributes */
            const float blue_particle_radius_ = 10.0f;
            const double blue_particle_mass_ = 10.0;
            const ci::Color blue_particle_color_ = ci::Color("blue");

            /** Green Particle Attributes */
            const float green_particle_radius_ = 10.0f;
            const double green_particle_mass_ = 10.0;
            const ci::Color green_particle_color_ = ci::Color("green");

            /** Particle Physics */
            std::vector<Particle> particles_;
            ParticlePhysics physics_;


        public:
            /**
             * Constructor that takes in boundaries of container
             * @param top_left_corner vec2 coordinate of the top left corner of the container
             * @param bottom_right_corner vec2 coordinate of the bottom right corner of the container
             */
            IdealGasSimulator(glm::vec2 top_left_corner, glm::vec2 bottom_right_corner);

            /**
             * Displays the current state of the ideal gas simulator in the cinder application
             */
            void Draw();

            /**
             * Updates the state of the particles within the ideal gas simulator
             */
            void Update();

            /**
             * Adds particle to the container
             * @param particle The particle to be added
             */
            void AddParticle();

            /**
             * Generates a random particle
             * @return Particle the randomly generated particle
             */
            Particle GenerateRandomParticle();

            /**
             * Generates a random integer between an upper and lower bound inclusive
             * @param lower int representing the lower bound
             * @param upper int representing the upper bound
             * @return int representing the random number
             */
            int GenerateRandomNumber(int lower, int upper);

            /**
             * Clears all particles within the container
             */
            void ClearParticles();
        };

    } // namespace visualizer

} // namespace idealgas