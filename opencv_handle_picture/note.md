# 读取图像
```cpp
Mat img = cv::imread(filename[, flags])
/*
保持原格式不变	-1
灰度图像	0
BGR	1
图像深度为16 or 32返回灰度图像，否则转换为8位图像	2
以任何可能颜色格式读取图像	4
*/

CV_8UC1/CV_8UC2/CV_8UC3(一通道/二通道/三通道)
// https://docs.opencv.org/2.4/doc/tutorials/core/mat_the_basic_image_container/mat_the_basic_image_container.html

//修改Mat的数据
img.col(i).row(j) = cv::Scalar{0, 0, 0};
```

cv::Mat:

+ row(n) : 访问第n行
+ col(n) : 访问第n列
+ rowRange(int start, int end) : 访问row范围[start, end)
+ colRange(int start, int end) : 访问范围[start, end)
+ rows : 图像的rows属性
+ cols : 图像的cols属性

# 显示图像
+ 给窗口命名: namedWindow(std::string windowname)
+ 显示图像: imshow(windowname, mat)

# 保存图像(到文件)
imwrite(std::string filename, mat[, params]);


#