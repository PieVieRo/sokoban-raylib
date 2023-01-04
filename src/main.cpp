#include <raylib.h>
#include <raymath.h>

#include <iostream>
#include <any>
#include <map>

#include "player.hpp"
#include "block.hpp"

std::map<short, std::any> block_ids = {};

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
            (Vector2){0,0},
            LoadTexture("assets/sprites/player.png")
            );
    Block wall(LoadTexture("assets/sprites/wall.png"));

    block_ids = {
        {32678, &player},
        {1, &wall},
    };

    Texture2D ground = LoadTexture("assets/sprites/ground.png");

    int test_level[10][10] {
        1, 1,     1, 1, 1, 1, 1, 1, 1, 1,
        1, 0,     0, 0, 0, 0, 0, 0, 0, 1,
        1, 1,     0, 0, 0, 0, 0, 0, 0, 1,
        1, 0,     0, 0, 0, 0, 0, 0, 0, 1,
        1, 32678, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0,     0, 0, 0, 0, 0, 0, 0, 1,
        1, 0,     0, 0, 0, 0, 0, 0, 0, 1,
        1, 0,     0, 0, 0, 0, 0, 0, 0, 1,
        1, 0,     0, 0, 0, 0, 0, 0, 0, 1,
        1, 1,     1, 1, 1, 1, 1, 1, 1, 1,
    };


    while(!WindowShouldClose()) {
        // Drawing
        BeginDrawing();
            for(int y=0; y<10; y++) {
                for(int x=0; x<10; x++) {
                    DrawTexture(ground, 64*x, 64*y, WHITE);
                    if(test_level[y][x]) {
                        if(test_level[y][x] &     1) std::any_cast<Block*>(block_ids[test_level[y][x]])->draw(x,y);
                        if(test_level[y][x] & 32678) std::any_cast<Player*>(block_ids[test_level[y][x]])->draw();
                    }
                }
            }

            DrawFPS(0,0);

        EndDrawing();
        // Physics and stuff idk
        player.move();

    }
    std::cout << block_ids[1].type().name() << std::endl;
    return 0;
}
