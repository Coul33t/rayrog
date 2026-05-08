//
// Created by couland-q on 08/05/2026.
//

#ifndef RAYROG_ENTITIES_FACTORY_H
#define RAYROG_ENTITIES_FACTORY_H

#include "entity.h"
#include "tags.h"

namespace entities_factory {
    Entity get_player() {
        Entity player;
        player.add_tag(Tag::PLAYER);
        return player;
    }

    Entity get_basic_monster() {

    }
}

#endif