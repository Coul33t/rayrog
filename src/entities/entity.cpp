//
// Created by couland-q on 07/05/2026.
//

#include "entity.h"

Entity::Entity() {

}

Entity::~Entity() {

}

bool Entity::has_tag(const Tag& tag) {
    const auto it = std::find(tags.begin(), tags.end(), tag);
    return (it != tags.end());
}