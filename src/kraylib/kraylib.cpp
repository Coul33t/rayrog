#include "kraylib.h"

namespace kraylib {
    void init_window(int w, int h, const std::string& title) {
        InitWindow(w, h, title.c_str());
    }

    void init_window(int w, int h, const char* title) {
        InitWindow(w, h, title);
    }

    void close_window() {
        CloseWindow();
    }

    bool window_should_close() {
        return WindowShouldClose();
    }

    void set_target_fps(int t_fps) {
        SetTargetFPS(t_fps);
    }

    Texture2D load_texture(const char* path) {
        return LoadTexture(path);
    }

    void begin_drawing() {
        BeginDrawing();
    }

    void end_drawing() {
        EndDrawing();
    }

    void clear_background(Color color) {
        ClearBackground(BLACK);
    }

    void draw_texture_rec(Texture2D text, Rectangle src, Vector2 pos, Color tint) {
        DrawTextureRec(text, src, pos, tint);
    }

    bool is_key_pressed(int key) {
        return IsKeyPressed(key);
    }
}