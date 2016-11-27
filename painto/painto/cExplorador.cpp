#include "stdafx.h"
#include "cExplorador.h"


cExplorador::cExplorador(cDocumento* doc, sf::RenderWindow* win)
{
	documento = doc;
	window = win;
}

void cExplorador::update()
{
	if (documento->nuevo||documento->estructura||documento->figuraSeleccionada)
	{
		window->clear();
		sf::Vector2f posicion(0,0);
		sf::Vector2f letras(2, 2);
		sf::Vector2f incremento(0, 24);


		for (list<cCapa*>::iterator it = documento->Capas.begin(); it != documento->Capas.end(); it++)
		{
			(*it)->contenedorNombre.setPosition(posicion);
			(*it)->contenedorNombre.setFillColor(sf::Color::Cyan);
			(*it)->contenedorNombre.setSize(sf::Vector2f(120,24));
			window->draw((*it)->contenedorNombre);
			(*it)->nombreFigura.setPosition(posicion+letras);
			(*it)->nombreFigura.setFillColor(sf::Color::Black);
			(*it)->nombreFigura.setCharacterSize(20);
			window->draw((*it)->nombreFigura);
			posicion += incremento;
			for (list <cFiguras*>::iterator fig = (*it)->Figuras.begin(); fig != (*it)->Figuras.end(); fig++)
			{
				(*fig)->contenedorNombre.setPosition(posicion);
				(*fig)->contenedorNombre.setFillColor(sf::Color::Cyan);
				(*fig)->contenedorNombre.setSize(sf::Vector2f(120, 24));
				window->draw((*fig)->contenedorNombre);
				(*fig)->nombreFigura.setPosition(posicion+letras);
				(*fig)->nombreFigura.setFillColor(sf::Color::Cyan);
				(*fig)->nombreFigura.setCharacterSize(20);
				window->draw((*fig)->nombreFigura);
				posicion += incremento;
			}
		}
		window->display();

	}
}


cExplorador::~cExplorador()
{
}
