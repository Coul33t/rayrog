// Just a namespacing of Raylib

#ifndef RAYROG_KRAYLIB_H
#define RAYROG_KRAYLIB_H

#include <string>
#include "raylib.h"

namespace kraylib {
    void init_window(int w, int h, const std::string& title);
    void init_window(int w, int h, const char* title);

    void close_window();

    bool window_should_close();

    void set_target_fps(int t_fps);


    Texture2D load_texture(const char* path);
    
    // Drawing
    void begin_drawing();
    void end_drawing();
    void clear_background(Color color);
    void draw_texture_rec(Texture2D texture, Rectangle source, Vector2 position, Color tint);

    // Inputs
    bool is_key_pressed(int key);

    
}

#endif