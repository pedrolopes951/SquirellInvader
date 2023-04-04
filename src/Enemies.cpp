#include "Enemies.hpp"

Enemies::Enemies(float pos_x, float pos_y): enemyShape(rand()%20 + 20,rand()%8)
{

    this->enemyShape.setPosition(pos_x,pos_y);
}

Enemies::~Enemies()
{
}

void Enemies::initVariables()
{
    this->hpMax = 10;
    this->hp = 0;
    this->scoreEnemy = 0;
    this->type = 0;
    this->enemySpeed = 10.f;

}

void Enemies::initSprite()
{
}

void Enemies::initTexture()
{
}

void Enemies::update(sf::RenderTarget *target)
{
}

void Enemies::render(sf::RenderTarget *target)
{
    target->draw(this->enemyShape);
}
