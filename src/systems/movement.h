//
// Created by couland-q on 07/05/2026.
//

#ifndef RAYROG_SYSTEMS_MOVEMENT_H
#define RAYROG_SYSTEMS_MOVEMENT_H

#include <any>

#include "../events/event.h"
#include "../components/position.h"

namespace systems {
    inline void move(const Event& ev) {
        auto pos = std::any_cast<Position>(ev.target->get_comp<Position>());
        pos->x += std::any_cast<int>(ev.act.params[0]);
        pos->y += std::any_cast<int>(ev.act.params[1]);
    }
}

#endif