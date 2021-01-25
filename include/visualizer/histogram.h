#pragma once

#include "core/particle.h"

#include <cinder/Color.h>
#include <vector>
#include <algorithm>
#include <math.h>

namespace idealgas {

namespace visualizer {

class Histogram {
private:
    /** Particle Data */
    std::vector<Particle> histogram_particles_;
    std::vector<double> particle_speeds_;

    /** Histogram Drawing Data */
    glm::vec2 histogram_top_left_corner_;
    glm::vec2 histogram_bottom_right_corner_;
    double histogram_side_length_;
    ci::Color histogram_color_;
    const ci::Color kHistogramBorderColor = ci::Color("white");
    const float kHistogramStroke = 10.0f;

    /** Bin Width Data */
    double partition_size_;
    std::vector<double> partition_values;
    std::vector<size_t> num_of_particles_per_partition_;
    size_t num_of_partitions_;

public:
    /**
     * Constructor that initialize histogram boundaries
     * @param color The color of the particles stored in the histogram
     * @param top_left_corner vec2 representing the coordinate of the top left corner of the histogram
     * @param bottom_right_corner vec2 representing the coordinate of the bottom right corner of the histogram
     */
    Histogram(ci::Color color, const glm::vec2 &top_left_corner, const glm::vec2 &bottom_right_corner);

    /**
     * Calculate data involved with histogram generation
     * @param particles The particles which data will be represented
     */
    void GenerateHistogram(const std::vector<Particle> &particles);

    /**
     * Counts the number of particles in each partition (bucket)
     */
    void CountParticlesInEachPartition();

    /**
     * Counts the number of particles with a given speed within a certain partition (bucket)
     * @param lower double representing the lower boundary (inclusive) of the bucket
     * @param upper double representing the upper boundary (exclusive) of the bucket
     * @return size_t representing the number of particles with a given speed within a partition
     */
    size_t CountParticlesInPartition(double lower, double upper);

    /**
     * Draws the histogram on the cinder app window
     */
    void Draw();

    /** Getter Methods */
    double GetPartitionSize();

    std::vector<size_t> GetNumberOfParticlesPerPartition();
};

} // namespace visualizer

} // namespace idealgas