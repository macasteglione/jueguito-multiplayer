#include "../include/Enemy.h"
#include <math.h>

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
    // Calculate the direction vector towards the target
    double dirX = _targetPosition.x - position.x;
    double dirY = _targetPosition.y - position.y;

    // Normalize the direction vector
    double length = sqrt(dirX * dirX + dirY * dirY);
    if (length != 0)
    {
        dirX /= length;
        dirY /= length;
    }
    // Move the enemy towards the target
    position.x += dirX * movSpeed;
    position.y += dirY * movSpeed;
}