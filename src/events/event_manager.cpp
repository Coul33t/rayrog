#include "event_manager.h"

EventManager::EventManager() {

}

EventManager::~EventManager() {

}

void EventManager::add_event(const Event& event) {
    events_queue.emplace_back(event);
}

void EventManager::add_event(const Action& act, Entity* target, int priority) {
    events_queue.emplace_back(Event{act, target, priority});
}

void EventManager::process_events(EntitiesManager& ent_manager) {
    for (auto ev: events_queue) {
        if (ev.act.type == ActionType::MOVE) {
            if (ev.target->has_tag(Tag::MOVEABLE)) {
                auto pos = std::any_cast<Position>(ev.target->get_comp<Position>());
                Position target_tile;
                target_tile.x = pos->x + std::any_cast<int>(ev.act.params[0]);
                target_tile.y = pos->y + std::any_cast<int>(ev.act.params[1]);
                if (!ent_manager.has_entity_at(target_tile)) {
                    systems::move(ev);
                } 
            }
        }
    }

    events_queue.clear();
}