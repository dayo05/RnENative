#ifndef RNENATIVE_LIBRARY_H
#define RNENATIVE_LIBRARY_H

extern "C" {
    void* image_read(void*, const char*);
    void* open_video(const char*);
    void* read_frame(void*, void*);
    int get_height(void*);
    int get_width(void*);
    int get_channel(void*);
    void draw_rect(void*, int, int, int, int);
    void image_show(void*, const char*);
    void* get_image(void*);
    void* resize(void*, int, int);
    void* crop(void*, void*, int, int, int, int);
    void* create_mat();
    void save_image(void*, const char*);
    void grayscale(void*);
};

#endif //RNENATIVE_LIBRARY_H
