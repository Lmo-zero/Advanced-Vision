#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    std::cout << "OpenCV 版本: " << CV_VERSION << std::endl;

    // 读取图像（相对路径基于工作目录）
    std::string image_path = "../../image/hss1.jpg";
    cv::Mat img = cv::imread(image_path);

    if (img.empty()) {
        std::cerr << "无法打开图像: " << image_path << std::endl;
        return -1;
    }

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    cv::imshow("Color", img);
    cv::imshow("Gray", gray);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}