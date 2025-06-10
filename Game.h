/**
 * The header file for our game class we will definbe the structure and the methods here
 */

#pragma once

#include <iostream>
#include <vector>
#include <ctime>

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
        sf::Vector2i mousePosWindow; // mouse pos rel to window
        
        sf::RectangleShape enemy; //for textures use a sf::Sprite
        std::vector<sf::RectangleShape> enemies;

       

        float enemySpawnTimer;
        const float enemySpawnTimerMax = 1000.f;
        unsigned int maxEnemies; 
        unsigned int points; 

         void initEnemy();
         void initVars();


    public:
        //constructors / Destructors
        Game();
        virtual ~Game();


        //Functions
        void update();
        void render();
        void pollEvents();
        void updateMouse();
        void spawnEnemy();
        bool isWinOpen();


        void updateEnemies();
        void renderEnemies();


};

