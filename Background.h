#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Background : public sf::Sprite
{
public:
	Background(sf::RenderWindow* win);
	~Background();

private:
	sf::Texture bgImage;
	std::string txtDir = "textures/BG/";
};

inline Background::Background(sf::RenderWindow* win)
{
	bgImage.loadFromFile(txtDir + "woods_1.jpg");
	bgImage.setSmooth(true);
	sf::IntRect uvRect;
	this->setTextureRect(uvRect);
	uvRect.top = 200;
	this->setTexture(bgImage);
	this->move(0, -300);
	//this->scale(win->getSize().x /2, win->getSize().y /2);
}

inline Background::~Background()
{
}
