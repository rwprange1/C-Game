#include "Game.h"
#include <iostream>


/**
 * The constructor for this it creates a new window 
 */
Game::Game(){
    this->initVars();
    this->videoMode = sf::VideoMode({800, 600});
    this->window = sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
    this->window.setFramerateLimit(60);
    this->initEnemy();
}

/**
 * destructor?
 */
Game::~Game(){

}




/** 
 * wh
 */
void Game::pollEvents(){
    //event polling
    while(const std::optional event = this->window.pollEvent()){
        
        if (event ->is<sf::Event::Closed>()){
            window.close();
        } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
            const sf::Keyboard::Scancode key = keyPressed->scancode;

            switch(key){
                case sf::Keyboard::Scancode::Escape:
                    std::cout << "Escape Was Hit" << std::endl;
                    window.close();
                    break;
                case sf::Keyboard::Scancode::Space:
                    std::cout << "Space Was Hit" << std::endl;  
                    break;  
            }

            
        }
    }
}

/**
 * This will call the poll events function and apply the chnages 
 */
void Game::update(){
    this->pollEvents();
    this->updateMouse();
    this->updateEnemies();
}

/**
 * This function will clear the screen make chnages then display again
 */
void Game::render(){
    this->window.clear();

    //this->window.draw(this->enemy); //not standard way to render objects
    this->renderEnemies();

    this->window.display();
}



/**
 * This function will check to see if the window is still open
 * that is the game is still running
 * returns a bool on if the game is running still
 */
bool Game::isWinOpen(){
    return this->window.isOpen();
}

/**
 * Create several enemies here 
 */
void Game::initEnemy(){
    
    this->enemy.setPosition(sf::Vector2f(100.f,100.f)); //we are placing the object's top left corner here
    this->enemy.setSize(sf::Vector2f(100.f,100.f)); //float value helps compiler
    this->enemy.setScale(sf::Vector2f(.5f, .5f)); //cut the objects size down by 1/2
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);
}

/**
 * Spawns enemies and sets their color and positions
 * @returns void
 */
void Game::spawnEnemy(){
    std::cout << "Rendered an enemy" <<std::endl;
    this->enemy.setPosition(
        sf::Vector2f(rand() % static_cast<int>(this->window.getSize().x - this->enemy.getSize().x),
        rand() % static_cast<int>(this->window.getSize().y - this->enemy.getSize().y)
    ));

    this->enemy.setFillColor(sf::Color::Green);

    this->enemies.push_back(this->enemy);
}

/**
 * Sets the mouse pos field to the relative positon if the mouse on the screen
 */
void Game::updateMouse(){
    this->mousePosWindow = sf::Mouse::getPosition(this->window);
}






void Game::renderEnemies(){
     // move enemies
    for (auto &e: this->enemies){
        this->window.draw(e);
    }
}

/**
 * If we are not at the max number of enemies check to
 * see if enough time has passed to spawn one. If so
 * spawn one and reset values, else update timer
 * @returns void
 */
void Game::updateEnemies(){
    if(this->enemies.size() < this->maxEnemies){
        if(this->enemySpawnTimer >= this->enemySpawnTimerMax){
            this->enemySpawnTimer = 0.f;
            this->spawnEnemy();

        } else {
            this->enemySpawnTimer += 1.f;
        }
    }

    // move enemies
    for (auto &e: this->enemies){
        e.move(sf::Vector2f(0.f, 1.f));
    }
}

void Game::initVars(){
    this->points = 0;
    //spawn immediately 
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    std::cout << "Spawn Timer: " << this->enemySpawnTimer << std::endl; 
    this->maxEnemies = 5;
}

