#include <raylib.h>
#include <raymath.h>
#include <iostream>


#include "player.hpp"

int main() {
    const char* TITLE = "Sokoban!!!";
    const int WIDTH = 640;  // all sprites are 64x64
    const int HEIGHT = 640;
    InitWindow(WIDTH, HEIGHT,  TITLE);

    const int FPS = 60;
    SetTargetFPS(FPS);
    Player person(
        (Vector2){0, 0},
        LoadTexture("assets/sprites/player.png")
        );

    if(!IsWindowReady()) {
        std::cout << "Window isn't ready :(" << std::endl;
        return -1;
    }
    while(!WindowShouldClose()) {
        // Drawing
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawFPS(0,0);
            person.draw();
        EndDrawing();
        // Physics and stuff idk
        person.move();
    }
    return 0;
}
