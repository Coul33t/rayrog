//
// Created by couland-q on 08/05/2026.
//

#ifndef RAYROG_EVENT_MANAGER_H
#define RAYROG_EVENT_MANAGER_H

#include "event.h"
#include "action.h"
#include "action_type.h"
#include "../systems/movement.h"
#include "../entities/entities_manager.h"

class EventManager {
public:
    EventManager();
    ~EventManager();

    void add_event(const Event& event);
    void add_event(const Action& act, Entity* target, int priority);

    void process_events(EntitiesManager& ent_manager);

    std::vector<Event> events_queue;
};

#endif