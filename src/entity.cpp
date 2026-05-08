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

template<typename... Args>
void Entity::add_tag(int nb_tags, const Args&... tags_to_add) {
    (tags.emplace_back(tags_to_add), ...);
}

bool Entity::has_tag(const Tag& tag) {
    const auto it = std::find(tags.begin(), tags.end(), tag);
    return (it != tags.end());
}
