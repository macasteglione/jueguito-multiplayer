#ifndef MENU_H
#define MENU_H

#include <raylib.h>
#include <string>

class Menu {
    Rectangle startButton{};
    Rectangle exitButton{};
    Rectangle nameField{};

    std::string playerName;

    static constexpr auto startText = "Jugar";
    static constexpr auto exitText = "Salir";
    static constexpr auto nameText = "Nombre:";

    void UpdateLayout();

public:
    enum Option {
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
