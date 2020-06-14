#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Background.h"

static void gameLoop(sf::RenderWindow* win);
//Background bgEdit();

int main()
{
	sf::RenderWindow win(sf::VideoMode(800, 600), "Ninja-Kid 0.1-Beta", sf::Style::Close | sf::Style::Resize);
	gameLoop(&win);
}

void gameLoop(sf::RenderWindow* win)
{
	Background bg(win, "woods_1.jpg");
	Background bg2(win, "glacial/Layers/nuvens_2.png", 2.0);
	Background bg3(win, "glacial/Layers/nuvens_1.png");
	bg2.move(0, 100);
	bg3.move(0, 100);
	bg2.scale(3, 2);
	bg3.scale(3, 2);

	Player ply(win, {100,450});
	sf::Clock clock;
	float deltaTime = 0.0f;

	std::string playerAction = "";

	while (win->isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		win->clear();

		//draw objects**************
		win->draw(bg);
		win->draw(bg2);
		win->draw(bg3, sf::BlendAdd);
		win->draw(ply);
		//***************************

		sf::Event event;
		while (win->pollEvent(event))
		{
			if(event.type == sf::Event::Closed) win->close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::A) playerAction = "attack";
				if (event.key.code == sf::Keyboard::Right) {
					ply.faceBack = false;
					bg2.parallaxMvmnt({ 1,0 });
					bg3.parallaxMvmnt({1,0});
					ply.movement({ 1,0 });
					playerAction = "walk";}
				if (event.key.code == sf::Keyboard::Left) {
					ply.faceBack = true;
					bg2.parallaxMvmnt({ -1,0 });
					bg3.parallaxMvmnt({ -1,0 });
					ply.movement({ -1,0 });
					playerAction = "walk";}
			}
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::A) playerAction = "";
				if (event.key.code == sf::Keyboard::Right) playerAction = "";
				if (event.key.code == sf::Keyboard::Left) playerAction = "";
			}
		}
		ply.playerAnimation(deltaTime, playerAction);
		win->display();
	}
}
