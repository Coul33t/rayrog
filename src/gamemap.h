//
// Created by couland-q on 06/05/2026.
//

#ifndef RAYROG_MAP_H
#define RAYROG_MAP_H

#include <vector>

#include "tile.h"
#include "tools.h"

class GameMap {
public:
    GameMap();
    ~GameMap();

    void init(size_t w, size_t h);
    void test_map();

    size_t w, h;
    std::vector<Tile> tiles;
};



#endif //RAYROG_MAP_H
