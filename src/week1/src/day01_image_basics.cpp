#include <iostream>
#include <opencv2/opencv.hpp>
#include "image_utils.hpp"

using namespace std;

/**编译命令
cmake -S . -B build -A x64
cmake --build build --config Debug --target day01_image_basics
.\build\Debug\day01_image_basics.exe
**/


int main() {
    try
    {
        const string assets = "E:/code/C++/AdvancedVision/image/hss1.jpg";
        const string output = "./output/";

        // 1. 读图 cv::Mat 引用计数自动管理内存，不需要手动 delete。
        cv::Mat img = imgutils::loadImage(assets, cv::IMREAD_COLOR);
        imgutils::printImageInfo("原始 BGR 图", img);

        // 2. 显示
        imgutils::showImage("Original", img);

        // 3. 灰度转换
        cv::Mat gray;
        cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
        imgutils::printImageInfo("灰度图", gray);
        imgutils::showImage("Gray", gray);

        // 4. ROI 裁剪 想强制拷贝用 img.clone()，浅拷贝用 img 直接赋值。
        int h = gray.rows, w = gray.cols;
        // cv::Rect 的构造顺序是 (x, y, width, height)
        cv::Rect roiRect(w / 4, h / 4, w / 4, h / 4);
        // gray(roiRect) 是浅拷贝，共享数据；如需独立用 gray(roiRect).clone()。
        cv::Mat roi = gray(roiRect);
        imgutils::printImageInfo("ROI", roi);
        imgutils::showImage("ROI", roi);

        // 5. 保存
        cv::imwrite(output + "day01_gray_cpp.jpg", gray);
        cv::imwrite(output + "day01_roi_cpp.jpg", roi);
        cout << "已保存到 " << output << "/n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "错误： " << e.what() << '/n';
        return -1;
    }
    return 0;
}