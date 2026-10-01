#pragma once
#include <string>
#include <opencv2/opencv.hpp>


namespace imgutils {
    //读图，失败时抛 std::runtime_error
    cv::Mat loadImage(const std::string& path, int flags = cv::IMREAD_COLOR);

    //显示图像，waitMs = 0, 等待任意键
    void showImage(const std::string& title, const cv::Mat& img, int waitMs = 0);

    //打印 shape / type / channels / min / max
    void printImageInfo(const std::string& name, const cv::Mat& img);
}   // namespace imgutils