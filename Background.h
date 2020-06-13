#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Background : public sf::Sprite
{
public:
	Background(sf::RenderWindow* win, std::string dir, float spd=3);
	~Background();
	void parallaxMvmnt(sf::Vector2f deltaLoc);

private:
	float mvmntRate;
	sf::Texture bgImage;
	std::string txtDir = "textures/BG/";
	sf::Vector2f bgLoc;
};

inline Background::Background(sf::RenderWindow* win, std::string dir, float spd) : mvmntRate(spd)
{
	bgImage.loadFromFile(txtDir + dir);
	sf::IntRect uvRect;
	this->setTexture(bgImage);
}

inline Background::~Background()
{
}

inline void Background::parallaxMvmnt(sf::Vector2f deltaLoc)
{
	bgLoc = this->getPosition();
	bgLoc.x -= (mvmntRate * deltaLoc.x);
	//bgLoc.y -= (jumpPower * deltaLoc.y);
	if (bgLoc.x < 0) this->setPosition(bgLoc);
}
