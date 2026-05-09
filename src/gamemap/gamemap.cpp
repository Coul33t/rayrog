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
