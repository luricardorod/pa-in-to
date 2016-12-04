#pragma once
#include "cObservador.h"
#include "cDocumento.h"
#include <vector>

class cExplorador :
	public cObservador
{
public:
	vector<sf::RectangleShape> rectangulos;
	vector<cSeleccionable*> seleccionables;
	bool hitTestExplorador;
	void update();
	sf::RenderWindow* window;
	sf::Texture texturasCapas[8];
	sf::Sprite botones[6];
	cDocumento* documento;
	cExplorador(cDocumento* doc, sf::RenderWindow* win);
	void checarClick(Point clickMouse);
	~cExplorador();
};

