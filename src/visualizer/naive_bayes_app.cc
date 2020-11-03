#include <visualizer/naive_bayes_app.h>
#include <glm/glm.hpp>
//using glm::vec2;

namespace naivebayes {

namespace visualizer {

NaiveBayesApp::NaiveBayesApp()
    : sketchpad_(glm::vec2(kMargin, kMargin), kImageDimension,
                 kWindowSize - 2 * kMargin) {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);

  x = 1500;
}

void NaiveBayesApp::draw() {
  //ci::Color8u background_color(255, 246, 148);  // light yellow

  // Draw a black background
  ci::Color8u background_color(0, 0, 0);

  // Clear the background color
  ci::gl::clear(background_color);

  //sketchpad_.Draw();


  ci::gl::drawStringCentered(
      "Click to add a particle. Press Enter to make a prediction.",
      glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("white"), ci::Font("Arial", 48.0f));



  ci::gl::color(ci::Color("gray"));
  ci::gl::drawSolidCircle(glm::vec2 {x, x}, 15.0f);
  x -= 1;

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
    ci::gl::drawStringCentered(
            "Prediction: " + std::to_string(current_prediction_),
            glm::vec2(kWindowSize / 2, kWindowSize - kMargin / 2), ci::Color("white"), ci::Font("Arial", 48.0f));
}

/*
void NaiveBayesApp::update()
{
    x += 1;
}
*/

void NaiveBayesApp::mouseDown(ci::app::MouseEvent event) {
  sketchpad_.HandleBrush(event.getPos());
}

void NaiveBayesApp::mouseDrag(ci::app::MouseEvent event) {
  sketchpad_.HandleBrush(event.getPos());
}

void NaiveBayesApp::keyDown(ci::app::KeyEvent event) {
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
