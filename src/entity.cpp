//
// Created by couland-q on 07/05/2026.
//

#include "entity.h"

Entity::Entity() {

}

Entity::Entity(int x, int y) {
    pos.x = x;
    pos.y = y;
}

Entity::~Entity() {

}

void Entity::move(int dx, int dy) {
    pos.x += dx;
    pos.y += dy;
}

void Entity::move(std::vector<std::any> dd) {
    move(std::any_cast<int>(dd[0]), std::any_cast<int>(dd[1]));
}

void Entity::move(Vector2 dd) {
    move(dd.x, dd.y);
}
