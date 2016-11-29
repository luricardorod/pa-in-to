#include "stdafx.h"
#include "cInformacion.h"


cInformacion::cInformacion(cDocumento* doc, sf::RenderWindow* win)
{
	documento = doc;
	window = win;
}


cInformacion::~cInformacion()
{
}

void cInformacion::update() {
	//tamaño de ventanoa (1024, 60) posicion  660
	// debe de mostrar que figura su posicion, color en rgb del relleno y de la linea
	// ademas imprimir la informacion de cada figura info()
}