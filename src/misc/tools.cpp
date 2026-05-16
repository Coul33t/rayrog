//
// Created by Kontin on 07/05/2026.
//

#include "tools.h"

namespace Random {
    int get_int(int min, int max, int seed) {
        if (seed != -1) {
            EffoRandom::seed(seed);
        }

        if (min == max) {
            return min;
        }    

        if (min > max) {
            std::swap(min, max);
        }
            
        return EffoRandom::get(min, max);
    }
}

namespace Tools {
    Rectangle get_rect(Vector2 pos, Vector2 size) {
        return {pos.x, pos.y, size.x, size.y};
    }

    int coord_2d_to_1d(int x, int y, int w) {
        return y*w + x;
    }
}
