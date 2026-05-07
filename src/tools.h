//
// Created by Kontin on 07/05/2026.
//

#ifndef RAYROG_TOOLS_H
#define RAYROG_TOOLS_H

#include "raylib.h"

namespace Tools {
    Rectangle get_rect(Vector2 pos, Vector2 size);
    int coord_2d_to_1d(int x, int y);
};


#endif //RAYROG_TOOLS_H
