/**
 * The header file for our game class we will definbe the structure and the methods here
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game {
    private:
        // fields
        sf::RenderWindow window;
        sf::VideoMode videoMode;

    public:
        //constructors / Destructors
        Game();
        virtual ~Game();


        //Functions
        void update();
        void render();
        void pollEvents();

        bool isWinOpen();


};

