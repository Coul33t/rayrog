//
// Created by couland-q on 06/05/2026.
//

#ifndef RAYROG_TILESET_INFO_H
#define RAYROG_TILESET_INFO_H

#include <map>
#include "components/position.h"
#include "tiletype.h"

struct TilesetInfo {
    int w, h, tile_w, tile_h;
    std::map<std::string, Position> tiles_idx;

    TilesetInfo() {
        w = -1;
        h = -1;
        tile_w = -1;
        tile_h = -1;
    }

    TilesetInfo(int w, int h, int tile_w, int tile_h): w(w), h(h), tile_w(tile_w), tile_h(tile_h) {}

    void set_info(int w, int h, int tile_w, int tile_h) {
        this->w = w;
        this->h = h;
        this->tile_w = tile_w;
        this->tile_h = tile_h;
    }

    void add_tile(const std::string& name, int x, int y) {
        tiles_idx[name] = Position(x, y);
    }

    Position get_tile(const std::string& name) {
        if (const auto it = tiles_idx.find(name); it != tiles_idx.end()) {
            return it->second;
        }

        return {-1, -1};
    }

    Vector2 get_tile_size() const {
        return Vector2{static_cast<float>(tile_w), static_cast<float>(tile_h)};
    }
};

#endif //RAYROG_TILESET_INFO_H
