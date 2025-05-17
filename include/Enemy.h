#ifndef ENEMY_HEADER
#define ENEMY_HEADER

#include "Character.h"

class Enemy : public Character
{
private:
    float radius = 20.0f;

public:
    explicit Enemy(Vector2 _position);
    ~Enemy() override = default;

    void Update() override;
    void Draw() const override;
    void FollowTarget(const Vector2 &_targetPosition);
};

#endif // ENEMY_HEADER