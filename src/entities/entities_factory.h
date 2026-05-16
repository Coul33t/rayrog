//
// Created by couland-q on 08/05/2026.
//

#ifndef RAYROG_ENTITIES_FACTORY_H
#define RAYROG_ENTITIES_FACTORY_H

#include "entity.h"
#include "../components/tags.h"
#include "../components/position.h"
#include "../components/graphics.h"
#include "../components/combat.h"
#include "../components/hp.h"
#include "../components/fov.h"

namespace entities_factory {
    inline Entity get_player() {
        Entity player;
        player.add_tag(Tag::PLAYER, Tag::MOVEABLE, Tag::ATTACK, Tag::HP, Tag::RENDER);
        player.add_comp(Position{0, 0}, Hp(10), Combat(5), Fov(10, FovShape::LOSANGE), Graphics("player"));
        return player;
    }

    inline Entity get_player(const int x, const int y) {
        Entity player;
        player.add_tag(Tag::PLAYER, Tag::MOVEABLE, Tag::ATTACK, Tag::HP, Tag::RENDER);
        player.add_comp(Position{x, y}, Hp(10), Combat(5), Fov(10, FovShape::LOSANGE), Graphics("player"));
        return player;
    }

    inline Entity get_basic_monster() {
        Entity monster;
        monster.add_tag(Tag::MONSTER, Tag::MOVEABLE, Tag::ATTACK, Tag::HP, Tag::RENDER);
        monster.add_comp(Position{5, 5}, Hp(10), Combat(1), Fov(8, FovShape::LOSANGE), Graphics("monster"));
        return monster;
    }

    inline Entity get_basic_monster(const int x, const int y) {
        Entity monster;
        monster.add_tag(Tag::MONSTER, Tag::MOVEABLE, Tag::ATTACK, Tag::HP, Tag::RENDER);
        monster.add_comp(Position{x, y}, Hp(10), Combat(1), Fov(8, FovShape::LOSANGE) Graphics("monster"));
        return monster;
    }
}

#endif