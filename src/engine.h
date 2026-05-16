//
// Created by couland-q on 06/05/2026.
//

#ifndef RAYROG_ENGINE_H
#define RAYROG_ENGINE_H

#include "kraylib/kraylib.h"

#include "rendering/renderer.h"
#include "gamemap/gamemap.h"
#include "inputs/input_handler.h"
#include "events/action.h"
#include "entities/entities_manager.h"
#include "events/event_manager.h"
#include "entities/entities_factory.h"
#include "misc/random.h"

class Engine {
public:
    Engine();
    ~Engine();

    void init();
    void run();

    Renderer renderer;
    InputHandler input_h;
    EventManager ev_manager;

    RandomGenerator r_gen;
    EntitiesManager ent_manager;
    GameMap game_map;
};



#endif //RAYROG_ENGINE_H
