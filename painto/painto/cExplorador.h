#pragma once
#include "cObservador.h"
#include "cDocumento.h"

class cExplorador :
	public cObservador
{
public:
	void update();
	sf::RenderWindow* window;
	cDocumento* documento;
	cExplorador(cDocumento* doc, sf::RenderWindow* win);
	~cExplorador();
};

