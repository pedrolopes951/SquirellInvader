#include "Game.hpp"

Game::Game()
{
    this->initWindow();
    this->initPlayer();
}

Game::~Game()
{
    delete this->window;
    delete this->player;
}
void Game::initPlayer()
{
    this->player = new Player;
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Space Invaders", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

const bool Game::running() const
{
    return this->window->isOpen();
}

void Game::update()
{
    sf::Event event;

    while (this->window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
            {
                this->window->close();
            }
        default:
            break;
        }
    }
    // Move player
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player->move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->move(0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->move(0.f, 1.f); 
}

void Game::render()
{
    this->window->clear();

    // Draw it
    this->player->render(this->window);

    this->window->display();
}
