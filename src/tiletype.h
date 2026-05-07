//
// Created by Kontin on 06/05/2026.
//

#ifndef RAYROG_TILETYPE_H
#define RAYROG_TILETYPE_H

#include <string>

enum class Tiletype {
    NONE,
    WALL,
    FLOOR
};

inline std::string tiletype_to_str(const Tiletype& tt) {
    std::string tt_str;

    if (tt == Tiletype::WALL) {
        tt_str = "wall";
    } else if (tt == Tiletype::FLOOR) {
        tt_str = "floor";
    } else {
        tt_str = "none";
    }

    return tt_str;
}
#endif //RAYROG_TILETYPE_H
