#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/opencv.hpp>

int main() {
  auto img = cv::imread(
      "/home/eric/code/learnopencv/opencv_handle_picture/Lenna.png", 0);
  img.rowRange(100, 200).colRange(20, 150) = 255;

  for (int i = 300; i < 400; ++i) {
    for (int j = 20; j < 150; ++j) {
      img.row(i).col(j) = 255;
    }
  }

  std::cout << img.rows << '\t' << img.cols << '\n';
  std::cout << img.rowRange(0, 2).colRange(0, 2) << '\n';
  cv::imshow(std::string("Lenna"), img);
  cv::waitKey(0);
  return 0;
}