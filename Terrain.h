#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Terrain : public sf::Sprite
{
public:
	Terrain(std::string dir, sf::Vector2f coordinates);
	~Terrain();

private:
	sf::Texture terrainTextr;
	sf::IntRect uvMap;

};

inline Terrain::Terrain(std::string dir, sf::Vector2f coordinates)
{
}

inline Terrain::~Terrain()
{
}
