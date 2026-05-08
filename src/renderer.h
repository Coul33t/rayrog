//
// Created by couland-q on 06/05/2026.
//

#ifndef RAYROG_RENDERER_H
#define RAYROG_RENDERER_H

#include "gamemap.h"
#include "include_raylib.h"
#include "tileset.h"
#include "tileset_info.h"
#include "components/position.h"
#include "tools.h"
#include "gamemap.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    bool init();
    void close();
    bool window_should_close();

    void draw_tile(const std::string& name, Position pos);
    void draw_tile(const Tile& tile, Position pos);
    void draw_map(const GameMap& map);

    Tileset tileset;
};



#endif //RAYROG_RENDERER_H
