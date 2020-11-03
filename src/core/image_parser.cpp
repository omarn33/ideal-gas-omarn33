/*
#include <core/image_parser.h>

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

namespace naivebayes {

void ImageParser::ReadImageLabels(std::istream& is) {
  // Parse image label file and store image labels
  std::string label = "";
  std::vector<int> classes;
  std::unordered_set<int> class_set;
  while (getline(is, label)) {
    image_labels_.push_back(std::stoi(label));
  }

  // Determine the number of classes from the image labels file
  // Source: http://www.cplusplus.com/forum/beginner/203059/
  class_set.insert(image_labels_.begin(), image_labels_.end());
  for (const int& x : class_set) {
    classes.push_back(x);
  }

  num_of_classes_ = classes.size();
}

void ImageParser::DisplayImageLabels() {
  std::cout << "Labels: " << std::endl;
  for (size_t label = 0; label < image_labels_.size(); ++label) {
    std::cout << image_labels_.at(label) << std::endl;
  }

  std::cout << std::endl;
}

void ImageParser::DisplayImages() {
  // Display images
  for (size_t image = 0; image < images_.size(); ++image) {
    std::cout << "Image " << image << ": " << std::endl;
    images_.at(image).DisplayImage();
    std::cout << std::endl;
  }
}

std::istream& operator>>(std::istream& is, ImageParser& parser) {
  std::string characters;
  size_t image_height = 0;
  std::vector<std::vector<char> > image_vtr;
  std::vector<char> image_row_vtr;

  // Iterate through the image file until all images are stored
  while (getline(is, characters)) {
    // Iterate through each line in the image file and populate the image vector
    for (size_t character = 0; character < characters.length(); ++character) {
      image_row_vtr.push_back(characters[character]);
    }

    image_vtr.push_back(image_row_vtr);
    ++image_height;

    // Determine if the full image has been stored
    if (image_height == characters.length()) {
      // Load the entire image into a vector
      parser.images_.push_back(Image(image_vtr));
      image_height = 0;

      image_vtr.clear();
    }

    image_row_vtr.clear();
  }

  // Set the number of training images to the number of images in the parser
  parser.num_of_training_images_ = parser.images_.size();

  return is;
}

}  // namespace naivebayes
 */