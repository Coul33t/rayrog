#ifndef RAYROG_GAMEMAP_ROOM_H
#define RAYROG_GAMEMAP_ROOM_H

#include <cmath>

#include "../kraylib/kraylib.h"

#include "../components/position.h"

struct Room {
    int x, y, w, h;

    Room(int x, int y, int w, int h): x(x), y(y), w(w), h(h) {

    }

    Position get_center() const {
        return {static_cast<int>(floor((x + w) / 2)),
                static_cast<int>(floor((y + h) / 2))};
    }

    Rectangle get_raylib_rect() const {
        return {(float)x, (float)y, (float)w, (float)h};
    }
};

#endif