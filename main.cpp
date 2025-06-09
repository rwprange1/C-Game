// this is the main file for a c++ sfml game
// @author Richard Prange, Suraj Sharma on yt
// @version 6/9/2025



#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

// allows us to not have sf:: before our sf::window etc
using namespace sf;

/**
 * The entry point to our program it does...
 *  
 */
int main(){
    
    //window
    sf::RenderWindow window(sf::VideoMode({800,600}), "Game", sf::Style::Titlebar | sf::Style::Close);
    
    // main loop
    while(window.isOpen()){

        //event polling
        while(const std::optional event = window.pollEvent()){
            if (event ->is<sf::Event::Closed>()){
                window.close();
            } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                const sf::Keyboard::Scancode key = keyPressed->scancode;

                switch(key){
                    case sf::Keyboard::Scancode::Escape:
                        window.close();
                        break;
                    case sf::Keyboard::Scancode::Space:
                        std::cout << "Space Was Hit" << std::endl;  
                        break;  
                }

              
            }
        }

        //update
        window.clear(sf::Color::Magenta); //clear old frame
        // draw game here



        window.display(); // tell app that window is done drawing 


        //render

    }




    return 0;
}
