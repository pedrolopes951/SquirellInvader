#pragma once

#include"stdafx.hpp"

class Peanut
{
private:
    /* data */
    sf::Sprite shape;
    sf::Vector2f direction;
    float movementSpeed;

public:
    Peanut();
    Peanut(sf::Texture* texture,float posX, float posY, float dirX, float dirY, float movementSpeed);
    virtual ~Peanut();

    const sf::FloatRect getBounds() const;
    
    void update();
    void render(sf::RenderTarget * target);

};
