/*
//
// Created by Omar on 10/18/2020.
//
#include <core/model_trainer.h>

namespace naivebayes {

ModelTrainer::ModelTrainer(ImageParser& parser) {
  parser_ = parser;

  std::cout << "Number of classes: " << parser_.num_of_classes_ << std::endl;
  std::cout << "Number of training images: " << parser_.num_of_training_images_
            << std::endl;

  // Initialize image_probability_matrix_ to 0
  for (size_t index = 0; index < parser_.num_of_classes_; ++index) {
    std::vector<std::vector<double> > outer;
    for (size_t row = 0; row < parser_.images_.at(index).GetImageLength();
         ++row) {
      std::vector<double> inner;
      for (size_t col = 0; col < parser_.images_.at(index).GetImageLength();
           ++col) {
        inner.push_back(0);
      }

      outer.push_back(inner);
    }

    image_probability_matrix_.push_back(outer);
  }

  // DisplayImageProbabilityMatrix();

  // Initialize class_counter_ to 0
  for (size_t class_number = 0; class_number < parser_.num_of_classes_;
       ++class_number) {
    class_counter_.push_back(0);
  }

  // Determine the number of occurrences for each class
  for (size_t class_number = 0; class_number < parser_.num_of_classes_;
       ++class_number) {
    for (size_t label = 0; label < parser.image_labels_.size(); ++label) {
      if (parser_.image_labels_.at(label) == class_number) {
        class_counter_.at(class_number) += 1;
      }
    }
  }
}

double ModelTrainer::ClassProbability(size_t class_number) {
  std::cout << "Class " << class_number << " Probability: "
            << (double)(kLaplaceConstant + class_counter_.at(class_number)) /
                   (parser_.num_of_classes_ * kLaplaceConstant +
                    (parser_.num_of_training_images_))
            << std::endl;
  return (double)(kLaplaceConstant + class_counter_.at(class_number)) /
         (parser_.num_of_classes_ * kLaplaceConstant +
          (parser_.num_of_training_images_));
}

void ModelTrainer::GenerateImageProbabilityMatrix() {

  for(size_t index = 0; index < parser_.num_of_training_images_; index++)
  {
    for(size_t row = 0; row < parser_.images_.at(index).GetImageLength(); row++)
    {
      for(size_t col =0; col < parser_.images_.at(index).GetImageLength(); col++)
      {
        image_probability_matrix_.at(parser_.image_labels_.at(index)).at(row).at(col) += size_t(IsPixelShaded(index, row, col));
      }
    }
  }

  /*
  // Determine the probability that a given pixel is shaded with laplace
  // smoothing
  for (size_t class_num = 0; class_num < image_probability_matrix_.size(); ++class_num)
  {
    std::cout << "Class Number " << class_num << ": " << std::endl;
    for (size_t row = 0; row < image_probability_matrix_.at(class_num).size(); ++row) {

      for (size_t col = 0; col < image_probability_matrix_.at(class_num).at(row).size(); ++col)
      {
        image_probability_matrix_.at(parser_.image_labels_.at(class_num)).at(row).at(col) = (kLaplaceConstant +
                                image_probability_matrix_.at(parser_.image_labels_.at(class_num)).at(row).at(col)) / (2 * kLaplaceConstant + class_counter_.at(class_num));


        std::cout << image_probability_matrix_.at(parser_.image_labels_.at(class_num)).at(row).at(col) << " ";

      }

      std::cout << std::endl;
    }
  }
}

bool ModelTrainer::IsPixelShaded(size_t image_index, size_t row, size_t col) {
  // Determine if the character at a given pixel is shaded/unshaded
  char image_pixel_character =
      parser_.images_.at(image_index).GetImagePixel(row, col);
  for (size_t character = 0; character < kShadedPixelChars.size();
       ++character) {
    if (image_pixel_character == kShadedPixelChars.at(character)) {
      return true;
    }
  }

  return false;
}

void ModelTrainer::DisplayImageProbabilityMatrix() {
  std::cout << "Image Probability Matrix: " << std::endl;
  for (size_t index = 0; index < image_probability_matrix_.size(); ++index) {
    std::cout << "Label: " << index << std::endl;
    for (size_t row = 0; row < image_probability_matrix_.at(index).size();
         ++row) {
      for (size_t col = 0;
           col < image_probability_matrix_.at(index).at(row).size(); ++col) {
        std::cout << image_probability_matrix_.at(index).at(row).at(col) << "|";
      }

      std::cout << std::endl;
    }

    std::cout << std::endl;
  }
}

void ModelTrainer::DisplayClassCounter() {
  for (size_t class_number = 0; class_number < class_counter_.size();
       ++class_number) {
    std::cout << "Class " << class_number << " -> "
              << class_counter_.at(class_number) << " time(s)" << std::endl;
  }

  std::cout << std::endl;
}

}  // namespace naivebayes
*/