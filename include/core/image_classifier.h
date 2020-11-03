/*
//
// Created by Omar on 10/20/2020.
//
#pragma once

#include <core/model_trainer.h>
#include <core/image_parser.h>

#include <vector>

namespace naivebayes {

class ImageClassifier {
 private:
  ImageParser parser_;
  ModelTrainer trainer_(ImageParser& parser_);
  std::vector< std::vector<int> > user_image_;
  std::vector<double> likelihood_scores_;
  std::vector<int> label_predictions_;
  double prediction_accuracy_;

 public:

  ImageClassifier(ModelTrainer& trainer, std::vector<std::vector<int>> image);

  void CalculateLikelihoodScores();

  int ClassifyImage();

  void CalculateLabelAccuracy();

};
}
*/
