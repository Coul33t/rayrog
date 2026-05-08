//
// Created by couland-q on 07/05/2026.
//

#ifndef RAYROG_ENTITY_H
#define RAYROG_ENTITY_H

#include <vector>
#include <any>

#include "raylib.h"

#include "components/position.h"
#include "tags.h"

class Entity {
public:
    Entity();
    Entity(int x, int y);
    ~Entity();

    void move(int dx, int dy);
    void move(std::vector<std::any> dd);
    void move(raylib::Vector2 dd);

    bool has_tag(const Tag& tag);

    Position pos;
    std::vector<Tag> tags;
};



#endif //RAYROG_ENTITY_H
