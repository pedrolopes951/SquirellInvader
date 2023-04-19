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

    int hp;
    int hpMax;
    // WIndow coord
    sf::Vector2f window_cords;

public:
    Player(sf::Vector2f windows_cords);
    virtual ~Player();

    const int& getHp()const;
    const int& getHpMax()const;
    const sf::Vector2f& getPos() const;
    const sf::FloatRect getBonds() const;
    const sf::Sprite& getSprite() const;
    void setHp(int newHp);
    void looseHp(int damageHp);
    const bool canAttack();
    
    //Functions 
    void updateWindowBoundsColision(const sf::RenderTarget *target);
    void movePlayer(const float dirX, const float dirY);
    void update(sf::RenderTarget* target);
    void updateAttack();
    void render(sf::RenderTarget* target);
};
