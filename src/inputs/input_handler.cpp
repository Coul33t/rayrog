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
    act.type = ActionType::NONE;

    if (IsKeyPressed(KEY_W)) {
        act.type = ActionType::MOVE;
        act.params = {0, -1};
    }

    else if (IsKeyPressed(KEY_A)) {
        act.type = ActionType::MOVE;
        act.params = {-1, 0};
    }

    else if (IsKeyPressed(KEY_S)) {
        act.type = ActionType::MOVE;
        act.params = {0, 1};
    }

    else if (IsKeyPressed(KEY_D)) {
        act.type = ActionType::MOVE;
        act.params = {1, 0};
    }

    return act;
}