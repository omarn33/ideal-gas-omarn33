#include <visualizer/ideal_gas_app.h>
#include <iostream>

namespace idealgas {

    namespace visualizer {

        IdealGasApp::IdealGasApp() : simulator_(IdealGasSimulator(glm::vec2(kWindowWidth * (1 / 3.0), kMargin),
                                                                  glm::vec2(kWindowWidth - kMargin,
                                                                            kWindowHeight - kMargin))),
                                     red_histogram_(ci::Color("red"), glm::vec2{ kHistogramMargin, kHistogramMargin}, glm::vec2{kHistogramMargin + kHistogramSideLength, kHistogramMargin + kHistogramSideLength}),
                                     blue_histogram_(ci::Color("blue"), glm::vec2{kHistogramMargin, 2 * kHistogramMargin + kHistogramSideLength}, glm::vec2{kHistogramMargin + kHistogramSideLength, 2 * kHistogramMargin + 2 * kHistogramSideLength}),
                                     green_histogram_(ci::Color("green"), glm::vec2{kHistogramMargin, 3 * kHistogramMargin + 2 * kHistogramSideLength}, glm::vec2{kHistogramMargin + kHistogramSideLength, 3 * kHistogramMargin + 3 * kHistogramSideLength})

                                     {
            ci::app::setWindowSize((int) kWindowWidth, (int) kWindowHeight);
        }

        void IdealGasApp::draw() {
            // Draw background
            ci::Color8u background_color(0, 0, 0);

            // Clear the background color
            ci::gl::clear(background_color);

            // Display instructions
            ci::gl::drawStringCentered(
                    "Press [Space] to add a particle. Press [Delete] to remove all particles.",
                    glm::vec2(kWindowWidth / 2, kMargin / 2), ci::Color("white"), ci::Font("Arial", 60.0f));

            // Display Ideal Gas Simulator
            simulator_.Draw();

            // Draw Histograms
            red_histogram_.Draw();
            blue_histogram_.Draw();
            green_histogram_.Draw();
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