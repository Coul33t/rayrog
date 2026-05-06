//
// Created by couland-q on 06/05/2026.
//

#ifndef RAYROG_MAP_H
#define RAYROG_MAP_H

#include <vector>

#include "tile.h"

class Map {
public:
    Map();
    ~Map();

    void init();

    std::vector<Tile> tiles;
};



#endif //RAYROG_MAP_H
