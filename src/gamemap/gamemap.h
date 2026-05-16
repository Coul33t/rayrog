//
// Created by couland-q on 06/05/2026.
//

#ifndef RAYROG_MAP_H
#define RAYROG_MAP_H

#include <vector>

#include "tile.h"
#include "room.h"
#include "../tools.h"

class GameMap {
public:
    GameMap();
    ~GameMap();

    void init(size_t w, size_t h);
    void test_map();
    void generate_map();

    void dig_room(const Room& r);
    void dig_corridor_between_rooms(const Room& r1, const Room& r2);

    Position get_closest_center(Position center);

    size_t w, h;
    std::vector<Tile> tiles;

    std::vector<Room> rooms;
};



#endif //RAYROG_MAP_H
