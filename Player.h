#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Background.h"

class Player : public sf::Sprite 
{
public:
	Player (sf::RenderWindow* win, sf::Vector2f loc);
	~Player ();
	void playerAnimation(float deltaTime, std::string action);
	void movement(sf::Vector2f deltaLoc);
	bool faceBack;

private:
	int walkingRate = 3, runningRate=3, jumpPower=10;
	sf::Vector2f playerLoc, bgLoc;
	sf::Texture plyrTexture;
	std::string txtDir = "textures/player/";
	int imageCount = 9, imgIndex = 0;
	float switchTime = 0.06f, totalTime = 0.0f;
	std::vector<std::string> animCallback;
	std::vector<std::string> idleAnimText{
		txtDir + "Idle__000.png",txtDir + "Idle__001.png",txtDir + "Idle__002.png",txtDir + "Idle__003.png",
		txtDir + "Idle__004.png",txtDir + "Idle__005.png",txtDir + "Idle__006.png",
		txtDir + "Idle__007.png",txtDir + "Idle__008.png",txtDir + "Idle__009.png" };
	std::vector<std::string> attackAnimText{
		txtDir + "Attack__000.png",txtDir + "Attack__001.png",txtDir + "Attack__002.png",txtDir + "Attack__003.png",
		txtDir + "Attack__004.png",txtDir + "Attack__005.png",txtDir + "Attack__006.png",
		txtDir + "Attack__007.png",txtDir + "Attack__008.png",txtDir + "Attack__009.png" };
	std::vector<std::string> runAnimText{
		txtDir + "Run__000.png",txtDir + "Run__001.png",txtDir + "Run__002.png",txtDir + "Run__003.png",
		txtDir + "Run__004.png",txtDir + "Run__005.png",txtDir + "Run__006.png",
		txtDir + "Run__007.png",txtDir + "Run__008.png",txtDir + "Run__009.png" };
};

inline Player::Player(sf::RenderWindow* win, sf::Vector2f loc)
	:
	playerLoc(loc), faceBack(true)
{
	this->move(playerLoc);
	this->setScale(0.2, 0.2);
	
}

inline Player ::~Player ()
{
}

inline void Player::playerAnimation(float deltaTime, std::string action)
{
	if (action == "attack")  animCallback = attackAnimText;
	if (action == "walk") animCallback = runAnimText;
	else if (action == "") animCallback = idleAnimText;

	if (faceBack)this->scale(-1, 1);
	totalTime += deltaTime;
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		plyrTexture.loadFromFile(animCallback[imgIndex]);
		this->setTexture(plyrTexture, true);
		imgIndex++;
		if (imgIndex >= 10) {
			imgIndex = 0;}
	}
}

inline void Player::movement(sf::Vector2f deltaLoc)
{
	playerLoc.x += (walkingRate * deltaLoc.x);
	playerLoc.y += (jumpPower * deltaLoc.y);
	this->setPosition(playerLoc);
}


