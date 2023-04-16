#include "Enemies.hpp"

Enemies::Enemies(float pos_x, float pos_y): enemyShape(rand()%20 + 40,rand()%8), enemyDir(0.f,1.f)
{

    this->initVariables();
    this->enemyShape.setRadius(this->pointCount*4);
    this->enemyShape.setPointCount(this->pointCount);
    this->enemyShape.setPosition(pos_x,pos_y);
    this->enemyShape.setFillColor(sf::Color(rand()%255 + 1,rand()%255 + 1,rand()%255 + 1,255 ));
}

Enemies::~Enemies()
{
}

const sf::FloatRect Enemies::getBounds() const
{
    return this->enemyShape.getGlobalBounds();
}

const int &Enemies::getPoint() const
{
    return this->points;
}

void Enemies::initVariables()
{
    this->pointCount = rand() % 8  +3; // min 3 and max 10 
    this->hpMax = static_cast<int>(this->pointCount);
    this->hp = this->hpMax;
    this->damage = this->pointCount;
    this->type = this->pointCount;
    this->damage = this->pointCount;
    this->points = this->pointCount;
    this->enemySpeed = static_cast<float>(this->pointCount)/2;

}

void Enemies::initSprite()
{

}



void Enemies::initTexture()
{
}

void Enemies::update()
{
    this->enemyShape.move(0.f,this->enemySpeed);
}

void Enemies::render(sf::RenderTarget *target)
{
    target->draw(this->enemyShape);
}
