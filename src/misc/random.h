//
// Created by couland-q on 16/05/2026.
//

#ifndef RAYROG_RANDOM_H
#define RAYROG_RANDOM_H

#include <cstdlib>
#include <ctime>

struct Random {

    static void seed() {
        srand(time(nullptr));
    }

    static void seed(const int new_seed) {
        srand(new_seed);
    }


    static int get_int(const int min, const int max) {
        return (rand() % (max - min + 1)) + min;
    }
};

#endif //RAYROG_RANDOM_H
