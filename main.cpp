#include "obstacle.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace sf;
using namespace std;

float gravedad = 0;
int salto = 0;
bool gameOver = false;

int main() {
    sf::Texture pas;
    pas.loadFromFile("./fondo.png");
    sf::Sprite fondo(pas);

    sf::Texture av;
    av.loadFromFile("./avionne.png");
    sf::Sprite avionne(av);

    RenderWindow window(VideoMode(700, 410), "SFML Flappy Bird");
    window.setFramerateLimit(60);

    RectangleShape bird(Vector2f(32.f, 32.f));
    bird.setPosition(50, 250);
    bird.setFillColor(Color::Black);

    Obstacles obstacles;

    Clock clock;
    float tiempoTranscurrido = 0;

    Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "Error cargando la fuente, utilizando la fuente predeterminada de SFML" << endl;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    if (gameOver) {
                        bird.setPosition(50, 250);
                        gravedad = 0;
                        salto = 0;
                        gameOver = false;
                        obstacles.reset();
                        clock.restart();
                        tiempoTranscurrido = 0;
                    } else {
                        salto = -13;
                        gravedad = 2;
                    }
                }
            }
        }

        if (!gameOver) {
            gravedad += 0.1;
            bird.move(0, gravedad);
            bird.move(0, salto);
            if (salto < 0) {
                salto += 1;
            }

            if (bird.getPosition().y + bird.getSize().y >= 410) {
                bird.setPosition(bird.getPosition().x, 410 - bird.getSize().y);
                gravedad = 0;
                salto = 0;
                gameOver = true;
            }

            if (bird.getPosition().y <= 0) {
                bird.setPosition(bird.getPosition().x, 0);
                gravedad = 0;
                salto = 0;
                gameOver = true;
            }

            for (auto& obstacle : obstacles.getObstacles()) {
                if (bird.getGlobalBounds().intersects(obstacle.getGlobalBounds())) {
                    gameOver = true;
                    break;
                }
            }

            avionne.setPosition(bird.getPosition());
            avionne.setScale(.3f, .3f);

            obstacles.update();

            tiempoTranscurrido = clock.getElapsedTime().asSeconds();
        }

        window.clear();
        window.draw(fondo);
        window.draw(avionne);
        obstacles.draw(window);
        
        if (gameOver) {
            Text text;
            text.setFont(font);
            text.setString("Tiempo: " + to_string(tiempoTranscurrido) + "s");
            text.setCharacterSize(24);
            text.setFillColor(Color::Green);
            text.setPosition(10, 10);
            window.draw(text);
        }

        window.display();
    }

    return 0;
}


