//
// Created by couland-q on 09/05/2026.
//

#ifndef RAYROG_GRAPHICS_H
#define RAYROG_GRAPHICS_H

#include <string>

#include "component.h"

struct Graphics: public Component {
    std::string name;

    Graphics() {

    }

    Graphics(const std::string& name) : name(name) {

    }
};

#endif //RAYROG_GRAPHICS_H
