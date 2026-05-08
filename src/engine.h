//
// Created by couland-q on 06/05/2026.
//

#ifndef RAYROG_ENGINE_H
#define RAYROG_ENGINE_H

#include "include_raylib.h"

#include "renderer.h"
#include "gamemap.h"
#include "input_handler.h"
#include "action.h"
#include "entity.h"
#include "event_manager.h"

class Engine {
public:
    Engine();
    ~Engine();

    void init();
    void run();

    void handle_action(Action act);

    Renderer renderer;
    InputHandler input_h;
    EventManager ev_manager;

    Entity player;
    GameMap game_map;
};



#endif //RAYROG_ENGINE_H
