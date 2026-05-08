#include "event_manager.h"
#include "action_type.h"

EventManager::EventManager() {

}
 EventManager::~EventManager() {

}

void EventManager::add_event(const Event& event) {
    events_queue.emplace_back(event);
}

void EventManager::add_event(const Action& act, Entity* target, int priority) {
    events_queue.emplace_back({act, target, priority});
}

void EventManager::process_events() {
    for (auto ev: events_queue) {
        if (ev.act.type == ActionType::MOVE) {
            if (ev.target.has_tag(Tag::MOVEABLE)) {
                ev.target.move(ev.act.params);
            }
        }
    }
}