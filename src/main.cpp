#include "include/Player.h"
#include "include/Enemy.h"

int main()
{
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Jueguito");
    SetTargetFPS(60);

    Player *player = new Player(Vector2{screenWidth / 2, screenHeight / 2});
    Enemy *enemy = new Enemy(Vector2{400, 400});

    while (!WindowShouldClose())
    {
        player->Update();
        enemy->FollowTarget(player->GetPosition());

        BeginDrawing();
        {
            ClearBackground(BLACK);
            player->Draw();
            enemy->Draw();
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}