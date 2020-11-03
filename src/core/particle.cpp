//
// Created by Omar on 10/12/2020.
//
#include <core/particle.h>

#include <iostream>
#include <utility>

namespace idealgas {

    Particle::Particle(float radius, double mass, std::string color, glm::vec2 position, glm::vec2 velocity) {
        radius_ = radius;
        mass_ = mass;
        color_ = color;
        position_ = position;
        velocity_ = velocity;
    }
}  // namespace idealgas
