//
// Created by couland-q on 07/05/2026.
//

#include "input_handler.h"

#include "raylib.h"


InputHandler::InputHandler() {

}

InputHandler::~InputHandler() {

}

Action InputHandler::handle_input() {
    Action act;

    int key = GetKeyPressed();

    if (key == KEY_Z) {
        act.type = ActionType::MOVE;
        act.params = {0, -1};
    }

    else if (key == KEY_Q) {
        act.type = ActionType::MOVE;
        act.params = {-1, 0};
    }

    else if (key == KEY_S) {
        act.type = ActionType::MOVE;
        act.params = {0, 1};
    }

    else if (key == KEY_D) {
        act.type = ActionType::MOVE;
        act.params = {1, 0};
    }

    return act;
}