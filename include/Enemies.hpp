#pragma once
#include "stdafx.hpp"

class Enemies
{
private:
    // Variables
    sf::CircleShape enemyShape;
    sf::Texture enemyTexture;
    sf::Sprite enemySprite;
    
    int type;
    int hp;
    int hpMax;
    int scoreEnemy;
    float enemySpeed;

    // Functions 
    void initVariables();
    void initSprite();
    void initTexture();

public:
    Enemies(float pos_x, float pos_y);
    ~Enemies();
    void update(sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
};

