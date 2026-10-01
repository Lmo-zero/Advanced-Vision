import cv2
import numpy as np

print(f"OpenCV 版本: {cv2.__version__}")
print(f"NumPy 版本: {np.__version__}")

# 创建一个简单的测试图像并显示
img = np.zeros((300, 400, 3), dtype=np.uint8)
cv2.putText(img, "OpenCV Python OK", (50, 150),
            cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
cv2.imshow("Test", img)
cv2.waitKey(0)
cv2.destroyAllWindows()