#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Menu.h"
#include "Player.h"
#include "Enemy.h"

enum class GameState {
    MENU,
    GAME,
    EXIT
};

class GameManager {
    Menu menu;
    GameState currentState = GameState::MENU;
    Player *player = nullptr;
    Enemy *enemy = nullptr;

    void UnloadGame();

    void UpdateMenu();

    void UpdateGame();

    void StartGame();

public:
    GameManager();

    ~GameManager();

    void Update();

    void Draw() const;

    bool ShouldClose() const;
};

#endif // GAME_MANAGER_H
