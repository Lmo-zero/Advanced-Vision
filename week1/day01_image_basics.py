"""Day 01: 图像读写、显示、属性、灰度、ROI"""
import os 
import cv2
import sys
import numpy as np

sys.path.append("..")
from utils.image_utils import load_images, show_image, print_image_info

ASSETS = "../assets/hss1.jpg"
OUTPUT = "./output"


def main() -> None:
    os.makedirs(OUTPUT, exist_ok=True)

    # 1. 读图
    img = load_images(ASSETS, cv2.IMREAD_COLOR)
    print_image_info("原始 BGR 图", img)

    # 2. 显示
    show_image("Original", img)

    # 3. 灰度转换（两种方式对比）
    gray_cvt = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # 手动模拟灰度转换： Y = 0.299R + 0.587G + 0.144B
    b, g, r = cv2.split(img)
    gray_manual = (0.299 * r + 0.587 * g + 0.114 * b).astype(np.uint8)

    # 对比两者差异
    diff = cv2.absdiff(gray_cvt, gray_manual)
    print(f"cvtColor 与 手写灰度最大差异：{diff.max()}")

    print_image_info("灰度图",gray_cvt)
    show_image("Gray(cvtColor)", gray_cvt)

    # 4.ROI剪裁
    h, w = gray_cvt.shape[:2]
    roi = gray_cvt[h // 4: h // 2, w // 4 : w // 2]
    print_image_info("ROI", roi)
    show_image("ROI", roi)

    # 5. 保存
    cv2.imwrite(os.path.join(OUTPUT, "day01_gray.jpg"), gray_cvt)
    cv2.imwrite(os.path.join(OUTPUT, "day01_roi.jpg"), roi)
    print(f"已保存到 {OUTPUT}")


if __name__ == "__main__":
    main()
