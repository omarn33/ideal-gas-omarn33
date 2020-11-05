#include <core/particle.h>
#include <core/particle_physics.h>
#include <core/model_trainer.h>
#include <visualizer/ideal_gas_simulator.h>


#include <iostream>

using namespace idealgas;
using namespace visualizer;

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

  return 0;
}
