#include "event_manager.h"

EventManager::EventManager() {

}

EventManager::~EventManager() {

}

void EventManager::add_event(const Event& event) {
    events_queue.emplace_back(event);
}

void EventManager::add_event(Action* act, Entity* target, int priority) {
    events_queue.emplace_back(Event{act, target, priority});
}

void EventManager::clear_event_queue() {
    for (auto ev: events_queue) {
        delete ev.act;
    }

    events_queue.clear();
}

void EventManager::process_events(EntitiesManager& ent_manager) {
    for (auto ev: events_queue) {
        if (ev.act->type == ActionType::MOVE) {
            if (ev.target->has_tag(Tag::MOVEABLE)) {
                process_move_or_attack(ent_manager, ev);
            }
        }
    }

    events_queue.clear();
}

void EventManager::process_move(EntitiesManager& ent_manager, Event& ev) {
    auto pos = std::any_cast<Position>(ev.target->get_comp<Position>());
    auto mov = static_cast<ActionMovement*>(ev.act);
    Entity* ent = ent_manager.get_entity_at({pos->x + mov->dx, pos->y + mov->dy});
    
    if (!ent) {
        systems::movement::move(ev);
    } 
}

void EventManager::process_attack(EntitiesManager& ent_manager, Event& ev) {
    auto pos = std::any_cast<Position>(ev.target->get_comp<Position>());
    auto mov = static_cast<ActionMovement*>(ev.act);
    Entity* ent = ent_manager.get_entity_at({pos->x + mov->dx, pos->y + mov->dy});
    
    if (ent) {
        systems::combat::attack(ev);
    } 
}

void EventManager::process_move_or_attack(EntitiesManager& ent_manager, Event& ev) {
    auto pos = std::any_cast<Position>(ev.target->get_comp<Position>());
    auto mov = static_cast<ActionMovement*>(ev.act);
    Entity* ent = ent_manager.get_entity_at({pos->x + mov->dx, pos->y + mov->dy});
    
    if (!ent) {
        systems::movement::move(ev);
    } else {
        if (ent->has_tag(Tag::HP)) {
            systems::combat::take_damage(ev);
        }
    }
}