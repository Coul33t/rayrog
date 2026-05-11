#include "entities_manager.h"

EntitiesManager::EntitiesManager() {
    player = nullptr;
}

EntitiesManager::~EntitiesManager() {

}


void EntitiesManager::add_entity(const Entity& ent) {
    entities.emplace_back(ent);
}

std::vector<Entity*> EntitiesManager::get_entities_with_tag(const Tag& tag) {
    std::vector<Entity*> r_ents;

    for (auto& ent: entities) {
        if (ent.has_tag(tag)) {
            r_ents.push_back(&ent);
        }
    }

    return r_ents;
}

Entity* EntitiesManager::get_first_entity_with_tag(const Tag& tag) {
    for (auto& ent: entities) {
        if (ent.has_tag(tag)) {
            return &ent;
        }
    }

    return nullptr;
}

Entity* EntitiesManager::get_player() {
    for (auto& ent: entities) {
        if (ent.has_tag(Tag::PLAYER)) {
            return &ent;
        }
    }

    return nullptr;
}