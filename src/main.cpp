#include "include/Player.h"
#include "include/Enemy.h"
#include "include/NetworkManager.h"

int main()
{
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Jueguito");
    SetTargetFPS(60);

    NetworkManager network(NetworkRole::CLIENT);
    network.Start();

    Player *player = new Player(Vector2{screenWidth / 2, screenHeight / 2});
    Enemy *enemy = new Enemy(Vector2{400, 400});

    while (!WindowShouldClose())
    {
        player->Update();
        network.SetOwnPosition(player->GetPosition());

        enemy->SetPosition(network.GetOtherPosition());

        BeginDrawing();
        {
            ClearBackground(BLACK);
            player->Draw();
            enemy->Draw();
            // enemy->FollowTarget(player->GetPosition());
        }
        EndDrawing();
    }

    network.Stop();
    CloseWindow();
    return 0;
}