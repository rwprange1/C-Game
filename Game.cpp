#include "Game.h"
#include <iostream>


/**
 * The constructor for this it creates a new window 
 */
Game::Game(){
    this->videoMode = sf::VideoMode({800, 600});
    this->window = sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
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
}

/**
 * This function will clear the screen make chnages then display again
 */
void Game::render(){
    this->window.clear(sf::Color::Cyan);
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
