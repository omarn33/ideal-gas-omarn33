#pragma once

#include <glm/glm.hpp>

#include <iostream>
#include <string>

namespace idealgas {

    class Particle {
    private:
        float radius_;
        double mass_;
        std::string color_;
        glm::vec2 position_;
        glm::vec2 velocity_;

        Particle(float radius, double mass, std::string color, glm::vec2 position, glm::vec2 velocity);
    };
}  // namespace idealgas
