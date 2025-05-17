#ifndef MENU_H
#define MENU_H

#include <raylib.h>
#include <string>

class Menu
{
private:
    Rectangle startButton;
    Rectangle exitButton;
    Rectangle nameField;

    std::string playerName;

    static constexpr const char *startText = "Jugar";
    static constexpr const char *exitText = "Salir";
    static constexpr const char *nameText = "Nombre:";

    void UpdateLayout();

public:
    enum Option
    {
        NONE,
        START,
        EXIT
    };

    Menu();

    Option Update();
    void Draw() const;
    std::string GetPlayerName() const;
};

#endif // MENU_H