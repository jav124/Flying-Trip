#include <SFML/Graphics.hpp> 
#include "bird.hpp"
using namespace sf; 
using namespace std;

float gravedad = 0; 
int salto = 0;

int main() { 

    
    sf::Texture pas; 
    pas.loadFromFile("./fondo.png"); 
    sf::Sprite fondo(pas);

    sf::Texture av;
    av.loadFromFile("./avionne.png");
    sf::Sprite avionne(av);


    bool play = false;
    RenderWindow window(VideoMode(700,510), "SFML works!");
    window.setFramerateLimit(60);

    RectangleShape bird(Vector2f(32.f,32.f));
    bird.setPosition(0,250);
    bird.setFillColor(Color::Black);

 

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    salto = -13;
                    gravedad = 1;
                }
            }

        }
        gravedad += 0.1;
        bird.move(0,gravedad);
        bird.move(0,salto);
        if (salto < 0) {
            salto += 1;
        }
    }  
    return 0;
}
