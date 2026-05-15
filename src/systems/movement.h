//
// Created by couland-q on 07/05/2026.
//

#ifndef RAYROG_SYSTEMS_MOVEMENT_H
#define RAYROG_SYSTEMS_MOVEMENT_H

#include <any>

#include "../events/event.h"
#include "../components/position.h"
#include "../events/action.h"

namespace systems {
    namespace movement {
        inline void move(const Event& ev) {
            auto pos = std::any_cast<Position>(ev.target->get_comp<Position>());
            auto mov = static_cast<ActionMovement*>(ev.act);
            pos->x += mov->dx;
            pos->y += mov->dy;
        }
    }
}

#endif