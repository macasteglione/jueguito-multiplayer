#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Character.h"

class Player : public Character
{
private:
    int radius;

public:
    Player(Vector2 _position);
    ~Player();
    
    void SetKeyControls();
    void SetBoundary();
    void Draw() const override;
    void Update() override;
};

#endif // PLAYER_HEADER