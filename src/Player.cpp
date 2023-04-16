#include "Player.hpp"

Player::Player(sf::Vector2f windows_cords)
{
    this->window_cords = windows_cords;
    this->moveSpeed = 10.f;
    this->attackCooldownMax = 10.f;
    this->attackCooldown = this->attackCooldownMax;
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

const sf::FloatRect Player::getBonds() const
{
    return this->sprite.getGlobalBounds();
}

const sf::Sprite &Player::getSprite() const
{
    return this->sprite;
}

const bool Player::canAttack()
{
    if(this->attackCooldown >= this->attackCooldownMax)
    {
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
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
    float center_x = this->sprite.getTexture()->getSize().x * 0.35;
    float center_y = this->sprite.getTexture()->getSize().y * 0.5;

    this->sprite.setOrigin(center_x, center_y);

    // Set player on the center of the screen
    sf::Vector2f middle_pos(this->window_cords.x / 2, this->window_cords.y / 2);
    this->sprite.setPosition(middle_pos);
}

void Player::updateWindowBoundsColision(const sf::RenderTarget *target)
{
    // Colisition bound to left side of screen
    if (this->sprite.getPosition().x - this->sprite.getOrigin().x <= 0.f)
    {
        this->sprite.setPosition(this->sprite.getOrigin().x, this->sprite.getPosition().y);
    }

    // // Right wall
    if (this->sprite.getPosition().x + this->sprite.getOrigin().x >= target->getSize().x)
    {
        this->sprite.setPosition(target->getSize().x - this->sprite.getOrigin().x, this->sprite.getPosition().y);
    }
    // // TOP
    if (this->sprite.getPosition().y - this->sprite.getOrigin().y <= 0.f)
    {
        this->sprite.setPosition(this->sprite.getPosition().x, this->sprite.getOrigin().y);
    }
    // Bottom
    if (this->sprite.getPosition().y + this->sprite.getOrigin().y >= target->getSize().y)
    {
        this->sprite.setPosition(this->sprite.getPosition().x,target->getSize().y - this->sprite.getOrigin().y );
    }
}

void Player::movePlayer(const float dirX, const float dirY)
{
    this->sprite.move(this->moveSpeed * dirX, this->moveSpeed * dirY);
}

void Player::update(sf::RenderTarget *target)
{
    this->updateWindowBoundsColision(target);
    this->updateAttack();
}
void Player::updateAttack()
{
    if(this->attackCooldown < this->attackCooldownMax)
    {
        this->attackCooldown += 0.5f;
    }
    
}

void Player::render(sf::RenderTarget *target)
{

    target->draw(this->sprite);
}
