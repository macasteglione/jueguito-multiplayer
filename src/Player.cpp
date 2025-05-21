#include "../include/Player.h"
#include "../include/Constants.h"
#include <raymath.h>

Player::Player(const Vector2 _position, const std::string &_name) : Character(_position) {
    name = _name;
}

void Player::Update() {
    SetKeyControls();
    SetBoundary();
}

void Player::Draw() const {
    DrawCircleV(position, radius, BLUE);
    DrawText(name.c_str(), (int) (position.x - MeasureText(name.c_str(), TEXT_SIZE) / 2),
             (int) (position.y - radius - 25), TEXT_SIZE, WHITE);
}

void Player::SetKeyControls() {
    Vector2 movement = {0, 0};

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        movement.x += 1;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        movement.x -= 1;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        movement.y -= 1;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        movement.y += 1;

    if (movement.x != 0 || movement.y != 0) {
        movement = Vector2Normalize(movement);
        position.x += movement.x * movSpeed;
        position.y += movement.y * movSpeed;
    }
}

void Player::SetBoundary() {
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    // Mantener el jugador dentro de los límites de la pantalla
    if (position.x < radius)
        position.x = radius;
    else if (position.x > screenWidth - radius)
        position.x = screenWidth - radius;

    if (position.y < radius)
        position.y = radius;
    else if (position.y > screenHeight - radius)
        position.y = screenHeight - radius;
}
