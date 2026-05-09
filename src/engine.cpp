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
    game_map.init(20, 40);
    game_map.test_map();
    player = entities_factory::get_player(1, 1);
    for (size_t i = 0; i < 5; i++) {
        entities.emplace_back(entities_factory::get_basic_monster(2 + i, 2));
    }
}

void Engine::run() {
    while (!renderer.window_should_close()) {
        BeginDrawing();
        ClearBackground(BLACK);
        renderer.render_all(game_map, player, entities);
        Action act = input_h.handle_input();
        ev_manager.add_event(act, &player, 0);
        ev_manager.process_events();
        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    renderer.close();
}

void Engine::handle_action(Action act) {
    if (act.type == ActionType::MOVE) {

    }
}