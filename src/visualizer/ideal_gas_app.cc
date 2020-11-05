#include <visualizer/ideal_gas_app.h>
#include <iostream>

namespace idealgas {

    namespace visualizer {

        IdealGasApp::IdealGasApp() : simulator_(IdealGasSimulator(glm::vec2(kMargin, kMargin),
                                                                  glm::vec2(kWindowSize - kMargin,
                                                                            kWindowSize - kMargin)))
                                                                            {
            ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
        }

        void IdealGasApp::draw() {
            // Draw background
            ci::Color8u background_color(0, 0, 0);

            // Clear the background color
            ci::gl::clear(background_color);

            // Display instructions
            ci::gl::drawStringCentered(
                    "Press 'Space' to add a particle. Press 'Delete' to remove a particle.",
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


/*

IdealGasApp::IdealGasApp()
: sketchpad_(glm::vec2(kMargin, kMargin), kImageDimension,
             kWindowSize - 2 * kMargin) {
ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);

x = 1500;
}

void IdealGasApp::draw() {
//ci::Color8u background_color(255, 246, 148);  // light yellow

// Draw a black background
ci::Color8u background_color(0, 0, 0);

// Clear the background color
ci::gl::clear(background_color);

//sketchpad_.Draw();

// Write Text
ci::gl::drawStringCentered(
  "Click to add a particle. Press Enter to make a prediction.",
  glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("white"), ci::Font("Arial", 48.0f));


// Draw a circle
ci::gl::color(ci::Color("gray"));
ci::gl::drawSolidCircle(glm::vec2 {x, x}, 15.0f);
x -= 1;

// Draw a rectangle
ci::gl::color(ci::Color("white"));
ci::gl::drawStrokedRect( ci::Rectf( getWindowWidth()/2 - 500.0f,
                            getWindowHeight()/2 - 500.0f,
                            getWindowWidth()/2 + 500.0f,
                            getWindowHeight()/2 + 500.0f), 10.0f);

/*
glm::vec2 pixel_top_left = glm::vec2(kMargin, kMargin) + vec2(col * pixel_side_length_,
                                              row * pixel_side_length_);

glm::vec2 pixel_bottom_right =
        pixel_top_left + vec2(pixel_side_length_, pixel_side_length_);


ci::Rectf pixel_bounding_box();
ci::gl::drawSolidRect(pixel_bounding_box);
*/

/*
ci::gl::drawStringCentered(
    "Prediction: " + std::to_string(current_prediction_),
    glm::vec2(kWindowSize / 2, kWindowSize - kMargin / 2), ci::Color("white"));
    */
/*
  ci::gl::drawStringCentered(
          "Prediction: " + std::to_string(current_prediction_),
          glm::vec2(kWindowSize / 2, kWindowSize - kMargin / 2), ci::Color("white"), ci::Font("Arial", 48.0f));
}
*/
/*
void IdealGasApp::update()
{
    x += 1;
}


void IdealGasApp::mouseDown(ci::app::MouseEvent event) {
  sketchpad_.HandleBrush(event.getPos());
}

void IdealGasApp::mouseDrag(ci::app::MouseEvent event) {
  sketchpad_.HandleBrush(event.getPos());
}

void IdealGasApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_RETURN:
      // ask your classifier to classify the image that's currently drawn on the
      // sketchpad and update current_prediction_
      //current_prediction_ = classifier.ClassifyImage();
      break;

    case ci::app::KeyEvent::KEY_DELETE:
      sketchpad_.Clear();
      break;
  }
}

}  // namespace visualizer

}  // namespace naivebayes
*/