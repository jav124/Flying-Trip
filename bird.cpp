#include <SFML/Graphics.hpp>

class Avion {
public:
    sf::Texture texture;
    sf::Sprite sprite;

    Avion() {
        if (!texture.loadFromFile("./avionne.png")) {
            
        }
        sprite.setTexture(texture);
    }
};
