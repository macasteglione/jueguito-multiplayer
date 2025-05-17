#include "../include/GameManager.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
    UnloadGame();
}

void GameManager::Update()
{
    if (WindowShouldClose())
    {
        currentState = GameState::EXIT;
        return;
    }

    switch (currentState)
    {
    case GameState::MENU:
        UpdateMenu();
        break;
    case GameState::GAME:
        UpdateGame();
        break;

    case GameState::EXIT:
        break;
    }
}

void GameManager::UpdateMenu()
{
    Menu::Option choice = menu.Update();

    if (choice == Menu::START)
        StartGame();
    else if (choice == Menu::EXIT)
        currentState = GameState::EXIT;
}

void GameManager::UpdateGame()
{
    if (IsKeyPressed(KEY_ESCAPE))
    {
        UnloadGame();
        currentState = GameState::MENU;
        return;
    }

    if (player)
        player->Update();

    if (enemy)
        enemy->FollowTarget(player->GetPosition());
}

void GameManager::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    switch (currentState)
    {
    case GameState::MENU:
        menu.Draw();
        break;

    case GameState::GAME:
        if (player)
            player->Draw();
        if (enemy)
            enemy->Draw();
        break;

    case GameState::EXIT:
        break;
    }

    EndDrawing();
}

bool GameManager::ShouldClose() const
{
    return currentState == GameState::EXIT;
}

void GameManager::StartGame()
{
    UnloadGame();

    player = new Player({400, 300}, menu.GetPlayerName());
    enemy = new Enemy({100, 100});
    currentState = GameState::GAME;
}

void GameManager::UnloadGame()
{
    delete player;
    delete enemy;
    player = nullptr;
    enemy = nullptr;
}