#include <raylib.h>
#include <iostream>

#include "player.hpp"

int main() {
    const char* TITLE = "Sokoban!!!";
    const int WIDTH = 1280;
    const int HEIGHT = 720;
    InitWindow(WIDTH, HEIGHT,  TITLE);

    const int FPS = 60;
    SetTargetFPS(FPS);

    Player person(
        (Vector2){200, 500},
        LoadTexture("assets/sprites/player.png")
        );

    if(!IsWindowReady()) {
        std::cout << "Window isn't ready :(" << std::endl;
        return -1;
    }
    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawFPS(0,0);
            person.draw();
        EndDrawing();
    }
    return 0;
}
