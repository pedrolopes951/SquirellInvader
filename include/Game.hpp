#pragma once
#include "stdafx.hpp"
#include "Player.hpp"
#include "Peanut.hpp"
class Game
{
private:
    // Window
    sf::RenderWindow* window;
    Player* player;

    // Background Texture for game
    sf::Texture textureBackground;
    sf::Sprite spriteBackground;

    //Resourcer
    std::map<std::string,sf::Texture*> texture;
    std::vector<Peanut*> peanut;

    void initPlayer();
    void initTexture();
    void initWindow();
    void initWindowBackground();


public:
    Game(/* args */);
    virtual ~Game();

    // Functions 
    void run();
    const bool running() const;

    void updatePollEvents();
    void updateInput();
    void updatePeanut();
    void update();
    void render();
};

