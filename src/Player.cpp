#include "../include/Player.h"

Player::Player(Vector2 _position) : Character(_position)
{
    radius = 20;
}

Player::~Player()
{
    // Destructor logic if needed
    // Currently, no dynamic memory allocation is used, so nothing to clean up
    // You can add cleanup code here if you allocate resources in the future
}

void Player::Update()
{
    SetKeyControls();
    SetBoundary();
}

void Player::Draw() const
{
    DrawCircle(position.x, position.y, radius, BLUE);
}

void Player::SetKeyControls()
{
    if (IsKeyDown(KEY_W))
        position.y -= movSpeed;
    if (IsKeyDown(KEY_S))
        position.y += movSpeed;
    if (IsKeyDown(KEY_A))
        position.x -= movSpeed;
    if (IsKeyDown(KEY_D))
        position.x += movSpeed;
}

void Player::SetBoundary()
{
    if (position.x - radius < 0)
        position.x = radius;
    if (position.x + radius > GetScreenWidth())
        position.x = GetScreenWidth() - radius;
    if (position.y - radius < 0)
        position.y = radius;
    if (position.y + radius > GetScreenHeight())
        position.y = GetScreenHeight() - radius;
}