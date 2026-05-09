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
    std::vector<std::any> params;
};
#endif //RAYROG_ACTION_H
