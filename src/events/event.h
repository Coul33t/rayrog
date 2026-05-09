//
// Created by couland-q on 08/05/2026.
//

#ifndef RAYROG_EVENT_H
#define RAYROG_EVENT_H

#include "action.h"
#include "../entities/entity.h"

struct Event {
    Action act;
    Entity* target;
    int priority;
};

#endif