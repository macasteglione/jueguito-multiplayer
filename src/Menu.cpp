#include "../include/Menu.h"
#include "../include/Constants.h"

Menu::Menu() {
    UpdateLayout();
}

void Menu::UpdateLayout() {
    const float screenWidth = GetScreenWidth();
    const float screenHeight = GetScreenHeight();

    constexpr float buttonWidth = 200;
    constexpr float buttonHeight = 50;

    nameField = {screenWidth / 2 - buttonWidth / 2, screenHeight / 2 - 100, buttonWidth, 40};
    startButton = {screenWidth / 2 - buttonWidth / 2, screenHeight / 2, buttonWidth, buttonHeight};
    exitButton = {screenWidth / 2 - buttonWidth / 2, screenHeight / 2 + 70, buttonWidth, buttonHeight};
}

Menu::Option Menu::Update() {
    UpdateLayout(); // Asegura que los botones se ajusten si cambia la resolución

    const Vector2 mouse = GetMousePosition();

    // Captura texto
    int key = GetKeyPressed();
    while (key > 0) {
        if (key >= 32 && key <= 125 && playerName.length() < PLAYER_NAME_LENGTH)
            playerName += static_cast<char>(key);
        key = GetKeyPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE) && !playerName.empty())
        playerName.pop_back();

    // Interacción
    const bool clickedStart = IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse, startButton);
    const bool pressedEnter = IsKeyPressed(KEY_ENTER);

    if ((clickedStart || pressedEnter) && !playerName.empty())
        return START;

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mouse, exitButton))
        return EXIT;

    return NONE;
}

void Menu::Draw() const {
    // Nombre
    DrawRectangleLinesEx(nameField, 2, LIGHTGRAY);
    DrawText(nameText, nameField.x - MeasureText(nameText, TEXT_SIZE) - 10,
             nameField.y + (nameField.height - TEXT_SIZE) / 2, TEXT_SIZE, WHITE);
    DrawText(playerName.c_str(), nameField.x + 10,
             nameField.y + (nameField.height - TEXT_SIZE) / 2, TEXT_SIZE, WHITE);

    // Botón Start
    DrawRectangleRec(startButton, playerName.empty() ? DARKGRAY : LIGHTGRAY);
    DrawText(startText, startButton.x + (startButton.width - MeasureText(startText, TEXT_SIZE)) / 2,
             startButton.y + (startButton.height - TEXT_SIZE) / 2, TEXT_SIZE, BLACK);

    // Botón Exit
    DrawRectangleRec(exitButton, LIGHTGRAY);
    DrawText(exitText, exitButton.x + (exitButton.width - MeasureText(exitText, TEXT_SIZE)) / 2,
             exitButton.y + (exitButton.height - TEXT_SIZE) / 2, TEXT_SIZE, BLACK);
}

std::string Menu::GetPlayerName() const {
    return playerName;
}
