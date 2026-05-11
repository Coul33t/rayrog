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

    Entity* get_player();

    std::vector<Entity> entities;
    Entity* player;
};

#endif