#pragma once
#include "stdafx.hpp"
#include "Player.hpp"
#include "Peanut.hpp"
#include "Enemies.hpp"

class Game
{
private:
    // Window
    sf::RenderWindow* window;
    Player* player;

    // Enemies
    std::vector<Enemies*> enemies;
    float spawnTimerMax;
    float spawnTimer;
    float initXPosEnemie;
    float initYPosEnemie;

    // GUI 
    sf::Font font;
    sf::Text pointText;
    unsigned points;

    // Background Texture for game
    sf::Texture textureBackground;
    sf::Sprite spriteBackground;

    //Resourcer
    std::map<std::string,sf::Texture*> texture;
    std::vector<Peanut*> peanut;

    void initPlayer();
    void initSystems();
    void initEnemie();
    void initGUI();
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
    void updateGUI();
    void updateEnemie();
    void updateCombat(); 
    void updatePeanut();
    void update();
    void render();
    void renderGUI();
};

