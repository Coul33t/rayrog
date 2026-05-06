//
// Created by couland-q on 06/05/2026.
//

#ifndef RAYROG_ENGINE_H
#define RAYROG_ENGINE_H

#include "renderer.h"

class Engine {
public:
    Engine();
    ~Engine();

    void init();
    void run();

    void draw_map();

    Renderer renderer;
};



#endif //RAYROG_ENGINE_H
