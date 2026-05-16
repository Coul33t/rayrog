//
// Created by couland-q on 06/05/2026.
//

#include "engine.h"

#include "inputs/input_handler.h"

Engine::Engine() {

}

Engine::~Engine() {

}

void Engine::init() {
    renderer.init();
    game_map.init(20, 30);
    game_map.generate_map();
    ent_manager.add_entity(entities_factory::get_player(game_map.get_center_of_random_room()));
    /*for (size_t i = 0; i < 5; i++) {
        ent_manager.add_entity(entities_factory::get_basic_monster(2 + i, 2));
    }*/
}

void Engine::run() {
    while (!renderer.window_should_close()) {
        kraylib::begin_drawing();
        kraylib::clear_background(BLACK);
        renderer.render_all(game_map, ent_manager);
        Action* act = input_h.handle_input();
        ev_manager.add_event(act, ent_manager.get_player(), 0);
        ev_manager.process_events(ent_manager);
        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        kraylib::end_drawing();
    }

    renderer.close();
}