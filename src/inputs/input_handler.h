//
// Created by couland-q on 07/05/2026.
//

#ifndef RAYROG_INPUT_HANDLER_H
#define RAYROG_INPUT_HANDLER_H

#include "../kraylib/kraylib.h"

#include "../events/action.h"
#include "../events/event.h"


class InputHandler {
public:
    InputHandler();
    ~InputHandler();

    Action* handle_input();
};



#endif //RAYROG_INPUT_HANDLER_H
