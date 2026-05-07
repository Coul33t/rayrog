//
// Created by couland-q on 06/05/2026.
//

#include "engine.h"

#include "input_handler.h"

Engine::Engine() {

}

Engine::~Engine() {

}

void Engine::init() {
    renderer.init();
    game_map.init(20, 40);
    game_map.test_map();
}

void Engine::run() {
    while (!renderer.window_should_close()) {
        BeginDrawing();
        ClearBackground(BLACK);
        renderer.draw_map(game_map);
        Action act = input_h.handle_input();
        handle_action(act);
        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    renderer.close();
}

void Engine::handle_action(Action act) {
    if (act.type == ActionType::MOVE) {

    }
}