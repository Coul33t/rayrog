//
// Created by couland-q on 06/05/2026.
//

#include "renderer.h"

Renderer::Renderer() {

}

Renderer::~Renderer() {

}

bool Renderer::init() {
    InitWindow(24*50, 24*35, "Yoooo");
    SetTargetFPS(60);

    TilesetInfo tileset_info(24*16, 24*16, 24, 24);
    tileset_info.add_tile("wall", 3, 2);

    tileset.load_tileset("../../data/Curses_square_24.png", tileset_info);

    tileset.add_tile("wall", 3, 2);
    tileset.add_tile("floor", 14, 2);

    return true;
}

void Renderer::close() {
    CloseWindow();
}

bool Renderer::window_should_close() {
    return WindowShouldClose();
}

void Renderer::draw_tile(const std::string& name, Position pos) {
    Position tile_pos = tileset.get_tile_pos(name);

    if (tile_pos != Position{-1, -1}) {
        Rectangle rect = Tools::get_rect(tileset.to_real_pos(tile_pos), tileset.get_tile_size());
        DrawTextureRec(tileset.text, rect, pos.as_vec2(), WHITE);
    }
}

void Renderer::draw_tile(const Tile& tile, Position pos) {
    draw_tile(tiletype_to_str(tile.type), pos);
}

void Renderer::draw_map(const GameMap& gamemap) {
    for (int i = 0; i < gamemap.w; i++) {
        for (int j = 0; j < gamemap.h; j++) {
            draw_tile(gamemap.tiles[Tools::coord_2d_to_1d(i, j)], {i, j});
        }
    }
}
