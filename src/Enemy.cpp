#include "../include/Enemy.h"
#include <raymath.h>

Enemy::Enemy(Vector2 _position) : Character(_position)
{
    radius = 20;  // Set a default radius for the ball
    movSpeed = 2; // Set a default movement speed for the enemy
}

Enemy::~Enemy()
{
    // Destructor logic if needed
    // Currently, no dynamic memory allocation is used, so nothing to clean up
    // You can add cleanup code here if you allocate resources in the future
}

void Enemy::Update()
{
}

void Enemy::Draw() const
{
    DrawCircle(position.x, position.y, radius, RED);
}

void Enemy::FollowTarget(const Vector2 &_targetPosition)
{
    Vector2 direction = _targetPosition - position;

    double length = Vector2Length(direction);
    if (length != 0)
        direction = Vector2Normalize(direction);

    position += direction * movSpeed;
}