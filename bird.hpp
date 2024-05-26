#ifndef bird_hpp
#define bird_hpp

#include <SFML/Graphics.hpp>

class Avion {
public:
    Avion();
    sf::Sprite getSprite();
    void setPosition(float x, float y);

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif 
