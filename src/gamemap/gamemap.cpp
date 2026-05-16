//
// Created by couland-q on 06/05/2026.
//

#include "gamemap.h"

GameMap::GameMap() {

}

GameMap::~GameMap() {

}

void GameMap::init(size_t w, size_t h) {
    this->w = w;
    this->h = h;

    this->tiles.reserve(w*h);

    for (size_t i = 0; i < w*h; i++) {
        this->tiles.emplace_back();
    }
}

void GameMap::test_map() {
    for (size_t i = 0; i < w; i++) {
        for (size_t j = 0; j < h; j++) {
            if (i == 0 || i == w-1 || j == 0 || j == h-1) {
                tiles[Tools::coord_2d_to_1d(i, j, w)].set_wall();
            }

            else {
                tiles[Tools::coord_2d_to_1d(i, j, w)].set_floor();
            }
        }
    }
}

void GameMap::generate_map() {
    int smallest_room_size = 3;
    bool cont = true;

    while (cont) {
        
    }
}

void GameMap::dig_room(const Room& r) {
    for (size_t i = r.x; i < r.x + r.w; i++) {
        for (size_t j = r.y; j < r.y + r.h; j++) {
            tiles[Tools::coord_2d_to_1d(i, j, w)].set_floor();
        }
    }
}

void GameMap::dig_corridor_between_rooms(const Room& r1, const Room& r2) {

}

Position GameMap::get_closest_center(Position center) {
    Position closest = {9999999, 9999999};
    int smallest_dst = 9999999;

    for (auto& room: rooms) {
        int dst = center.distance(room.get_center());
        if (dst > 0 && dst < smallest_dst) {
            smallest_dst = dst;
            closest = room.get_center();
        }
    }

    return closest;
}