//
// Created by couland-q on 06/05/2026.
//

#ifndef RAYROG_TILESET_H
#define RAYROG_TILESET_H

#include <string>
#include "raylib.h"
#include "tileset_info.h"
#include "tiletype.h"

class Tileset {
public:
    Tileset();
    ~Tileset();

    bool load_tileset(const std::string& path_to_file, TilesetInfo ts_info);

    void add_tile(const std::string& name, int x, int y);

    Position get_tile_pos(const std::string& tile_name);

    Vector2 get_tile_size() const;
    Vector2 to_real_pos(int x, int y) const;
    Vector2 to_real_pos(Position pos) const;

    Texture2D text;
    TilesetInfo ts_info;
};



#endif //RAYROG_TILESET_H
