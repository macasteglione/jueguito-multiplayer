#include "../include/GameManager.h"
#include "../include/Constants.h"

int main() {
    SetExitKey(KEY_NULL);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Jueguito");
    SetTargetFPS(TARGET_FPS);

    GameManager game;

    while (!game.ShouldClose()) {
        game.Update();
        game.Draw();
    }

    CloseWindow();
    return 0;
}
