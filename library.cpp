#include "library.h"

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

void* image_read(void* i, const char* str) {
    auto k = static_cast<cv::Mat *>(i);
    *k = cv::imread(str);
    cv::cvtColor(*k, *k, cv::COLOR_BGR2RGB);
    return k;
}

void* open_video(const char* video) {
    return new cv::VideoCapture(video);
}

void* read_frame(void* i, void* mat) {
    auto* vc = static_cast<cv::VideoCapture *>(i);

    if(!vc->isOpened()) return nullptr;
    auto k = static_cast<cv::Mat *>(mat);
    *vc >> *k;
    if(k->empty()) return nullptr;
    try {
        cv::cvtColor(*k, *k, cv::COLOR_BGR2RGB);
    } catch(cv::Exception &k) {
        return nullptr;
    }
    return k;
}

int get_height(void* image) {
    return static_cast<cv::Mat *>(image)->rows;
}

int get_width(void* image) {
    return static_cast<cv::Mat *>(image)->cols;
}

int get_channel(void* image) {
    return static_cast<cv::Mat *>(image)->channels();
}

void draw_rect(void* image, int x, int y, int w, int h) {
    cv::rectangle(*static_cast<cv::Mat *>(image), cv::Rect2i(x, y, w, h), cv::Scalar::all(255), 2, cv::LINE_AA, 0);
}

void image_show(void* i, const char* str) {
    auto image = static_cast<cv::Mat *>(i);
    cv::cvtColor(*image, *image, cv::COLOR_RGB2BGR);
    cv::imshow(str, *image);
    cv::cvtColor(*image, *image, cv::COLOR_BGR2RGB);
    cv::waitKey(25);
}

void* get_image(void* image) {
    return static_cast<cv::Mat *>(image)->data;
}

void* crop(void* i, void* crop, int x, int y, int w, int h) {
    auto image = static_cast<cv::Mat *>(i);
    auto ci = static_cast<cv::Mat *>(crop);
    cv::Rect bounds(0, 0, image->cols, image->rows);
    cv::Rect r(x, y, w, h);
    *ci = (*image)(r & bounds);
    return ci->data;
}

void* resize(void* i, int w, int h) {
    auto image = static_cast<cv::Mat *>(i);
    cv::resize(*image, *image, cv::Size(w, h));
    return image->data;
}

void* create_mat() {
    return new cv::Mat[1];
}

void save_image(void* img, const char* str) {
    auto image = static_cast<cv::Mat *>(img);
    cv::Mat k;
    if(image->empty()) {
	    std::cout << "ERROR!" << std::endl;
	    return;
    }
    cv::cvtColor(*image, k, cv::COLOR_RGB2BGR);
    cv::imwrite(str, k);
}

void grayscale(void* img) {
    auto image = static_cast<cv::Mat *>(img);
    cv::cvtColor(*image, *image, cv::COLOR_RGB2GRAY);
}
