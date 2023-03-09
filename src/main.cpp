#include <raylib.h>
#include <raymath.h>

#include <iostream>
#include <map>

#include "player.hpp"
#include "level.hpp"

int main() {
    const char* TITLE = "Sokoban!!!";
    const int WIDTH = 640;  // all sprites are 64x64
    const int HEIGHT = 640;
    InitWindow(WIDTH, HEIGHT, TITLE);

    const int FPS = 60;
    SetTargetFPS(FPS);

    if(!IsWindowReady()) {
        std::cout << "Window isn't ready :(" << std::endl;
        return -1;
    }

    Player player(
            LoadTexture("assets/sprites/player.png"),
            (Vector2){2,2}
            );

   int levelArr[100] =
            { 1,1,1,1,1,1,1,1,1,1,
              1,0,0,0,0,0,0,0,0,1,
              1,0,0,0,0,0,0,0,0,1,
              1,0,0,0,0,0,0,0,0,1,
              1,0,0,0,0,0,0,0,0,1,
              1,0,0,0,0,0,0,0,0,1,
              1,0,0,0,0,0,0,0,0,1,
              1,0,0,0,0,0,0,0,0,1,
              1,1,0,0,0,0,0,0,0,1,
              1,1,1,1,1,1,1,1,1,1 };

    Level level(levelArr);

        std::map<int, Texture2D> textures{
            {1, LoadTexture("assets/sprites/wall.png")}
        };

    while(!WindowShouldClose()) {
        // Drawing
        BeginDrawing();
            level.draw(textures);
            player.draw();

            DrawFPS(0,0);

        EndDrawing();
        // Physics and stuff idk
        player.move(&level);

    }
    return 0;
}
