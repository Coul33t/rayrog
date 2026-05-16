#ifndef RAYROG_GAMEMAP_ROOM_H
#define RAYROG_GAMEMAP_ROOM_H

#include <cmath>

#include "../kraylib/kraylib.h"

struct Room {
    int x, y, w, h;

    Room(int x, int y, int w, int h): x(x), y(y), w(w), h(h) {

    }

    Position get_center() {
        return ({floor((x + w) / 2),
                 floor((y + h) / 2)});
    }
};

#endif