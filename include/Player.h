#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Character.h"
#include <string>

class Player final : public Character {
    float radius = 20.0f;
    std::string name;

public:
    explicit Player(Vector2 _position, const std::string &_name);

    ~Player() override = default;

    void SetKeyControls();

    void SetBoundary();

    void Draw() const override;

    void Update() override;
};

#endif // PLAYER_HEADER
