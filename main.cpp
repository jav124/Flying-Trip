#include<SFML/Graphics.hpp>
#include"globals.hpp"
#include"game.hpp"
int main()
{
	sf::RenderWindow win(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Flappy Bird");
	Game game(win);
	game.startGameLoop();
	return 0;
}