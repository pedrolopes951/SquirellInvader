#pragma once
#include "stdafx.hpp"
#include "Player.hpp"

class Game
{
private:
    // Window
    sf::RenderWindow* window;
    Player* player;

    void initPlayer();
    void initWindow();
public:
    Game(/* args */);
    virtual ~Game();

    // Functions 
    void run();
    const bool running() const;

    void update();
    void render();
};

