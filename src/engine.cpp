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
    while (!renderer.windowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    renderer.close();
}
