//
// Created by couland-q on 06/05/2026.
//

#ifndef RAYROG_RENDERER_H
#define RAYROG_RENDERER_H

#include "../entities/entity.h"
#include "../gamemap/gamemap.h"
#include "../include_raylib.h"
#include "tileset.h"
#include "tileset_info.h"
#include "../components/position.h"
#include "../components/graphics.h"
#include "../tools.h"
#include "../gamemap/gamemap.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    bool init();
    void close();
    bool window_should_close();

    void draw_tile(const std::string& name, Position pos);
    void draw_tile(const Tile& tile, Position pos);
    void draw_tile(const Tile& tile, Vector2 pos);

    void draw_map(const GameMap& map);
    void draw_entity(Entity& entity);
    void draw_player(Entity& player);
    void draw_entities(std::vector<Entity>& entities);
    void render_all(const GameMap& gamemap, Entity& player, std::vector<Entity>& entities);

    Tileset tileset;
};



#endif //RAYROG_RENDERER_H
