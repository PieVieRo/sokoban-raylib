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
            LoadTexture("assets/images/player.png"),
            (Vector2){2,2}
            );

    Level level(
            [ 1,1,1,1,1,1,1,1,1,1,
              1,0,0,0,0,0,0,0,0,1,
              1,0,0,0,0,0,0,0,0,1,
              1,0,0,0,0,0,0,0,0,1,
              1,0,0,0,0,0,0,0,0,1,
              1,0,0,0,0,0,0,0,0,1,
              1,0,0,0,0,0,0,0,0,1,
              1,0,0,0,0,0,0,0,0,1,
              1,1,0,0,0,0,0,0,0,1,
              1,1,1,1,1,1,1,1,1,1 ]
            )

        std::map<int, Texture2D> textures{
            {1, LoadTexture("assets/images/wall.png")}
        };

    while(!WindowShouldClose()) {
        // Drawing
        BeginDrawing();
            player.draw();

            DrawFPS(0,0);

        EndDrawing();
        // Physics and stuff idk
        player.move(&level);

    }
    return 0;
}
