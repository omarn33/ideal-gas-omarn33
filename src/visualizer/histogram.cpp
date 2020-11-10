#include <cinder/gl/gl.h>
#include "visualizer/histogram.h"

namespace idealgas {

namespace visualizer {

    Histogram::Histogram(ci::Color color, const glm::vec2 &top_left_corner, const glm::vec2 &bottom_right_corner) {
        histogram_color_ = color;
        histogram_top_left_corner_ = top_left_corner;
        histogram_bottom_right_corner_ = bottom_right_corner;
        histogram_side_length_ = histogram_bottom_right_corner_.x - histogram_top_left_corner_.x;
    }

    void Histogram::GenerateHistogram(const std::vector<Particle> &particles) {
        histogram_particles_ = particles;

        // Store the speed for each particle
        for(size_t particle = 0; particle < histogram_particles_.size(); ++particle) {
            particle_speeds_.at(particle) = histogram_particles_.at(particle).GetSpeed();
        }

        // Determine the bin size for the histogram
        if(particle_speeds_.size() > 1) {
            double highest_speed = *max_element(particle_speeds_.begin(), particle_speeds_.end());
            double lowest_speed = *min_element(particle_speeds_.begin(), particle_speeds_.end());

            partition_size_ = (highest_speed - lowest_speed) / (partition_size_);
        }
        else {
            partition_size_ = 10;
        }

        // Determine the bin height
        CountParticlesInEachPartition();
    }

    void Histogram::CountParticlesInEachPartition() {
        // Store the various bin size values
        for(size_t partition = 0; partition < histogram_particles_.size() + 1; ++partition) {
            partition_values.push_back(partition * partition_size_);
        }

        // Determine the number of particles that fall within the calculated speed ranges
        for(size_t range = 0; range < partition_values.size() - 1; ++range) {
            num_of_particles_per_partition_.push_back(CountParticlesInPartition(partition_values.at(range),
                                                                                partition_values.at(range + 1)));
        }
    }

    size_t Histogram::CountParticlesInPartition(double lower, double upper)
    {
        // Count the number of particles in a given range
        size_t counter = 0;
        for(size_t particle = 0; particle < particle_speeds_.size(); ++particle) {
            if(particle_speeds_.at(particle) >= lower && particle_speeds_.at(particle) < upper) {
                ++counter;
            }
        }

        return counter;
    }

    void Histogram::Draw() {
        // Draw Rectangle
        ci::gl::color(kHistogramBorderColor);
        ci::gl::drawStrokedRect(ci::Rectf(histogram_top_left_corner_,
                                          histogram_bottom_right_corner_), kHistogramStroke);

        // Calculate
        //float width = partition_size_ * (histogram_side_length_ / num_of_particles_per_partition_.size());
        //float height = num_of_particles_per_partition_.at(0) * (histogram_side_length_ / histogram_particles_.size());
    }

} // namespace visualizer

} // namespace idealgas
