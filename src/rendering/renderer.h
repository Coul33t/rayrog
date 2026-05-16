//
// Created by couland-q on 06/05/2026.
//

#ifndef RAYROG_RENDERER_H
#define RAYROG_RENDERER_H

#include "../entities/entities_manager.h"
#include "../gamemap/gamemap.h"
#include "../kraylib/kraylib.h"
#include "tileset.h"
#include "tileset_info.h"
#include "../components/position.h"
#include "../components/graphics.h"
#include "../misc/tools.h"
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
    void draw_entities(EntitiesManager& entities);
    void render_all(const GameMap& gamemap, EntitiesManager& ent_manager);

    Tileset tileset;
};



#endif //RAYROG_RENDERER_H
