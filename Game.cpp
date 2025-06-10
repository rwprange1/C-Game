#include "Game.h"
#include <iostream>


/**
 * The constructor for this it creates a new window 
 */
Game::Game(){
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

    //update mouse pos, this gets relative mouse position to the entire screen
    //std::cout << "Mouse Pos: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << std::endl;

     //update mouse pos, this gets relative mouse position to our window(moving the window changes the values)
    std::cout << "Mouse Pos: " << sf::Mouse::getPosition(this->window).x << " " << sf::Mouse::getPosition(this->window).y << std::endl;
    
}

/**
 * This function will clear the screen make chnages then display again
 */
void Game::render(){
    this->window.clear();

    this->window.draw(this->enemy); //not standard way to render objects
    
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


void Game::initEnemy(){
    
    this->enemy.setPosition(sf::Vector2f(100.f,100.f)); //we are placing the object's top left corner here
    this->enemy.setSize(sf::Vector2f(100.f,100.f)); //float value helps compiler
    this->enemy.setScale(sf::Vector2f(.5f, .5f)); //cut the objects size down by 1/2
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);
}