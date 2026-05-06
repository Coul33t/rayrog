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

    Position(const int x, const int y): x(x), y(y) {

    }

    Vector2 as_vec2() const {
        return Vector2{static_cast<float>(x), static_cast<float>(y)};
    }

    bool operator==(const Position& rhs) const {
        return (this->x == rhs.x) && (this->y == rhs.y);
    }

    bool operator!=(const Position& rhs) const {
        return !((this->x == rhs.x) && (this->y == rhs.y));
    }
};
#endif //RAYROG_POSITION_H
