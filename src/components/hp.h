//
// Created by couland-q on 08/05/2026.
//

#ifndef RAYROG_HP_H
#define RAYROG_HP_H

struct Hp {
    int hp, max_hp;
    
    Hp() {
        hp = 10;
        max_hp = 10;
    }

    Hp(int init_hp) {
        hp = init_hp;
        max_hp = init_hp;
    }

    Hp(int init_hp, int max_hp) {
        hp = init_hp;
        this->max_hp = max_hp;
    }

    bool is_dead() {
        return (hp <= 0);
    }
};

#endif