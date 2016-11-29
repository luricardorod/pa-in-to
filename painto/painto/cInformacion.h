#pragma once
#include "cObservador.h"
#include "cDocumento.h"

class cInformacion :
	public cObservador
{
public:
	void update();
	sf::RenderWindow* window;
	cDocumento* documento;
	cInformacion(cDocumento* doc, sf::RenderWindow* win);
	~cInformacion();
};

