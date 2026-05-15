//
// Created by couland-q on 07/05/2026.
//

#ifndef RAYROG_ACTION_H
#define RAYROG_ACTION_H

#include <vector>
#include <any>

#include "action_type.h"

struct Action {
    ActionType type;
    bool next_turn = false;
};

struct ActionNone: Action {
    ActionNone() {
        type = ActionType::NONE;
    }
};

struct ActionMovement: Action {
    int dx, dy;

    ActionMovement(int dx, int dy): dx(dx), dy(dy) {
        type = ActionType::MOVE;
    }
};

struct ActionAttack: Action {
    int dmg;

    ActionAttack(int dmg): dmg(dmg) {
        type = ActionType::ATTACK;
    }
};
#endif //RAYROG_ACTION_H
