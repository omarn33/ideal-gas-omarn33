/*
//
// Created by Omar on 10/18/2020.
//

#pragma once

#include <core/image_parser.h>
#include <core/image_classifier.h>

#include <vector>

namespace naivebayes {

class ModelTrainer {
 private:
  size_t kLaplaceConstant = 1;
  std::vector<char> kShadedPixelChars = {'+', '#'};
  std::vector<int> class_counter_;
  std::vector<std::vector<std::vector<double>>> image_probability_matrix_;
  ImageParser parser_;

  //friend ImageClassifier;

 public:
  ModelTrainer();

  ModelTrainer(ImageParser& parser);

  double ClassProbability(size_t class_number);

  void GenerateImageProbabilityMatrix();

  bool IsPixelShaded(size_t image_index, size_t row, size_t col);

  void DisplayImageProbabilityMatrix();

  void DisplayClassCounter();
};

}  // namespace naivebayes
*/