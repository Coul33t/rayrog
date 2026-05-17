//
// Created by Kontin on 07/05/2026.
//

#ifndef RAYROG_TOOLS_H
#define RAYROG_TOOLS_H

#include "raylib.h"

#include "../../extlib/random/random.hpp"

/*namespace Random {
    using EffoRandom = effolkronium::random_static;
    int get_int(int lower, int higher, int seed=7);
}*/

namespace Tools {
    Rectangle get_rect(Vector2 pos, Vector2 size);
    int coord_2d_to_1d(int x, int y, int w);
};


#endif //RAYROG_TOOLS_H
