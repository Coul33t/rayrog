#ifndef RAYROG_ENTITIES_MANAGER_H
#define RAYROG_ENTITIES_MANAGER_H

#include <vector>

#include "entity.h"

#include "../components/tags.h"

class EntitiesManager {
public:
    EntitiesManager();
    ~EntitiesManager();

    void add_entity(const Entity& ent);

    std::vector<Entity*> get_entities_with_tag(const Tag& tag);
    Entity* get_first_entity_with_tag(const Tag& tag);

    // *In theory*, should never return nullptr (for now)
    Entity* get_player();

    Entity* get_entity_at(Position pos);
    bool has_entity_at(Position pos);

    std::vector<Entity> entities;
    Entity* player;
};

#endif