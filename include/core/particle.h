#pragma once

#include "../../../../include/glm/glm.hpp"
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

public:
    //Particle() = default;

    Particle(float radius, double mass, std::string color, glm::vec2 position, glm::vec2 velocity);

    /** Getter Methods */
    float GetRadius();

    double GetMass();

    std::string GetColor();

    glm::vec2 GetPosition();

    glm::vec2 GetVelocity();

    /** Setter Methods */
    void SetRadius(float radius);

    void SetMass(double mass);

    void SetColor(std::string color);

    void SetPosition(glm::vec2 position);

    void SetVelocity(glm::vec2 velocity);

};
}  // namespace idealgas
