//
// Created by couland-q on 06/05/2026.
//

#include "renderer.h"

Renderer::Renderer() {

}

Renderer::~Renderer() {

}

bool Renderer::init() {
    InitWindow(640, 480, "Yoooo");
    SetTargetFPS(60);

    TilesetInfo tileset_info(24*16, 24*16, 24, 24);
    tileset_info.add_tile("wall", 3, 2);

    tileset.load_tileset("Curses_square_24.png", tileset_info);

    return true;
}

void Renderer::close() {
    CloseWindow();
}

bool Renderer::windowShouldClose() {
    return WindowShouldClose();
}
