#include "Player.hpp"


Player::Player(/* args */)
{
    this->moveSpeed = 10.f;
    this->initTexture();
    this->initSprite();
}

Player::~Player()
{
}

const sf::Vector2f &Player::getPos() const
{
    return this->sprite.getPosition();
}

void Player::initTexture()
{
    if(!this->texture.loadFromFile(std::string(TEXTUREPATH)+ std::string("squirrel.png")))
    {
        std::cerr << "Load texture from file failed\n";
    }
    
}

void Player::initSprite()
{
    this->sprite.setTexture(this->texture);

    // Resize the sprite

    this->sprite.scale(0.9f,0.9f);
}

void Player::move(const float dirX, const float dirY)
{
    this->sprite.move(this->moveSpeed*dirX,this->moveSpeed*dirY);
}

void Player::update()
{
}

void Player::render(sf::RenderTarget* target)
{
    target->draw(this->sprite);
}
