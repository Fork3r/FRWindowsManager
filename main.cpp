//
// Created by rsalogub on 27.11.19.
//

#include "window.h"

int main()
{
    FRWindows::Window window(800, 600, "window");
    while (true) {
        FRWindows::EventHandler::processEvents();
    }
    return 0;
}