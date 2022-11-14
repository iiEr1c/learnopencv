#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/opencv.hpp>

int main() {
  auto img = cv::imread(
      "/home/eric/code/learnopencv/opencv_handle_picture/Lenna.png", -1);
  std::cout << img.rows << '\t' << img.cols << '\n';
  std::cout << img.rowRange(0, 2).colRange(0, 2) << '\n';
  cv::imshow(std::string("Lenna"), img);
  cv::waitKey(0);
  return 0;
}