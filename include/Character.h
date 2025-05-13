#ifndef CHARACTER_HEADER
#define CHARACTER_HEADER

#include <raylib.h>

class Character
{
protected:
    int movSpeed = 5;
    Vector2 position;

public:
    Character(Vector2 _position);
    virtual ~Character();

    Vector2 GetPosition() const;
    void SetPosition(const Vector2 &_position);
    double GetMovSpeed() const;
    void SetMovSpeed(const double &_movSpeed);

    virtual void Draw() const = 0;
    virtual void Update() = 0;
};

#endif // CHARACTER_HEADER