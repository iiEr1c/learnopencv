#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/opencv.hpp>

int main() {
  auto img = cv::Mat(500, 500, CV_8UC3, cv::Scalar(255, 0, 0));
  img.col(125).row(125) = cv::Scalar{0, 0, 0};
  for (int i = 100; i < 200; ++i) {
    for (int j = 200; j < 300; ++j) {
      img.col(i).row(j) = cv::Scalar{0, 0, 0};
    }
  }
  cv::imshow(std::string("Lenna"), img);
  cv::waitKey(0);
  return 0;
}