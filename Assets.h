#pragma once
#include <SFML/Graphics.hpp>

class Assets : public sf::Sprite
{
public:
	Assets(sf::RenderWindow* win, std::string dir, float spd = 3);
	~Assets();
	void parallaxMvmnt(sf::Vector2f deltaLoc);
	sf::Vector2u spriteSize();

private:
	float mvmntRate;
	sf::Texture bgImage;
	std::string txtDir = "textures/assets/";
	sf::Vector2f bgLoc;
};

inline Assets::Assets(sf::RenderWindow* win, std::string dir, float spd) : mvmntRate(spd)
{
	bgImage.loadFromFile(txtDir + dir);
	sf::IntRect uvRect;
	this->setTexture(bgImage);
}

inline Assets::~Assets()
{
}

inline void Assets::parallaxMvmnt(sf::Vector2f deltaLoc)
{
	bgLoc = this->getPosition();
	bgLoc.x -= (mvmntRate * deltaLoc.x);
	//bgLoc.y -= (jumpPower * deltaLoc.y);
	if (bgLoc.x < 0) this->setPosition(bgLoc);
}

inline sf::Vector2u Assets::spriteSize()
{
	return bgImage.getSize();
}
