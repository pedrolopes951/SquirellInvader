#include "Game.hpp"

Game::Game()
{
    this->initWindow();
    this->initPlayer();
    this->initTexture();
    this->initWindowBackground();
}

Game::~Game()
{
    delete this->window;
    delete this->player;

    // Delete texture
    for (auto &i : this->texture)
    {
        delete i.second;
    }

    for (auto &i : this->peanut)
    {
        delete i;
    }
}
void Game::initPlayer()
{
    sf::Vector2f window_size(this->window->getSize().x, this->window->getSize().y);
    this->player = new Player(window_size);
}

void Game::initTexture()
{
    this->texture["Peanut"] = new sf::Texture();

    if (!this->texture["Peanut"]->loadFromFile(std::string(TEXTUREPATH) + std::string("bullet.png")))
    {
        std::cerr << "Load texture from file failed\n";
    }

    if (!this->textureBackground.loadFromFile(std::string(TEXTUREPATH) + std::string("grass.jpeg")))
    {
        std::cerr << "Load texture from file failed\n";
    }
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Space Invaders", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initWindowBackground()
{
    this->spriteBackground.setTexture(this->textureBackground);

    float x_scale = this->window->getSize().x / this->spriteBackground.getGlobalBounds().width;

    // std::cout << "X scale " << this->spriteBackground.getGlobalBounds().width << "\n";
    float y_scale = this->window->getSize().y / this->spriteBackground.getGlobalBounds().height;
    // std::cout << "Y scale " << this->spriteBackground.getGlobalBounds().height << "\n";
    this->spriteBackground.setScale(x_scale, y_scale);
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

void Game::updatePollEvents()
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
}

void Game::updateInput()
{
    // Move player
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player->movePlayer(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player->movePlayer(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->movePlayer(0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->movePlayer(0.f, 1.f);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
    {
        
        this->peanut.push_back(new Peanut(this->texture["Peanut"], this->player->getPos().x, this->player->getPos().y, 0.f, -1.f, 5.f));
        
    }
}

void Game::updatePeanut()
{
    unsigned counter = 0;
    for (auto *i : this->peanut)
    {
        i->update();
        // Bullet culling (Top of screen)
        if (i->getBounds().top + i->getBounds().height < 0.f)
        {
            // Delete the bullter
            delete this->peanut.at(counter);
            this->peanut.erase(this->peanut.begin() + counter);
            --counter;

            // Check memory is being deleted

            std::cout << this->peanut.size() << "\n";
        }
        ++counter;
    }
}

void Game::update()
{
    this->updatePollEvents();
    this->updateInput();
    this->player->update(this->window);
    this->updatePeanut();
}

void Game::render()
{
    this->window->clear();

    this->window->draw(this->spriteBackground);

    // Draw it
    this->player->render(this->window);

    for (auto *i : this->peanut)
    {
        i->render(this->window);
    }

    this->window->display();
}
