//
// Created by couland-q on 06/05/2026.
//

#ifndef RAYROG_TILESET_H
#define RAYROG_TILESET_H

#include <string>
#include "raylib.h"
#include "tileset_info.h"

class Tileset {
public:
    Tileset();
    ~Tileset();

    bool load_tileset(const std::string& path_to_file, TilesetInfo ts_info);

    Texture2D text;
    TilesetInfo ts_info;
};



#endif //RAYROG_TILESET_H
