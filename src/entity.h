//
// Created by couland-q on 07/05/2026.
//

#ifndef RAYROG_ENTITY_H
#define RAYROG_ENTITY_H

#include <vector>
#include <any>
#include <cstdarg>
#include <algorithm>

#include "components/position.h"
#include "tags.h"

class Entity {
public:
    Entity();
    Entity(int x, int y);
    ~Entity();

    template<typename... Args>
    void add_tag(int nb_tags, const Args&... tags);
    bool has_tag(const Tag& tag);
    std::any get_comp(const Tag& tag);

    Position pos;
    std::vector<Tag> tags;
    std::vector<std::any> comps;
};



#endif //RAYROG_ENTITY_H
