#ifndef ENEMY_HEADER
#define ENEMY_HEADER

#include "Character.h"

class Enemy : public Character
{
private:
    int radius;

public:
    Enemy(Vector2 _position);
    ~Enemy();
    
    void Update() override;
    void Draw() const override;
    void FollowTarget(const Vector2 &_targetPosition);
};

#endif // ENEMY_HEADER