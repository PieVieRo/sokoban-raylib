#include <raylib.h>
#include <raymath.h>
#include <iostream>

#include "player.hpp"
#include "block.cpp"

int main() {
    const char* TITLE = "Sokoban!!!";
    const int WIDTH = 640;  // all sprites are 64x64
    const int HEIGHT = 640;
    InitWindow(WIDTH, HEIGHT,  TITLE);

    const int FPS = 60;
    SetTargetFPS(FPS);

    if(!IsWindowReady()) {
        std::cout << "Window isn't ready :(" << std::endl;
        return -1;
    }

    Block ground(LoadTexture("assets/sprites/ground.png"), true);
    Block wall(LoadTexture("assets/sprites/wall.png"));
    Block* test_level[10][10] {
        &wall, &wall, &wall, &wall,  &wall,  &wall,  &wall,  &wall,  &wall,  &wall,
        &wall, &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &wall,
        &wall, &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &wall,
        &wall, &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &wall,
        &wall, &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &wall,
        &wall, &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &wall,
        &wall, &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &wall,
        &wall, &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &wall,
        &wall, &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &ground,  &wall,
        &wall, &wall,  &wall,  &wall,  &wall,  &wall,  &wall,  &wall,  &wall,  &wall,
    };

    Player person(
            (Vector2){0, 0},
            LoadTexture("assets/sprites/player.png")
            );

    while(!WindowShouldClose()) {
        // Drawing
        BeginDrawing();
            ClearBackground(RAYWHITE);

            for(int x=0; x<10; x++) {
                for(int y=0; y<10; y++) {
                    if(test_level[x][y] != &ground)
                        ground.draw(x,y);
                    test_level[x][y]->draw(x,y);
                }
            }
            person.draw();

            DrawFPS(0,0);

        EndDrawing();
        // Physics and stuff idk
        person.move();

    }
    return 0;
}
