#include "stdafx.h"
#include "cExplorador.h"
#include <iostream>

cExplorador::cExplorador(cDocumento* doc, sf::RenderWindow* win)
{
	documento = doc;
	window = win;
}
void cExplorador::update() {
	sf::Font fuente;
	fuente.loadFromFile("comic.ttf");

	sf::Vector2f posicion(874, 40);
	sf::Vector2f letras(2, 2);
	sf::Vector2f incremento(0, 24);
	for (list<cCapa*>::iterator it = documento->Capas.begin(); it != documento->Capas.end(); it++)
	{
		sf::RectangleShape recTemp;
		recTemp.setPosition(posicion);
		recTemp.setFillColor(sf::Color::Cyan);
		recTemp.setSize(sf::Vector2f(150, 24));
		window->draw(recTemp);

		sf::Text nombreTemporal((*it)->nombre, fuente);
		nombreTemporal.setCharacterSize(20);
		nombreTemporal.setPosition(posicion + letras);
		nombreTemporal.setFillColor(sf::Color::Black);
		window->draw(nombreTemporal);

		posicion += incremento;
		for (list<cFiguras*>::iterator figit =(*it)->Figuras.begin(); figit != (*it)->Figuras.end(); figit++)
		{
			sf::RectangleShape FigRecTemp;
			FigRecTemp.setPosition(posicion);
			FigRecTemp.setFillColor(sf::Color::Green);
			FigRecTemp.setSize(sf::Vector2f(150, 24));
			window->draw(FigRecTemp);

			sf::Text nombreTemporalFig((*figit)->nombre, fuente);
			nombreTemporalFig.setCharacterSize(20);
			nombreTemporalFig.setPosition(posicion + letras + sf::Vector2f(15,0));
			nombreTemporalFig.setFillColor(sf::Color::Black);
			window->draw(nombreTemporalFig);
			posicion += incremento;
		}
	}
}

cExplorador::~cExplorador()
{
}
