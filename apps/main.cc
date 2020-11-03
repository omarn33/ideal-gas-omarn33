#include <core/particle.h>
#include <core/particle_physics.h>
#include <core/model_trainer.h>


#include <iostream>

using namespace idealgas;

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main(int argc, char* argv[]) {

    glm::vec2 top_left(0.0, 0.0);
    glm::vec2 bottom_right(100.0, 100.0);

    glm::vec2 position1(30.0, 10.0);
    glm::vec2 velocity1(1.0, -1.0);

    glm::vec2 position2(110.0, 110.0);
    glm::vec2 velocity2(-2.0, -2.0);

    Particle particle1(10.0f, 10.0, "white", position1, velocity1);
    Particle particle2(10.0f, 10.0, "white", position2, velocity2);

    std::vector<Particle> particles = {particle1, particle2};


    ParticlePhysics physics(particles, top_left, bottom_right);
    std::cout << "Particle Collided in X: " << physics.HasParticleCollidedWithWall(particle1, 'x') << std::endl;
    if(physics.HasParticleCollidedWithWall(particle1, 'x'))
    {
        std::cout << "x-collision true" << std::endl;
        physics.CalculateVelocityAfterWallCollision(particle1, 'x');
    }

    std::cout << "Particle Collided in Y: " << physics.HasParticleCollidedWithWall(particle1, 'y') << std::endl;
    if(physics.HasParticleCollidedWithWall(particle1, 'y'))
    {
        std::cout << "y-collision true" << std::endl;
        physics.CalculateVelocityAfterWallCollision(particle1, 'y');
    }


    physics.CalculatePositionAfterCollision(particle1);


    std::cout << "Particle Update x-coordinate: " << particle1.GetPosition().x << std::endl;
    std::cout << "Particle Update y-coordinate: " << particle1.GetPosition().y << std::endl;

  return 0;
}
