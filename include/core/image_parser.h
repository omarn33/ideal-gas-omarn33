/*
//
// Created by Omar on 10/12/2020.
//
#pragma once

#include <fstream>
#include <map>
#include <vector>

#include "particle.h"

namespace naivebayes {

class ImageParser {
 private:
  std::vector<Image> images_;
  std::vector<int> image_labels_;
  size_t num_of_training_images_;
  size_t num_of_classes_;

  friend class ModelTrainer;

 public:

  void ReadImageLabels(std::istream& is);


  void DisplayImageLabels();


  void DisplayImages();

  friend std::istream& operator>>(std::istream& is, ImageParser& parser);
};

}  // namespace naivebayes
*/