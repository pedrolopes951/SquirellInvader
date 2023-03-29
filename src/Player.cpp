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

void Player::updateWindowBoundsColision(const sf::RenderTarget *target)
{
    // Colisition bound to left side of screen 
    if(this->sprite.getGlobalBounds().left <= 0.f)
    {
        this->sprite.setPosition(0.f,this->sprite.getGlobalBounds().top);
    }
    // Right wall 
    if(this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width >= target->getSize().x)
    {
        this->sprite.setPosition(target->getSize().x-this->sprite.getGlobalBounds().width,this->sprite.getGlobalBounds().top);
    }
    // TOP
    if(this->sprite.getGlobalBounds().top <= 0.f)
    {
        this->sprite.setPosition(this->sprite.getGlobalBounds().left,0.f);
    }
    // Bottom 
    if(this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height >= target->getSize().y)
    {
        this->sprite.setPosition(this->sprite.getGlobalBounds().left,target->getSize().y-this->sprite.getGlobalBounds().height);
    }
    
}

void Player::move(const float dirX, const float dirY)
{
    this->sprite.move(this->moveSpeed*dirX,this->moveSpeed*dirY);
}

void Player::update(sf::RenderTarget* target)
{
    this->updateWindowBoundsColision(target);    
}

void Player::render(sf::RenderTarget* target)
{
    target->draw(this->sprite);
}
