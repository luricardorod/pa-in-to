#include "stdafx.h"
#include "cDocumento.h"
#include <string>
#include <iostream>
cDocumento::cDocumento()
{

}

cDocumento::~cDocumento()
{

}

void cDocumento::Subir()
{
	int counter = 0;
	if (capaActual == Capas.front())
	{
		return;
	}
	for (list<cCapa*>::iterator it = Capas.begin(); it != Capas.end(); ++it)
	{
		if ((*it)== capaActual)
		{
			list<cCapa*>::iterator lu = Capas.begin();
			advance(lu, counter-1);
			Capas.splice(lu, Capas, it);
			return;
		}
		counter++;
	}
}
void cDocumento::SubirFigura()
{
	int counter = 0;
	if (figuraActual == capaActual->Figuras.front())
	{
		if (capaActual == Capas.front())
		{
			return;
		}
		else
		{
			for (list<cCapa*>::iterator it = Capas.begin(); it != Capas.end(); ++it)
			{
				if ((*it) == capaActual)
				{
					list<cCapa*>::iterator lu = Capas.begin();
					advance(lu, counter - 1);
					(*lu)->Figuras.splice((*lu)->Figuras.end(), capaActual->Figuras, capaActual->Figuras.begin());
					capaActual = (*lu);
					return;
				}
				counter++;
			}
		}
	}
	else
	{
		for (list<cFiguras*>::iterator it = capaActual->Figuras.begin(); it != capaActual->Figuras.end(); ++it)
		{
			if ((*it) == figuraActual)
			{
				list<cFiguras*>::iterator lu = capaActual->Figuras.begin();
				advance(lu, counter - 1);
				capaActual->Figuras.splice(lu, capaActual->Figuras, it);
				return;
			}
			counter++;
		}
	}

}

void cDocumento::BajarFigura()
{
	int counter = 0;
	if (figuraActual == capaActual->Figuras.back())
	{
		if (capaActual == Capas.back())
		{
			return;
		}
		else
		{
			for (list<cCapa*>::iterator it = Capas.begin(); it != Capas.end(); ++it)
			{
				if ((*it) == capaActual)
				{
					list<cCapa*>::iterator lu = Capas.begin();
					advance(lu, counter + 1);
					list<cFiguras*>::iterator lol = capaActual->Figuras.end();
					lol--;
					(*lu)->Figuras.splice((*lu)->Figuras.begin(), capaActual->Figuras, lol);
					capaActual = (*lu);
					return;
				}
				counter++;
			}
		}
	}
	else
	{
		for (list<cFiguras*>::iterator it = capaActual->Figuras.begin(); it != capaActual->Figuras.end(); ++it)
		{
			if ((*it) == figuraActual)
			{
				list<cFiguras*>::iterator lu = capaActual->Figuras.begin();
				advance(lu, counter + 2);
				capaActual->Figuras.splice(lu, capaActual->Figuras, it);
				return;
			}
			counter++;
		}
	}

}

void cDocumento::Bajar()
{
	int counter = 0;
	if (capaActual == Capas.back())
	{
		return;
	}
	for (list<cCapa*>::iterator it = Capas.begin(); it != Capas.end(); ++it)
	{
		if ((*it) == capaActual)
		{
			list<cCapa*>::iterator lu = Capas.begin();
			advance(lu, counter + 2);
			Capas.splice(lu, Capas, it);
			return;
		}
		counter++;
	}
}

void cDocumento::Insertar()
{
	Capas.push_back(new cCapa());
	capaActual = Capas.back();
	capaActual->nombre = "Capa " + to_string(contador);
	figuraActual = NULL;
	contador++;
}

void cDocumento::Eliminar()
{
	capaActual->Figuras.clear();
	Capas.remove(capaActual);

}

void cDocumento::Guardar(ofstream &salida)
{
	salida << Capas.size() << endl;
	for (list<cCapa*>::iterator it = Capas.begin(); it != Capas.end(); ++it)
	{
		(*it)->Guardar(salida);
	}
}

void cDocumento::Cargar(ifstream &entrada)
{
	int sz;
	string str;
	getline(entrada, str);
	
	sz = stoi(str);
	
	Capas.clear();
	while (Capas.size() < sz)
	{
		Insertar();
		Capas.back()->Cargar(entrada);
	}
	capaActual = Capas.back();
	figuraActual = capaActual->Figuras.front();
}

int cDocumento::GetClsId()
{
	return 0;
}

