//
// Created by Omar on 10/20/2020.
//

/*
#include <core/image_classifier.h>

namespace naivebayes {

ImageClassifier::ImageClassifier(ModelTrainer& trainer,
                                 std::vector<std::vector<int>> image) {
  //trainer_ = trainer;
  user_image_ = image;
}

void ImageClassifier::CalculateLikelihoodScores() {
  // Calculate the likelihood scores for all classes
  for (size_t class_num = 0; class_num < likelihood_scores_.size();
       ++class_num) {
    for (size_t row = 0; row < user_image_.size(); ++row) {
      for (size_t col = 0; col < user_image_.at(row).size(); ++col) {
        if (user_image_.at(row).at(col) == 1) {
          //likelihood_scores_.at(class_num) +=
            //  log(image_probability_matrix_.at(row).at(col));
        } else {
        }
      }
    }
  }
}

int ImageClassifier::ClassifyImage() {
  // Find the class with the highest likelihood score and return the class
  double highest_likelihood_score_index = 0;
  double highest_likelihood_score = likelihood_scores_.at(0);
  double current_class_score = 0;
  for (size_t class_num = 1; class_num < likelihood_scores_.size();
       ++class_num) {
    current_class_score = likelihood_scores_.at(class_num);
    if (current_class_score > highest_likelihood_score) {
      highest_likelihood_score = current_class_score;
      highest_likelihood_score_index = class_num;
    }
  }

  //return highest_likelihood_score_index;
  return 1;
}

}  // namespace naivebayes

 */