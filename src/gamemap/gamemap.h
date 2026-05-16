//
// Created by couland-q on 06/05/2026.
//

#ifndef RAYROG_MAP_H
#define RAYROG_MAP_H

#include <vector>

#include "tile.h"
#include "room.h"
#include "../misc/tools.h"

#include "../components/position.h"

#include "../misc/random.h"

class GameMap {
public:
    GameMap();
    ~GameMap();

    void init(size_t w, size_t h);
    void test_map();
    void generate_map();

    void dig_room(const Room& r);
    void dig_h_corridor(int x1, int x2, int y);
    void dig_v_corridor(int y1, int y2, int x);
    void dig_corridor_between_rooms(const Position& p1, const Position& p2);

    Position get_closest_center(Position center);
    bool check_collisions(const Room& r);

    Position get_center_of_random_room();

    size_t w, h;
    std::vector<Tile> tiles;
    std::vector<Room> rooms;
};



#endif //RAYROG_MAP_H
