#include "../include/Enemy.h"
#include <raymath.h>

Enemy::Enemy(Vector2 _position) : Character(_position)
{
    movSpeed = 2;
}

void Enemy::Update()
{
}

void Enemy::Draw() const
{
    DrawCircleV(position, radius, RED);
}

void Enemy::FollowTarget(const Vector2 &_targetPosition)
{
    Vector2 direction = _targetPosition - position;

    if (Vector2Length(direction) > 0.0f)
    {
        direction = Vector2Normalize(direction);
        position = Vector2Add(position, Vector2Scale(direction, movSpeed));
    }
}