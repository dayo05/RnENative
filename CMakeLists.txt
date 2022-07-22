cmake_minimum_required(VERSION 3.22)
project(RnENative)

include_directories(/usr/local/include/opencv4)

link_libraries(opencv_core)
link_libraries(opencv_videoio)
link_libraries(opencv_imgproc)
link_libraries(opencv_highgui)
link_libraries(opencv_objdetect)
link_libraries(dav1d)
link_libraries(srt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY /home/dayo/lib)

add_library(RnENative SHARED library.cpp)
