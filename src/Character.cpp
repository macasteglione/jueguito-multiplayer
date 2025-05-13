#include "../include/Character.h"

Character::Character(Vector2 _position)
{
    position = _position;
}

Character::~Character()
{
    // Destructor logic if needed
    // Currently, no dynamic memory allocation is used, so nothing to clean up
    // You can add cleanup code here if you allocate resources in the future
}

Vector2 Character::GetPosition() const
{
    return position;
}

void Character::SetPosition(const Vector2 &_position)
{
    position = _position;
}

double Character::GetMovSpeed() const
{
    return movSpeed;
}

void Character::SetMovSpeed(const double &_movSpeed)
{
    movSpeed = _movSpeed;
}