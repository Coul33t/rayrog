//
// Created by couland-q on 07/05/2026.
//

#include "input_handler.h"


InputHandler::InputHandler() {

}

InputHandler::~InputHandler() {

}

Action* InputHandler::handle_input() {
    Action* act;

    if (IsKeyPressed(KEY_W)) {
        act = new ActionMovement(0, -1);
        act->next_turn = true;
    }

    else if (IsKeyPressed(KEY_A)) {
        act = new ActionMovement(-1, 0);
        act->next_turn = true;
    }

    else if (IsKeyPressed(KEY_S)) {
        act = new ActionMovement(0, 1);
        act->next_turn = true;
    }

    else if (IsKeyPressed(KEY_D)) {
        act = new ActionMovement(1, 0);
        act->next_turn = true;
    }

    else {
        act = new ActionNone();
    }

    return act;
}