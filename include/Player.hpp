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

public:
    Player(/* args */);
    virtual ~Player();

    const sf::Vector2f& getPos() const;

    
    //Functions 
    void updateWindowBoundsColision(const sf::RenderTarget *target);
    void move(const float dirX, const float dirY);
    void update(sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
};
