#include <visualizer/ideal_gas_app.h>
#include <iostream>

namespace idealgas {

    namespace visualizer {

        IdealGasApp::IdealGasApp() : simulator_(IdealGasSimulator(glm::vec2(kMargin, kMargin),
                                                                  glm::vec2(kWindowSize - kMargin,
                                                                            kWindowSize - kMargin)))
                                                                            {
            ci::app::setWindowSize((int) kWindowSize + 1000, (int) kWindowSize);
        }

        void IdealGasApp::draw() {
            // Draw background
            ci::Color8u background_color(0, 0, 0);

            // Clear the background color
            ci::gl::clear(background_color);

            // Display instructions
            ci::gl::drawStringCentered(
                    "Press [Space] to add a particle. Press [Delete] to remove all particles.",
                    glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("white"), ci::Font("Arial", 60.0f));

            // Display Ideal Gas Simulator
            simulator_.Draw();
        }

        void IdealGasApp::update() {
            // Update Ideal Gas Simulator
            simulator_.Update();
        }

        void IdealGasApp::keyDown(ci::app::KeyEvent event) {
            switch (event.getCode()) {
                case ci::app::KeyEvent::KEY_SPACE:
                    // Create a particle at center
                    simulator_.AddParticle();

                    break;

                case ci::app::KeyEvent::KEY_DELETE:
                    // Delete all particles
                    simulator_.ClearParticles();
                    break;
            }
        }
    }
}