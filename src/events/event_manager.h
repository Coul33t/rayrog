//
// Created by couland-q on 08/05/2026.
//

#ifndef RAYROG_EVENT_MANAGER_H
#define RAYROG_EVENT_MANAGER_H

#include "event.h"
#include "action.h"
#include "action_type.h"
#include "../systems/movement.h"
#include "../systems/combat.h"
#include "../entities/entities_manager.h"

class EventManager {
public:
    EventManager();
    ~EventManager();

    void add_event(const Event& event);
    void add_event(Action* act, Entity* target, int priority);

    void clear_event_queue();

    void process_events(EntitiesManager& ent_manager);

    void process_move(EntitiesManager& ent_manager, Event& ev);
    void process_attack(EntitiesManager& ent_manager, Event& ev);
    void process_move_or_attack(EntitiesManager& ent_manager, Event& ev);

    std::vector<Event> events_queue;
};

#endif