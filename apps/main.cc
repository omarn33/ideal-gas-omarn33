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
    glm::vec2 velocity1(2.0, 2.0);

    glm::vec2 position2(110.0, 110.0);
    glm::vec2 velocity2(-2.0, -2.0);

    Particle particle1(10.0f, 10.0, "white", position1, velocity1);
    Particle particle2(10.0f, 10.0, "white", position2, velocity2);

    std::vector<Particle> particles = {particle1, particle2};

    ParticlePhysics physics(particles, top_left, bottom_right);

    cout << "Particle1 collide with wall in x: " << physics.HasCollidedWithWall(particle1, 'x') << endl;
    cout << "Particle1 collide with wall in y: " << physics.HasCollidedWithWall(particle1, 'y') << endl;

    cout << endl;
    cout << "Particle2 collide with wall in x: " << physics.HasCollidedWithWall(particle2, 'x') << endl;
    cout << "Particle2 collide with wall in y: " << physics.HasCollidedWithWall(particle2, 'y') << endl;

  return 0;
}
