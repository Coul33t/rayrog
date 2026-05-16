//
// Created by couland-q on 16/05/2026.
//

#ifndef RAYROG_RANDOM_H
#define RAYROG_RANDOM_H

#include <cstdlib>
#include <ctime>

class RandomGenerator {
public:
    RandomGenerator() {
        seed = time(0);
        srand(seed);
    }

    explicit RandomGenerator(const int seed): seed(seed) {
        srand(seed);
    }

    ~RandomGenerator() {

    }

    void reseed(const int new_seed) {
        seed = new_seed;
        srand(seed);
    }

    static int get_int(const int min, const int max) {
        return (rand() % (max - min + 1)) + min;
    }

    // For debugging purposes I guess
    int seed;
};

#endif //RAYROG_RANDOM_H
