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
    int frameCount;
    sf::Clock clock; // Cronómetro para medir el tiempo transcurrido
    sf::Time elapsedTime; // Tiempo transcurrido desde el inicio del juego
    bool gameStarted; // Bandera para controlar si el juego ha comenzado
};

#endif
