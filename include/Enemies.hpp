#pragma once
#include "stdafx.hpp"

class Enemies
{
private:
    // Variables
    sf::CircleShape enemyShape;
    sf::Texture enemyTexture;
    sf::Sprite enemySprite;
    
    unsigned pointCount;
    int points;
    int type;
    int hp;
    int hpMax;
    int damage;
    float enemySpeed;
    sf::Vector2f enemyDir;

    // Acessors 
    
    // Functions 
    void initVariables();
    void initSprite();
    void initTexture();

public:
    Enemies(float pos_x, float pos_y);
    ~Enemies();
    const sf::FloatRect getBounds() const;
    const int& getPoint() const;
    void update();
    void render(sf::RenderTarget* target);
};

