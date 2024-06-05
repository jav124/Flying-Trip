#ifndef obstacle_hpp
#define obstacle_hpp

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

class Obstacles {
public:
    Obstacles();
    void update();
    void draw(sf::RenderWindow& window);
    void reset();
    std::vector<sf::Sprite>& getObstacles();

private:
    void generateObstacles();
    sf::Texture texture;
    std::vector<sf::Sprite> obstacles;
    int gap;
    int obstacleWidth;
    int obstacleHeight;
    int speed;
    int obstacleFrequency;
    int frame;
    sf::Clock clock; // cronometro 
    sf::Time elapsedTime; // tiempo desde q empieza
    bool gameStarted; // saber si el juego ya empezó
};

#endif
