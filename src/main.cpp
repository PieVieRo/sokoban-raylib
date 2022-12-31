#include <raylib.h>
#include <iostream>

int main() {
    const char* TITLE = "Sokoban!!!";
    const int WIDTH = 1280;
    const int HEIGHT = 720;
    InitWindow(WIDTH, HEIGHT,  TITLE);

    Texture2D person = LoadTexture("assets/sprites/player.png");
    const int FPS = 60;
    SetTargetFPS(FPS);

    if(!IsWindowReady()) {
        std::cout << "Window isn't ready :(" << std::endl;
        return -1;
    }
    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawFPS(0,0);
            DrawCircleGradient(400, 300, 20, GOLD, DARKPURPLE);
            DrawTexture(person, 200, 500, WHITE);
            DrawText("Hello World", WIDTH / 2 - 5, HEIGHT / 2 - 15, 30, BLACK);
        EndDrawing();
    }
    return 0;
}
