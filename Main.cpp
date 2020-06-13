#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Background.h"

static void gameLoop(sf::RenderWindow* win);

int main()
{
	sf::RenderWindow win(sf::VideoMode(800, 600), "Ninja-Kid 0.1-Beta", sf::Style::Close | sf::Style::Resize);
	gameLoop(&win);
}

void gameLoop(sf::RenderWindow* win)
{
	Background bg(win);
	Player ply(win, {100,100}, &bg);
	sf::Clock clock;
	float deltaTime = 0.0f;

	std::string playerAction = "";

	while (win->isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		win->clear();

		//draw objects
		win->draw(bg); 
		win->draw(ply);
		//***************************

		sf::Event event;
		while (win->pollEvent(event))
		{
			if(event.type == sf::Event::Closed) win->close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::A) playerAction = "attack";
				if (event.key.code == sf::Keyboard::Right) {
					ply.movement({ 1,0 });
					playerAction = "walk";}
				if (event.key.code == sf::Keyboard::Left) {
					ply.movement({ -1,0 });
					playerAction = "walk";}
			}
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::A) playerAction = "";
				if (event.key.code == sf::Keyboard::Right) playerAction = "";
			}
		}
		ply.playerAnimation(deltaTime, playerAction);
		win->display();
	}
}
