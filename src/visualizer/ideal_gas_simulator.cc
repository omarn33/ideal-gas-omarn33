#include <visualizer/ideal_gas_simulator.h>

namespace idealgas {

namespace visualizer {

    IdealGasSimulator::IdealGasSimulator(const glm::vec2 &top_left_corner, const glm::vec2 &bottom_right_corner,
                                         std::vector<Particle>& particles) {
        container_bottom_right_corner_ = top_left_corner;
        container_bottom_right_corner_ = bottom_right_corner;

        physics_ = ParticlePhysics(particles, top_left_corner, bottom_right_corner);
        num_of_particles_ = particles.size();
    }

    void IdealGasSimulator::Draw() {
        // Draw the container
        ci::gl::color(ci::Color("white")); // C++ wasn't allowing me to use container_color_ for some reason
        ci::Rectf pixel_bounding_box(container_top_left_corner_, container_bottom_right_corner_);
        ci::gl::drawSolidRect(pixel_bounding_box);

        // Draw particles
        for(size_t particle = 0; particle < num_of_particles_; ++particle)
        {
            ci::gl::color(ci::Color("gray")); // C++ wasn't allowing me to use particle.GetColor() for some reason
            ci::gl::drawSolidCircle(physics_.GetParticlesVector().at(particle).GetPosition(), physics_.GetParticlesVector().at(particle).GetRadius());
        }
    }

    void IdealGasSimulator::Update() {
        // Determine if a particle collided with the container
        for (size_t particle = 0; particle < num_of_particles_; ++particle) {
            // Determine if a particle collided with the container in a corner
            if (physics_.HasParticleCollidedWithWall(physics_.GetParticlesVector().at(particle), 'x') &&
                physics_.HasParticleCollidedWithWall(physics_.GetParticlesVector().at(particle), 'y')) {
                physics_.CalculateVelocityAfterWallCollision(physics_.GetParticlesVector().at(particle), 'x');
                physics_.CalculateVelocityAfterWallCollision(physics_.GetParticlesVector().at(particle), 'y');
            }
                // Determine if the a particle collided with the left/right container boundary
            else if (physics_.HasParticleCollidedWithWall(physics_.GetParticlesVector().at(particle), 'x')) {
                physics_.CalculateVelocityAfterWallCollision(physics_.GetParticlesVector().at(particle), 'x');
            }
                // Determine if the a particle collided with the left/right container boundary
            else if (physics_.HasParticleCollidedWithWall(physics_.GetParticlesVector().at(particle), 'y')) {
                physics_.CalculateVelocityAfterWallCollision(physics_.GetParticlesVector().at(particle), 'y');
            }

            // Update particle position
            physics_.CalculatePositionAfterCollision(physics_.GetParticlesVector().at(particle));
        }
    }

    void IdealGasSimulator::AddParticle(Particle particle)
    {
        physics_.GetParticlesVector().push_back(particle);
        ++num_of_particles_;
    }

    void IdealGasSimulator::ClearParticles() {
        physics_.GetParticlesVector().clear();
        num_of_particles_ = 0;
    }
} // namespace visualizer

} // namespace idealgas

    /*
using glm::vec2;

Sketchpad::Sketchpad(const vec2& top_left_corner, size_t num_pixels_per_side,
                     double sketchpad_size, double brush_radius)
    : top_left_corner_(top_left_corner),
      num_pixels_per_side_(num_pixels_per_side),
      pixel_side_length_(sketchpad_size / num_pixels_per_side),
      brush_radius_(brush_radius) {}

void Sketchpad::Draw() const {
  for (size_t row = 0; row < num_pixels_per_side_; ++row) {
    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
      // Currently, this will draw a quarter circle centered at the top-left
      // corner with a radius of 20

      // TODO: Replace the if-statement below with an if-statement that checks
      // if the pixel at (row, col) is currently shaded

      if (row * row + col * col <= 20 * 20) {
        ci::gl::color(ci::Color::gray(0.3f));
      } else {
        ci::gl::color(ci::Color("white"));
      }

      vec2 pixel_top_left = top_left_corner_ + vec2(col * pixel_side_length_,
                                                    row * pixel_side_length_);

      vec2 pixel_bottom_right =
          pixel_top_left + vec2(pixel_side_length_, pixel_side_length_);

      ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);

      ci::gl::drawSolidRect(pixel_bounding_box);

      ci::gl::color(ci::Color("black"));
      ci::gl::drawStrokedRect(pixel_bounding_box);
    }
  }
}



void Sketchpad::HandleBrush(const vec2& brush_screen_coords) {
  vec2 brush_sketchpad_coords =
      (brush_screen_coords - top_left_corner_) / (float)pixel_side_length_;

  for (size_t row = 0; row < num_pixels_per_side_; ++row) {
    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
      vec2 pixel_center = {col + 0.5, row + 0.5};

      if (glm::distance(brush_sketchpad_coords, pixel_center) <=
          brush_radius_) {
        // TODO: Add code to shade in the pixel at (row, col)

      }
    }
  }
}

void Sketchpad::Clear() {
  // TODO: implement this method
}
}  // namespace visualizer

}  // namespace naivebayes
*/