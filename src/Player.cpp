#include "Player.hpp"

Player::Player(sf::Vector2f windows_cords)
{
    this->window_cords = windows_cords;
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
    if (!this->texture.loadFromFile(std::string(TEXTUREPATH) + std::string("squirrel.png")))
    {
        std::cerr << "Load texture from file failed\n";
    }
}

void Player::initSprite()
{
    this->sprite.setTexture(this->texture);

    // Resize the sprite

    this->sprite.scale(0.9f, 0.9f);

    // Set origin in the center of sprite
    float center_x = this->sprite.getTexture()->getSize().x * 0.5;
    float center_y = this->sprite.getTexture()->getSize().y * 0.5;

    this->sprite.setOrigin(center_x, center_y);

    // Set player on the center of the screen
    sf::Vector2f middle_pos(this->window_cords.x / 2, this->window_cords.y / 2);
    this->sprite.setPosition(middle_pos);
}

void Player::updateWindowBoundsColision(const sf::RenderTarget *target)
{
    // Colisition bound to left side of screen
    // std::cout << "Left : "<< this->sprite.getGlobalBounds().left << ", Top : " << this->sprite.getGlobalBounds().top << std::endl;
    std::cout << "Origin x : " << this->sprite.getOrigin().x << std::endl;
    std::cout << "Origin y : " << this->sprite.getOrigin().y << std::endl;
    if (this->sprite.getPosition().x  -  this->sprite.getOrigin().x <= 0)
    {
        
        this->sprite.setPosition(this->sprite.getOrigin().x, this->sprite.getPosition().y);

    }

    // // Right wall
    // if(this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width - 50.f /* Discont a bit */ >= this->sprite.getGlobalBounds()target->getSize().x)
    // {
    //     this->sprite.setPosition(target->getSize().x-this->sprite.getGlobalBounds().width + 50.f,this->sprite.getGlobalBounds().top);
    // }
    // // TOP
    // if(this->sprite.getGlobalBounds().top <= 0.f)
    // {
    //     this->sprite.setPosition(this->sprite.getGlobalBounds().left,0.f);
    // }
    // // Bottom
    // if(this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height >= target->getSize().y)
    // {
    //     this->sprite.setPosition(this->sprite.getGlobalBounds().left,target->getSize().y-this->sprite.getGlobalBounds().height);
    // }
}

void Player::movePlayer(const float dirX, const float dirY)
{
    this->sprite.move(this->moveSpeed * dirX, this->moveSpeed * dirY);
}

void Player::update(sf::RenderTarget *target)
{
    this->updateWindowBoundsColision(target);
}

void Player::render(sf::RenderTarget *target)
{

    target->draw(this->sprite);
}
