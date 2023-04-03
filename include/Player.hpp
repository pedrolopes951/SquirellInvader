#include "stdafx.hpp"



class Player
{
private:
    //Textures
    sf::Sprite sprite;
    sf::Texture texture;

    //Sprite
    void initTexture();
    void initSprite();

    float moveSpeed;
    float attackCooldown;
    float attackCooldownMax;

    // WIndow coord
    sf::Vector2f window_cords;

public:
    Player(sf::Vector2f windows_cords);
    virtual ~Player();

    const sf::Vector2f& getPos() const;
    const bool canAttack();
    
    //Functions 
    void updateWindowBoundsColision(const sf::RenderTarget *target);
    void movePlayer(const float dirX, const float dirY);
    void update(sf::RenderTarget* target);
    void updateAttack();
    void render(sf::RenderTarget* target);
};
