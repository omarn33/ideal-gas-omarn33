#pragma once

#include "core/particle.h"

#include <cinder/Color.h>
#include <vector>
#include <algorithm>

namespace idealgas {

namespace visualizer {

class Histogram {
private:
    std::vector<Particle> histogram_particles_;
    std::vector<double> particle_speeds_;
    ci::Color histogram_color_;

    /** Coordinates for the histogram */
    glm::vec2 histogram_top_left_corner_;
    glm::vec2 histogram_bottom_right_corner_;

    /** Histogram Drawing Data */
    double histogram_side_length_;
    std::vector<double> partition_values;
    std::vector<size_t> num_of_particles_per_partition_;
    double partition_size_;


public:
    Histogram(ci::Color color, const glm::vec2 &top_left_corner, const glm::vec2 &bottom_right_corner);

    void GenerateHistogram(const std::vector<Particle> &particles);

    void CountParticlesInEachPartition();

    size_t CountParticlesInPartition(double lower, double upper);

    void Draw();
};

} // namespace visualizer

} // namespace idealgas