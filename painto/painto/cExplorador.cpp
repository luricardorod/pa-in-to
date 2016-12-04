#include "stdafx.h"
#include "cExplorador.h"
#include <iostream>

cExplorador::cExplorador(cDocumento* doc, sf::RenderWindow* win)
{
	documento = doc;
	window = win;
	
	texturasCapas[0].loadFromFile("Assets/capa.png");
	texturasCapas[1].loadFromFile("Assets/arriba.png");
	texturasCapas[2].loadFromFile("Assets/abajo.png");
	texturasCapas[3].loadFromFile("Assets/ojo.png");
	texturasCapas[4].loadFromFile("Assets/open.png");
	texturasCapas[5].loadFromFile("Assets/eliminar.png");
	texturasCapas[6].loadFromFile("Assets/ojo2.png");
	texturasCapas[7].loadFromFile("Assets/close.png");

	
	for (int i = 0; i < 6; i++)
	{
		botones[i].setTexture(texturasCapas[i]);
		botones[i].setPosition(874 + i * 25, 630);
		botones[i].setScale((float)25 / 200, (float)25 / 200);
	}
}
void cExplorador::checarClick(Point clickMouse)
{
	for (int i = 0; i < 6; i++) //Buscar a que "boton" le dio clic
	{
		if (botones[i].getGlobalBounds().contains(clickMouse.x, clickMouse.y)) {
			switch (i)
			{
			case 0:
				cout << "nueva capa" << endl; //imprimir numero de boton
				documento->Insertar();
				return;
				break;
			case 1:
				cout << "subir" << endl; //imprimir numero de boton
				return;
				break;
			case 2:
				cout << "bajar" << endl; //imprimir numero de boton
				return;
				break;
			case 3:
				cout << "visible" << endl; //imprimir numero de boton
				if (documento->capaActual != 0)
				{
					if (documento->figuraActual == 0)
					{
						cout << "visible capa" << endl; //imprimir numero de boton
						documento->capaActual->visible = !documento->capaActual->visible;
					}
					else
					{
						cout << "visible figura" << endl; //imprimir numero de boton
						documento->figuraActual->visible = !documento->figuraActual->visible;
					}
				}
				return;
				break;
			case 4:
				cout << "bloquear" << endl; //imprimir numero de boton
				if (documento->capaActual != 0)
				{
					if (documento->figuraActual == 0)
					{
						cout << "visible capa" << endl; //imprimir numero de boton
						documento->capaActual->desbloqueado = !documento->capaActual->desbloqueado;
					}
					else
					{
						cout << "visible figura" << endl; //imprimir numero de boton
						documento->figuraActual->desbloqueado = !documento->figuraActual->desbloqueado;
					}
				}
				return;
				break;
			case 5:
				cout << "eliminar" << endl; //imprimir numero de boton
				if (documento->capaActual != 0)
				{
					if (documento->figuraActual == 0)
					{
						documento->Eliminar();
						documento->capaActual = NULL;
						documento->figuraActual = NULL;
					}
					else
					{
						documento->capaActual->Eliminar(documento->figuraActual);
						documento->figuraActual = NULL;
					}
				}
				return;
				break;
			default:
				break;
			}
		}
	}
	for (int i = 0; i < rectangulos.size(); i++)
	{
		if (rectangulos[i].getGlobalBounds().contains(clickMouse.x, clickMouse.y))
		{
			documento->cambiarSeleccionado(seleccionables[i]);
			return;
		}
	}
}
void cExplorador::update() {
	rectangulos.clear();
	seleccionables.clear();
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
		rectangulos.push_back(recTemp);
		if ((*it) == documento->capaActual)
		{
			recTemp.setFillColor(sf::Color::Red);
		}
		seleccionables.push_back((*it));
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
			rectangulos.push_back(FigRecTemp);
			seleccionables.push_back((*figit));
			if ((*figit) == documento->figuraActual)
			{
				FigRecTemp.setFillColor(sf::Color::Blue);
			}
			window->draw(FigRecTemp);

			sf::Text nombreTemporalFig((*figit)->nombre, fuente);
			nombreTemporalFig.setCharacterSize(20);
			nombreTemporalFig.setPosition(posicion + letras + sf::Vector2f(15,0));
			nombreTemporalFig.setFillColor(sf::Color::Black);
			window->draw(nombreTemporalFig);
			posicion += incremento;
		}
	}
	cSeleccionable* itemSeleccionado = NULL;
	if (documento->capaActual != 0)
	{
		if (documento->figuraActual == 0)
		{
			itemSeleccionado = documento->capaActual;
		}
		else
		{	
			itemSeleccionado = documento->figuraActual;
		}
	}
	if (itemSeleccionado && itemSeleccionado->visible == 0)
	{
		botones[3].setTexture(texturasCapas[6]);
	}
	else
	{
		botones[3].setTexture(texturasCapas[3]);
	}
	if (itemSeleccionado && itemSeleccionado->desbloqueado == 0)
	{
		botones[4].setTexture(texturasCapas[7]);
	}
	else
	{
		botones[4].setTexture(texturasCapas[4]);
	}
	for (int i = 0; i < 6; i++)
		window->draw(botones[i]);
}

cExplorador::~cExplorador()
{
}
