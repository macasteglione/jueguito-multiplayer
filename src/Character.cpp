#include "../include/Character.h"

Character::Character(Vector2 startPos) : position(startPos) {}

Vector2 Character::GetPosition() const
{
    return position;
}

void Character::SetPosition(const Vector2 &_position)
{
    position = _position;
}

float Character::GetMovSpeed() const
{
    return movSpeed;
}

void Character::SetMovSpeed(const float &_movSpeed)
{
    movSpeed = _movSpeed;
}