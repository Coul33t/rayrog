//
// Created by couland-q on 07/05/2026.
//

#ifndef RAYROG_SYSTEMS_MOVEMENT_H
#define RAYROG_SYSTEMS_MOVEMENT_H

#include "../include_raylib.h"

#include "../event.h"

namespace systems {
    void move(const Event& ev) {
        move(ev.target, ev.act.params);
    }

    void move(Entity& e, int dx, int dy) {
        e.pos.x += dx;
        e.pos.y += dy;
    }

    void move(Entity& e, std::vector<std::any> dd) {
        move(std::any_cast<int>(dd[0]), std::any_cast<int>(dd[1]));
    }

    void move(Entity& e, raylib::Vector2 dd) {
        move(dd.x, dd.y);
    }
}

#endif