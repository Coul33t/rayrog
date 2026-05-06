//
// Created by couland-q on 06/05/2026.
//

#include "tileset.h"

Tileset::Tileset() {

}

Tileset::~Tileset() {

}

bool Tileset::load_tileset(const std::string &path_to_file, TilesetInfo ts_info) {
    text = LoadTexture(path_to_file.c_str());
    this->ts_info = ts_info;
    return true;
}
