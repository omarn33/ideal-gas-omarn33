#include "visualizer/histogram.h"

namespace idealgas {

namespace visualizer {

    Histogram::Histogram(ci::Color color, const glm::vec2 &top_left_corner, const glm::vec2 &bottom_right_corner) {
        histogram_color_ = color;
        histogram_top_left_corner_ = top_left_corner;
        histogram_bottom_right_corner_ = bottom_right_corner;
    }

    void Histogram::GenerateHistogram(const std::vector<Particle> &particles) {


    }

    void Histogram::Draw() {


    }

} // namespace visualizer

} // namespace idealgas
