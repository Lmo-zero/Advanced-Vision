python 读取自定义包前添加项目路径，如：
```python
import sys
sys.path.append("..")
from utils.image_utils import load_images, show_image, print_image_info
```