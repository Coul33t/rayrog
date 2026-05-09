//
// Created by couland-q on 06/05/2026.
//

#ifndef RAYROG_TIL_H
#define RAYROG_TIL_H

#include "tiletype.h"

struct Tile {
    Tiletype type;
    bool walkable, transparent;

    Tile() {
        type = Tiletype::NONE;
        walkable = false;
        transparent = false;
    }

    Tile(bool w, bool t) {
        walkable = w;
        transparent = t;
        type = Tiletype::NONE;
    }

    Tile(Tiletype tt, bool w, bool t) {
        type = tt;
        walkable = w;
        transparent = t;
    }

    void set_wall() {
        type = Tiletype::WALL;
        walkable = false;
        transparent = false;
    }

    void set_floor() {
        type = Tiletype::FLOOR;
        walkable = true;
        transparent = true;
    }
};

#endif //RAYROG_TIL_H
