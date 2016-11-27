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
		for (list<cCapa*>::iterator it = documento->Capas.begin(); it != documento->Capas.end(); it++)
		{
			window->draw((*it)->contenedorNombre);
			window->draw((*it)->nombreFigura);
			for (list <cFiguras*>::iterator fig = (*it)->Figuras.begin(); fig != (*it)->Figuras.end(); fig++)
			{
				window->draw((*fig)->contenedorNombre);
				window->draw((*fig)->nombreFigura);
			}
		}
		window->display();

	}
}


cExplorador::~cExplorador()
{
}
