#pragma once
#include <SFML/Graphics.hpp>

class Terrain : public sf::Sprite
{
public:
	Terrain();
	~Terrain();

private:
	sf::Texture terrainTextr;

};

inline Terrain::Terrain()
{
}

inline Terrain::~Terrain()
{
}