void cDocumento::Dibujar(sf::RenderWindow &Ventana)
{
	for (list<cCapa*>::reverse_iterator it = Capas.rbegin(); it != Capas.rend(); ++it)
	{
		if((*it)->visible)
			(*it)->Dibujar(Ventana);
	}

	if (figuraActual == NULL)
	{
		return;
	}
	if (figuraActual->GetClsId() < 6)
	{
		sf::RectangleShape figSec;
		figSec.setSize(sf::Vector2f(figuraActual->infoFig->getGlobalBounds().width, figuraActual->infoFig->getGlobalBounds().height));
		figSec.setOutlineThickness(3);
		figSec.setOutlineColor(sf::Color::Blue);
		figSec.setFillColor(sf::Color::Transparent);
		figSec.setPosition(sf::Vector2f(figuraActual->infoFig->getGlobalBounds().left, figuraActual->infoFig->getGlobalBounds().top));
		Ventana.draw(figSec);
	}
	else if (figuraActual->GetClsId() == 6)
	{

		sf::RectangleShape select;
		float pMayor = 0, pMenor = 720 , pDer = 0, pIzq = 1080;
		for (int i = 0; i < ((cCurvaBezier*)(figuraActual))->tamano; i++)
		{
			pMenor =((cCurvaBezier*)(figuraActual))->vertices[i].position.y < pMenor? ((cCurvaBezier*)(figuraActual))->vertices[i].position.y : pMenor;
			pMayor = ((cCurvaBezier*)(figuraActual))->vertices[i].position.y > pMayor ? ((cCurvaBezier*)(figuraActual))->vertices[i].position.y : pMayor;
			pDer = ((cCurvaBezier*)(figuraActual))->vertices[i].position.x > pDer ? ((cCurvaBezier*)(figuraActual))->vertices[i].position.x : pDer;
			pIzq = ((cCurvaBezier*)(figuraActual))->vertices[i].position.x < pIzq ? ((cCurvaBezier*)(figuraActual))->vertices[i].position.x : pIzq;
		}
		select.setSize(sf::Vector2f(pDer-pIzq, pMayor-pMenor));		
		select.setOutlineThickness(3);
		select.setOutlineColor(sf::Color::Blue);
		select.setFillColor(sf::Color::Transparent);
		select.setPosition(sf::Vector2f( ((pDer+pIzq) / 2) - ((pDer-pIzq)/2), ((pMayor+pMenor)/2) - ((pMayor-pMenor)/2)));
		Ventana.draw(select);
	}
	else if (figuraActual->GetClsId() == 7)
	{
		sf::RectangleShape select;
		float pMayor = 0, pMenor = 720, pDer = 0, pIzq = 1080;
		for (int i = 0; i < ((cLinea*)(figuraActual))->tamano; i++)
		{
			pMenor = ((cLinea*)(figuraActual))->vertices[i].position.y < pMenor ? ((cLinea*)(figuraActual))->vertices[i].position.y : pMenor;
			pMayor = ((cLinea*)(figuraActual))->vertices[i].position.y > pMayor ? ((cLinea*)(figuraActual))->vertices[i].position.y : pMayor;
			pDer = ((cLinea*)(figuraActual))->vertices[i].position.x > pDer ? ((cLinea*)(figuraActual))->vertices[i].position.x : pDer;
			pIzq = ((cLinea*)(figuraActual))->vertices[i].position.x < pIzq ? ((cLinea*)(figuraActual))->vertices[i].position.x : pIzq;
		}
		select.setSize(sf::Vector2f(pDer - pIzq, pMayor - pMenor));
		select.setOutlineThickness(3);
		select.setOutlineColor(sf::Color::Blue);
		select.setFillColor(sf::Color::Transparent);
		select.setPosition(sf::Vector2f(((pDer + pIzq) / 2) - ((pDer - pIzq) / 2), ((pMayor + pMenor) / 2) - ((pMayor - pMenor) / 2)));
		Ventana.draw(select);
	}
	else if (figuraActual->GetClsId() == 8)
	{

		sf::RectangleShape select;
		float pMayor = 0, pMenor = 720, pDer = 0, pIzq = 1080;
		for (int i = 0; i < ((cTiraDeLinea*)(figuraActual))->tamano; i++)
		{
			pMenor = ((cTiraDeLinea*)(figuraActual))->vertices[i].position.y < pMenor ? ((cTiraDeLinea*)(figuraActual))->vertices[i].position.y : pMenor;
			pMayor = ((cTiraDeLinea*)(figuraActual))->vertices[i].position.y > pMayor ? ((cTiraDeLinea*)(figuraActual))->vertices[i].position.y : pMayor;
			pDer = ((cTiraDeLinea*)(figuraActual))->vertices[i].position.x > pDer ? ((cTiraDeLinea*)(figuraActual))->vertices[i].position.x : pDer;
			pIzq = ((cTiraDeLinea*)(figuraActual))->vertices[i].position.x < pIzq ? ((cTiraDeLinea*)(figuraActual))->vertices[i].position.x : pIzq;
		}
		select.setSize(sf::Vector2f(pDer - pIzq, pMayor - pMenor));
		select.setOutlineThickness(3);
		select.setOutlineColor(sf::Color::Blue);
		select.setFillColor(sf::Color::Transparent);
		select.setPosition(sf::Vector2f(((pDer + pIzq) / 2) - ((pDer - pIzq) / 2), ((pMayor + pMenor) / 2) - ((pMayor - pMenor) / 2)));
		Ventana.draw(select);
	}
	else if (figuraActual->GetClsId() == 9)
	{
		sf::RectangleShape figSec;
		figSec.setSize(sf::Vector2f( ((cTexto*)(figuraActual))->cajaTexto.getGlobalBounds().width, ((cTexto*)(figuraActual))->cajaTexto.getGlobalBounds().height));
		figSec.setOutlineThickness(3);
		figSec.setOutlineColor(sf::Color::Blue);
		figSec.setFillColor(sf::Color::Transparent);
		figSec.setPosition(sf::Vector2f(((cTexto*)(figuraActual))->cajaTexto.getGlobalBounds().left, ((cTexto*)(figuraActual))->cajaTexto.getGlobalBounds().top));
		Ventana.draw(figSec);
	}
}

void cDocumento::cambiarSeleccionado(cSeleccionable * nuevaSeleccion)
{
	int tipo = nuevaSeleccion->GetClsId();
	if (tipo == 0)
	{
		capaActual = ((cCapa*)(nuevaSeleccion));
		figuraActual = NULL;
	}
	else {
		figuraActual = ((cFiguras*)(nuevaSeleccion));
		for (list<cCapa*>::iterator it = Capas.begin(); it != Capas.end(); it++)
		{
			for (list<cFiguras*>::iterator figit = (*it)->Figuras.begin(); figit != (*it)->Figuras.end(); figit++)
			{
				if ((*figit) == figuraActual)
				{
					capaActual = (*it);
					return;
				}
			}
		}
	}
}
