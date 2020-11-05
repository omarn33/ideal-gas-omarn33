#pragma once

#include <core/particle_physics.h>
#include <cinder/gl/gl.h>
#include <string>
#include <vector>

namespace idealgas {

    namespace visualizer {

        class IdealGasSimulator {

        private:
            /** Coordinates for container */
            glm::vec2 container_top_left_corner_;
            glm::vec2 container_bottom_right_corner_;

            /** Container attributes */
            const std::string container_color_ = "white";
            const float container_stroke_ = 10.0f;

            /** Default Particle */
            float particle_radius_;
            double particle_mass_;
            std::string particle_color_;
            glm::vec2 initial_position_;
            glm::vec2 initial_velocity_;

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
             * Clears all particles within the container
             */
            void ClearParticles();
        };


    } // namespace visualizer

} // namespace idealgas








/**
 * A sketchpad which will be displayed in the Cinder application and respond to
 * mouse events. Furthermore, the sketchpad can output its current state in the
 * same format as the Naive Bayes image data files.
 */
/*
class Sketchpad {
 public:
  /**
   * Creates a sketchpad.
   * (Note that sketchpad pixels are larger than screen pixels.)
   *
   * @param top_left_corner     the screen coordinates of the top left corner of
   *                            the sketchpad
   * @param num_pixels_per_side the number of sketchpad pixels in one row/column
   *                            of the sketchpad
   * @param sketchpad_size      the side length of the sketchpad, measured in
   *                            screen pixels
   * @param brush_radius        the maximum distance (measured in sketchpad
   *                            pixels) from the brush that will be shaded
   */

/*
  Sketchpad(const glm::vec2& top_left_corner, size_t num_pixels_per_side,
            double sketchpad_size, double brush_radius = 1.15);


  /**
   * Displays the current state of the sketchpad in the Cinder application.
   */
/*
  void Draw() const;

  /**
   * Shades in the sketchpad pixels whose centers are within brush_radius units
   * of the brush's location. (One unit is equal to the length of one sketchpad
   * pixel.)
   *
   * @param brush_screen_coords the screen coordinates at which the brush is
   *           located
   */
/*
  void HandleBrush(const glm::vec2& brush_screen_coords);

  /**
   * Set all of the sketchpad pixels to an unshaded state.
   */
/*
  void Clear();

 private:
  glm::vec2 top_left_corner_;

  size_t num_pixels_per_side_;

  /** Number of screen pixels in the width/height of one sketchpad pixel */
/*
  double pixel_side_length_;

  double brush_radius_;
};

}  // namespace visualizer

}  // namespace naivebayes
*/