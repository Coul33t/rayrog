//
// Created by couland-q on 06/05/2026.
//

#include "renderer.h"

Renderer::Renderer() {

}

Renderer::~Renderer() {

}

bool Renderer::init() {
    kraylib::init_window(24*50, 24*35, "Yoooo");
    kraylib::set_target_fps(60);

    TilesetInfo tileset_info(24*16, 24*16, 24, 24);
    tileset_info.add_tile("wall", 3, 2);

    tileset.load_tileset("../../data/Curses_square_24.png", tileset_info);

    tileset.add_tile("wall", 3, 2);
    tileset.add_tile("floor", 14, 2);
    tileset.add_tile("player", 0, 4);
    tileset.add_tile("monster", 0, 14);

    return true;
}

void Renderer::close() {
    kraylib::close_window();
}

bool Renderer::window_should_close() {
    return kraylib::window_should_close();
}

void Renderer::draw_tile(const std::string& name, Position pos) {
    Position tile_pos = tileset.get_tile_pos(name);

    if (tile_pos != Position{-1, -1}) {
        Rectangle rect = Tools::get_rect(tileset.to_real_pos(tile_pos), tileset.get_tile_size());
        kraylib::draw_texture_rec(tileset.text, rect, pos.as_vec2(), WHITE);
    }
}

void Renderer::draw_tile(const Tile& tile, Position pos) {
    draw_tile(tiletype_to_str(tile.type), pos);
}

void Renderer::draw_tile(const Tile& tile, Vector2 pos) {
    draw_tile(tile, Position{static_cast<int>(pos.x), static_cast<int>(pos.y)});
}

void Renderer::draw_map(const GameMap& gamemap) {
    Vector2 tile_size = tileset.get_tile_size();

    for (int x = 0; x < gamemap.w; x++) {
        for (int y = 0; y < gamemap.h; y++) {
            draw_tile(gamemap.tiles[Tools::coord_2d_to_1d(x, y, gamemap.w)],
                Vector2{x * tile_size.x, y * tile_size.y});
        }
    }
}

void Renderer::draw_entity(Entity& entity) {
    Vector2 tile_size = tileset.get_tile_size();
    auto pos = std::any_cast<Position>(entity.get_comp<Position>())->as_vec2();
    auto graphics = std::any_cast<Graphics>(entity.get_comp<Graphics>());

    Position tile_pos = tileset.get_tile_pos(graphics->name);

    if (tile_pos != Position{-1, -1}) {
        const Rectangle rect = Tools::get_rect(tileset.to_real_pos(tile_pos), tileset.get_tile_size());
        kraylib::draw_texture_rec(tileset.text, rect, {pos.x * tile_size.x, pos.y * tile_size.y}, WHITE);
    }
}

void Renderer::draw_player(Entity& player) {
    draw_entity(player);
}

void Renderer::draw_entities(EntitiesManager& ent_manager) {
    for (auto& ent: ent_manager.entities) {
        if (!ent.has_tag(Tag::PLAYER)) {
            draw_entity(ent);
        }
        
    }
}

void Renderer::render_all(const GameMap& gamemap, EntitiesManager& ent_manager) {
    draw_map(gamemap);
    draw_player(*(ent_manager.get_player()));
    draw_entities(ent_manager);
}
