//
// Created by couland-q on 06/05/2026.
//

#include "gamemap.h"

#include <iostream>

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
    int min_room_size = 3;
    int max_room_size = 10;
    bool first = true;
    int succ_fails = 0;
    int max_fails = 30;

    while (succ_fails < max_fails) {
        int x = RandomGenerator::get_int(0, w);
        int y = Random::get_int(0, h);
        int w = Random::get_int(min_room_size, max_room_size);
        int h = Random::get_int(min_room_size, max_room_size);

        Room r(x, y, w, h);

        if(check_collisions(r)) {
            succ_fails++;
            std::cout << "Failed (" << succ_fails << "/" << max_fails << ")" << std::endl;
        } 
        
        else {
            std::cout << "Successful" << std::endl;
            rooms.emplace_back(r);
            dig_room(r);
            if (!first) {
                dig_corridor_between_rooms(r.get_center(), get_closest_center(r.get_center()));
            }

            else {
                first = false;
            }

            succ_fails = 0;   
        }
    }
}

void GameMap::dig_room(const Room& r) {
    for (size_t i = r.x; i < r.x + r.w; i++) {
        for (size_t j = r.y; j < r.y + r.h; j++) {
            tiles[Tools::coord_2d_to_1d(i, j, w)].set_floor();
        }
    }
}

void GameMap::dig_h_corridor(int x1, int x2, int y) {
    for (size_t i = x1; i < x2; i++) {
        tiles[Tools::coord_2d_to_1d(i, y, w)].set_floor();
    }
}

void GameMap::dig_v_corridor(int y1, int y2, int x) {
    for (size_t j = y1; j < y2; j++) {
        tiles[Tools::coord_2d_to_1d(x, j, w)].set_floor();
    }
}

void GameMap::dig_corridor_between_rooms(const Position& p1, const Position& p2) {
    if(Random::get_int(1, 2) == 1) {
        dig_h_corridor(p1.x, p2.x, p1.y);
        dig_v_corridor(p1.y, p2.y, p1.x);
    }

    else {
        dig_v_corridor(p1.y, p2.y, p1.x);
        dig_h_corridor(p1.x, p2.x, p1.y);
    }
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

bool GameMap::check_collisions(const Room& r) {
    for (auto& room: rooms) {
        if (CheckCollisionRecs(r.get_raylib_rect(), room.get_raylib_rect())) {
            return true;
        }
    }

    return false;
}

Position GameMap::get_center_of_random_room() {
    int idx = Random::get_int(0, rooms.size() - 1);
    return rooms[idx].get_center();
}