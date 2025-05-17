#ifndef CHARACTER_HEADER
#define CHARACTER_HEADER

#include <raylib.h>

class Character
{
protected:
    float movSpeed = 5.0f;
    Vector2 position;

public:
    explicit Character(Vector2 _position);
    virtual ~Character() = default;

    Vector2 GetPosition() const;
    void SetPosition(const Vector2 &_position);

    float GetMovSpeed() const;
    void SetMovSpeed(const float &_movSpeed);

    virtual void Draw() const = 0;
    virtual void Update() = 0;
};

#endif // CHARACTER_HEADER