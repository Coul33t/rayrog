#ifndef RAYROG_COMBAT_H
#define RAYROG_COMBAT_H

struct Combat: public Component {
    int dmg;

    Combat() {

    }

    Combat(int dmg): dmg(dmg) {
        
    }
};

#endif