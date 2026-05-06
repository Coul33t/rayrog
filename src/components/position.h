//
// Created by couland-q on 06/05/2026.
//

#ifndef RAYROG_POSITION_H
#define RAYROG_POSITION_H

struct Position {
    int x, y;

    Position() {
        x = 0;
        y = 0;
    }

    Position(int x, int y): x(x), y(y) {

    }
};
#endif //RAYROG_POSITION_H
