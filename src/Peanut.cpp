#include "Peanut.hpp"

Peanut::Peanut(/* args */)
{
}

Peanut::Peanut(sf::Texture* texture,float posX, float posY, float dirX, float dirY, float movementSpeed)
{
    this->shape.setTexture(*texture);

    this->shape.setPosition(posX,posY);
    this->shape.setScale(1.f,1.f);
    this->direction.y = dirY;
    this->direction.x = dirX;
    this->movementSpeed = movementSpeed;

}

Peanut::~Peanut()
{
}

void Peanut::update()
{
    this->shape.move(this->movementSpeed* this->direction);

}

void Peanut::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}
