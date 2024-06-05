#include "obstacle.hpp"

Obstacles::Obstacles() : gameStarted(false) {
    if (!texture.loadFromFile("./obstacle.png")) {
        
    }

    gap = 180; 
    obstacleWidth = 50; 
    obstacleHeight = 200;
    speed = 5; //velocidad del juego 
    obstacleFrequency = 80; //cada cuanto sale un edifcio
    frame = 10; 

    generateObstacles();
}

void Obstacles::generateObstacles() {
    int randomHeight = rand() % (410 - gap);

    sf::Sprite obstacleone;
    obstacleone.setTexture(texture);
    obstacleone.setScale(0.5f, 0.5f); 
    obstacleone.setPosition(700, randomHeight - obstacleHeight);
    obstacles.push_back(obstacleone);

    sf::Sprite obstacledos;
    obstacledos.setTexture(texture);
    obstacledos.setScale(0.5f, 0.5f);
    obstacledos.setPosition(700, randomHeight + gap);
    obstacles.push_back(obstacledos);
}

void Obstacles::update() {
    frame++;
    
    if (frame >= obstacleFrequency) {
        generateObstacles();
        frame = 0;
    }

    for (auto& obstacle : obstacles) {
        obstacle.move(-speed, 0);
    }

    if (!obstacles.empty() && obstacles[0].getPosition().x < -obstacleWidth) {
        obstacles.erase(obstacles.begin(), obstacles.begin() + 2);
    }
}

void Obstacles::draw(sf::RenderWindow& window) {
    for (auto& obstacle : obstacles) {
        window.draw(obstacle);
    }
}

void Obstacles::reset() {
    obstacles.clear();
    frame = 0;
    generateObstacles();
}

std::vector<sf::Sprite>& Obstacles::getObstacles() {
    return obstacles;
}
