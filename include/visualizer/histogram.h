#pragma once

#include "core/particle.h"

#include <cinder/Color.h>
#include <vector>

namespace idealgas {

namespace visualizer {

class Histogram {
private:
    std::vector<Particle> histogram_particles_;
    ci::Color histogram_color_;

    /** Coordinates for the histogram */
    glm::vec2 histogram_top_left_corner_;
    glm::vec2 histogram_bottom_right_corner_;
    size_t histogram_side_length_;

public:
    Histogram(ci::Color color, const glm::vec2 &top_left_corner, const glm::vec2 &bottom_right_corner);

    void GenerateHistogram(const std::vector<Particle> &particles);

    void Draw();
};

} // namespace visualizer

} // namespace idealgas