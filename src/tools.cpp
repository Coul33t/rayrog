//
// Created by Kontin on 07/05/2026.
//

#include "tools.h"

namespace Tools {
    Rectangle get_rect(Vector2 pos, Vector2 size) {
        return {pos.x, pos.y, size.x, size.y};
    }
}