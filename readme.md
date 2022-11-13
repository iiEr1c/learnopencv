# 环境配置(ubuntu22.04)

```shell
sudo apt-get install build-essential libgtk2.0-dev libgtk-3-dev libavcodec-dev libavformat-dev libjpeg-dev libswscale-dev libtiff5-dev
# libdc1394 2.x CUDA Toolkit 6.5

# 官网下载源码 https://opencv.org/releases/
# wget -e "http_proxy=http://<ip>:<port>/" https://github.com/opencv/opencv/archive/4.6.0.zip

unzip 4.6.0.zip

cd opencv4.6.0
mkdir build
cd build
# -D OPENCV_GENERATE_PKGCONFIG=YESOpenCV4以上默认不使用pkg-config，该编译选项开启生成opencv4.pc文件
cmake -D CMAKE_BUILD_TYPE=Release -D OPENCV_GENERATE_PKGCONFIG=YES ..
make

# 安装
sudo make install

# 默认安装位置
# 注意: 默认安装路径为:/usr/local/bin - executable files /usr/local/lib - libraries (.so) /usr/local/cmake/opencv4 - cmake package /usr/local/include/opencv4 - headers /usr/local/share/opencv4 - other files (e.g. trained cascades in XML format)

# 配置pkg-config环境
# opencv4.pc文件的默认路径为/usr/local/lib/pkgconfig/opencv4.pc
# 配置动态环境
sudo vim /etc/ld.so.conf.d/opencv4.conf
# 末尾添加/usr/local/lib
# 配置生效
sudo ldconfig
# 修改bash.bsdhrc
# vim /etc/bash.bashrc
vim /etc/bash.bashrc
PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig export PKG_CONFIG_PATH

# gcc /usr/local/include/opencv4
gcc xx.cpp -I/usr/local/include/opencv4 `pkg-config --libs --cflags opencv`

g++ -I /usr/local/include/opencv4 -L /usr/local/lib/ -g main.cpp -l opencv_highgui -l opencv_core -l opencv_imgcodecs
```


# reference
+ [Linux环境下OpenCV的安装与配置](https://blog.csdn.net/weixin_52402390/article/details/122341561)
+ [opencv环境](https://zhuanlan.zhihu.com/p/473488905)