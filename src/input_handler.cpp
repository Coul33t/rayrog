//
// Created by couland-q on 07/05/2026.
//

#include "input_handler.h"


InputHandler::InputHandler() {

}

InputHandler::~InputHandler() {

}

Action InputHandler::handle_input() {
    Action act;

    int key = raylib::GetKeyPressed();

    if (key == raylib::KEY_Z) {
        act.type = ActionType::MOVE;
        act.params = {0, -1};
    }

    else if (key == raylib::KEY_Q) {
        act.type = ActionType::MOVE;
        act.params = {-1, 0};
    }

    else if (key == raylib::KEY_S) {
        act.type = ActionType::MOVE;
        act.params = {0, 1};
    }

    else if (key == raylib::KEY_D) {
        act.type = ActionType::MOVE;
        act.params = {1, 0};
    }

    return act;
}