#pragma once
#include <SFML\Graphics.hpp>

class cLineType
{
public:
	sf::VertexArray vertices;
	int tamano = 0;
public:
	cLineType();
	~cLineType();
	virtual void setMove(float x, float y);
	virtual void setColor(sf::Color newColor);
};