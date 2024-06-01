#include "obstacle.hpp"

Obstacles::Obstacles() : gameStarted(false) {
    if (!texture.loadFromFile("./obstacle.png")) {
        // Handle error
    }

    gap = 180;
    obstacleWidth = 50;
    obstacleHeight = 200;
    speed = 5;
    obstacleFrequency = 80;
    frameCount = 0;

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
    frameCount++;
    
    if (frameCount >= obstacleFrequency) {
        generateObstacles();
        frameCount = 0;
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
    frameCount = 0;
    generateObstacles();
}

std::vector<sf::Sprite>& Obstacles::getObstacles() {
    return obstacles;
}
