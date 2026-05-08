//
// Created by couland-q on 06/05/2026.
//

#include "tileset.h"

Tileset::Tileset() {

}

Tileset::~Tileset() {

}

bool Tileset::load_tileset(const std::string &path_to_file, TilesetInfo ts_info) {
    text = raylib::LoadTexture(path_to_file.c_str());
    this->ts_info = ts_info;
    return true;
}

void Tileset::add_tile(const std::string& name, int x, int y) {
    ts_info.add_tile(name, x, y);
}

Position Tileset::get_tile_pos(const std::string& tile_name) {
    return ts_info.get_tile(tile_name);
}

raylib::Vector2 Tileset::get_tile_size() const {
    return ts_info.get_tile_size();
}

raylib::Vector2 Tileset::to_real_pos(const int x, const int y) const {
    return raylib::Vector2{static_cast<float>(x * ts_info.tile_w), static_cast<float>(y * ts_info.tile_h)};
}

raylib::Vector2 Tileset::to_real_pos(const Position pos) const {
    return raylib::Vector2{static_cast<float>(pos.x * ts_info.tile_w), static_cast<float>(pos.y * ts_info.tile_h)};
}