//
// Created by couland-q on 06/05/2026.
//

#include "engine.h"

Engine::Engine() {

}

Engine::~Engine() {

}

void Engine::init() {
    renderer.init();
}

void Engine::run() {
    while (!renderer.window_should_close()) {
        BeginDrawing();
        ClearBackground(BLACK);
        draw_map();
        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    renderer.close();
}

void Engine::draw_map() {
    int x1 = 24;
    int x2 = 24*15;
    int y1 = 24;
    int y2 = 24*10;
    for (size_t i = 0; i < 15; i++) {
        renderer.draw_tile("wall", {x1 + (int)(24*i), y1});
        renderer.draw_tile("wall", {x1 + (int)(24*i), y2});
    }

    for (size_t i = 0; i < 10; i++) {
        renderer.draw_tile("wall", {x1, y1 + (int)(24*i)});
        renderer.draw_tile("wall", {x2, y1 + (int)(24*i)});
    }
}
