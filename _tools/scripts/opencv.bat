git clone https://github.com/Itseez/opencv_contrib.git
cd opencv_contrib
git checkout ${CV_VERSION}
cd ..
git clone https://github.com/Itseez/opencv.git
cd opencv
git checkout ${CV_VERSION}
mkdir build 
cd build 
cmake -D CMAKE_INSTALL_PREFIX=../install \
          -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
          -D INSTALL_C_EXAMPLES=OFF \
          -D INSTALL_PYTHON_EXAMPLES=OFF \
          -D BUILD_EXAMPLES=OFF \
          -D WITH_OPENGL=ON \
          -D WITH_V4L=ON \
          -D WITH_XINE=ON \
          -D WITH_TBB=ON \
          -G "Visual Studio 14 Win64" ..
