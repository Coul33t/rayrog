//
// Created by couland-q on 07/05/2026.
//

#ifndef RAYROG_ENTITY_H
#define RAYROG_ENTITY_H

#include <vector>
#include <any>
#include <cstdarg>
#include <algorithm>
#include "../components/component.h"

#include "../components/position.h"
#include "../components/tags.h"

class Entity {
public:
    Entity();
    ~Entity();

    template<typename... Args>
    void add_tag(const Args&... tags);
    template<typename... Args>
    void add_comp(const Args&... comp);

    bool has_tag(const Tag& tag) const;
    template<typename T>
    std::any* get_comp();

    std::vector<Tag> tags;
    std::vector<std::any> comps;
};

template<typename... Args>
void Entity::add_tag(const Args&... tags_to_add) {
    (tags.emplace_back(tags_to_add), ...);
}

template<typename... Args>
void Entity::add_comp(const Args&... comps_to_add) {
    // Checks if we're really adding a Component (since type is std::any)
    //if (std::is_base_of_v<Component, comp.type()>) {
    (comps.emplace_back(comps_to_add), ...);
    //}
}

template<typename T>
std::any* Entity::get_comp() {
    for (auto& comp: comps) {
        if (typeid(T) == comp.type()) {
            return &comp;
        }
    }

    return {};
}


#endif //RAYROG_ENTITY_H
