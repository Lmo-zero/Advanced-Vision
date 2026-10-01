"""图像读写与显示工具函数"""
import os
import cv2
import numpy as np
from typing import Optional


def load_images(path: str, flags: int = cv2.IMREAD_COLOR) -> np.ndarray:
    """读取图像，失败时抛出异常
    
    Args:
        path: 图像路径
        flags：cv2.IMREAD_COLOR / GRAYSCALE / UNCHANGED

    Returns:
        BGR 或灰度 ndarray

    Raises:
        FileNotFoundError: 文件不存在
        ValueError: Opencv无法解码
    """
    if not os.path.exists(path):
        raise FileNotFoundError(f"图像不存在：{path}")

    img = cv2.imread(path, flags)
    if img is None:
        raise ValueError(f"opencv 无法解码：{path}")

    return img


def show_image(title: str, img: np.ndarray, wait: int = 0) -> None:
    """显示图像，按任意键关闭
    
    Args:
        title: 窗口标题
        img： ndarry
        wait: cv2.waitKey 的参数，0 表示一直等待

    Raises:
            ValueError: 图像数据为空
    """
    if img is None or img.size == 0:
        raise ValueError("传入的图像为空")

    cv2.imshow(title, img)
    cv2.waitKey(wait)
    cv2.destroyAllWindows()


def print_image_info(name: str, img: np.ndarray) -> None:
    """打印图像的 shape、dtype、通道数、像素范围。"""
    channels = 1 if img.ndim == 2 else img.shape[2]
    bits = 8
    if img.dtype == np.uint16:
        bits = 16
    elif img.dtype == np.uint32 or np.float32:
        bits = 32
    bitDepth = 8 if (channels == 1 and bits == 8) else channels * bits
    print(f"[{name}]")
    print(f"  shape    : {img.shape}")
    print(f"  dtype    : {img.dtype}")
    print(f"  bit depth  : {bitDepth}")
    print(f"  channels    : {channels}")
    print(f"  min/max    : {img.min()} / {img.max()}")