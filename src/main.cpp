#include "raylib.h"
#include "../include/grid.h"

int main() {
    unsigned int screenWidth = 1200;
    unsigned int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "Hello World z Raylib");
    SetTargetFPS(60);
    Grid grid{screenHeight, screenWidth};
    grid.grid_create(30);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BROWN);
        grid.render();


        EndDrawing();
    }

    CloseWindow();

    return 0;
}
