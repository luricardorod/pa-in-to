#pragma once
#include "CDibujable.h"
#include "cCapa.h"
#include <list>

class cDocumento:public CDibujable
{
public:
	list<cCapa*> Capas;
	cCapa *capaActual;
	cFiguras* figuraActual;

	int contador = 0;
public:
	cDocumento();
	~cDocumento();

	void Subir();
	void Bajar();
	void Insertar();
	void Eliminar();

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	void Dibujar(sf::RenderWindow &Ventana);
	void cambiarSeleccionado(cSeleccionable* nuevaSeleccion);
};