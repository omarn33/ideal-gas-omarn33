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

        // Calculate histogram data for particles
        if(histogram_particles_.size() > 0) {

            // Store the speed for each particle
            for (size_t particle = 0; particle < histogram_particles_.size(); ++particle) {
                particle_speeds_.push_back(histogram_particles_.at(particle).GetSpeed());
            }

            double highest_speed;
            double lowest_speed;

            // Determine the bin size for the histogram
            if (particle_speeds_.size() > 1) {
                highest_speed = *max_element(particle_speeds_.begin(), particle_speeds_.end());
                lowest_speed = *min_element(particle_speeds_.begin(), particle_speeds_.end());

                // Determine the bin width
                partition_size_ = (highest_speed - lowest_speed) / (histogram_particles_.size());

                // Determine the number of partitions
                num_of_partitions_ = ceil((highest_speed) / (partition_size_));

            } else {
                partition_size_ = 10.0;
                num_of_partitions_ = 1;
            }

            // Determine the bin height
            CountParticlesInEachPartition();
        }
    }

    void Histogram::CountParticlesInEachPartition() {
        // Store the various bin size values
        for(size_t partition = 0; partition < num_of_partitions_; ++partition) {
            partition_values.push_back(partition * partition_size_);
        }

        // Determine the number of particles that fall within the calculated speed ranges
        for(size_t range = 0; range < partition_values.size() - 1; ++range) {
            num_of_particles_per_partition_.push_back(CountParticlesInPartition(
                    partition_values.at(range),partition_values.at(range + 1)));
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
        // Draw Histogram outline
        ci::gl::color(kHistogramBorderColor);
        ci::gl::drawStrokedRect(ci::Rectf(histogram_top_left_corner_,
                                          histogram_bottom_right_corner_), kHistogramStroke);

        if(histogram_particles_.size() > 1) {

            float width = (histogram_side_length_ / num_of_particles_per_partition_.size());
            float height;

            float histogram_bottom_left_x = (float) histogram_top_left_corner_.x;
            float histogram_bottom_left_y = (float) (histogram_top_left_corner_.y + histogram_side_length_);

            float bar_top_left_x;
            float bar_top_left_y;

            float bar_bottom_right_x;
            float bar_bottom_right_y;

            for(size_t bin = 0; bin < num_of_particles_per_partition_.size(); ++bin) {
                height = num_of_particles_per_partition_.at(bin) *
                        (histogram_side_length_ / histogram_particles_.size());

                bar_top_left_x = histogram_bottom_left_x + (bin * width);
                bar_top_left_y = histogram_bottom_left_y - height;

                bar_bottom_right_x = histogram_bottom_left_x + ((bin + 1) * width);
                bar_bottom_right_y = histogram_bottom_left_y;

                ci::gl::color(histogram_color_);
                ci::gl::drawSolidRect(ci::Rectf(
                        glm::vec2{bar_top_left_x, bar_top_left_y},
                        glm::vec2{bar_bottom_right_x, bar_bottom_right_y}));
            }
        }
        else if(histogram_particles_.size() == 1) {
            float width = (histogram_side_length_ / partition_size_);

            float bar_top_left_x;
            float bar_top_left_y;

            float bar_bottom_right_x;
            float bar_bottom_right_y;

            float histogram_bottom_left_x = (float) histogram_top_left_corner_.x;
            float histogram_bottom_left_y = (float) (histogram_top_left_corner_.y + histogram_side_length_);

            bar_top_left_x = histogram_bottom_left_x;
            bar_top_left_y = histogram_top_left_corner_.y;

            bar_bottom_right_x = histogram_bottom_left_x + width;
            bar_bottom_right_y = histogram_bottom_left_y;

            ci::gl::color(histogram_color_);
            ci::gl::drawSolidRect(ci::Rectf(
                    glm::vec2{bar_top_left_x, bar_top_left_y},
                    glm::vec2{bar_bottom_right_x, bar_bottom_right_y}));
        }

        // Clear all vectors
        partition_values.clear();
        num_of_particles_per_partition_.clear();
        particle_speeds_.clear();
        histogram_particles_.clear();
    }

    double Histogram::GetPartitionSize() {
        return partition_size_;
    }

    std::vector<size_t> Histogram::GetNumberOfParticlesPerPartition() {
        return num_of_particles_per_partition_;
    }

} // namespace visualizer

} // namespace idealgas
