#include "image_utils.hpp"
#include <iostream>
#include <stdexcept>

namespace imgutils {
    cv::Mat loadImage(const std::string& path, int flags) {
        cv::Mat img = cv::imread(path, flags);
        if (img.empty()) {
            throw std::runtime_error("无法读取图像" + path);

        }
        return img;
    }

    void showImage(const std::string& title, const cv::Mat& img, int waitMs) {
        if(img.empty()) {
            throw std::invalid_argument("showImage: 图像为空");
        }
        cv::imshow(title, img);
        cv::waitKey(waitMs);
        cv::destroyAllWindows();
    }

    void printImageInfo(const std::string& name, const cv::Mat& img) {
        int channels = img.channels();
        double minVal, maxVal;
        // reshape(1) 把多通道压成单通道，方便 minMaxLoc。
        cv::minMaxLoc(img.reshape(1), &minVal, &maxVal);

        std::cout << "[" << name << "]\n"
                << " row/cols: " << img.rows << " x " << img.cols << "\n"
                << " channels: " << channels << "\n"
                << " depth: " << img.depth() << " (0=CV_8U)\n"
                << " min/max: " << minVal << " / " << maxVal << "\n";
    }
}