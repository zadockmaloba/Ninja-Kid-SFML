#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Background.h"
#include "Assets.h"

static void gameLoop(sf::RenderWindow* win);
//Background bgEdit();

int main()
{
	sf::RenderWindow win(sf::VideoMode(800, 600), "Ninja-Kid 0.1-Beta", sf::Style::Close | sf::Style::Resize);
	gameLoop(&win);
}

void gameLoop(sf::RenderWindow* win)
{
	Background bg(win, "woods_1.jpg", 2.0);
	Background bg2(win, "woods_view2.png", 3.0);
	Background bg3(win, "glacial/Layers/nuvens_1.png");
	bg2.move(0, -50);
	bg3.move(0, 100);
	bg.scale(1, 0.5);
	bg2.scale(1,0.8);
	bg3.scale(3, 2);

	Assets tree(win, "vegetation/tree_1.png", 3.5);
	tree.move(100, 270);
	tree.scale(0.4, 0.4);

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
		win->draw(bg2, sf::BlendMultiply);
		//win->draw(bg3, sf::BlendAdd);
		//win->draw(tree, sf::BlendAlpha);
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
					bg.parallaxMvmnt({ 1,0 });
					bg2.parallaxMvmnt({ 1,0 });
					bg3.parallaxMvmnt({1,0});
					tree.parallaxMvmnt({ 1,0 });
					ply.movement({ 1,0 });
					playerAction = "walk";}
				if (event.key.code == sf::Keyboard::Left) {
					ply.faceBack = true;
					bg.parallaxMvmnt({ -1,0 });
					bg2.parallaxMvmnt({ -1,0 });
					bg3.parallaxMvmnt({ -1,0 });
					tree.parallaxMvmnt({ -1,0 });
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
