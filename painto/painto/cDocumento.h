#pragma once
#include "CDibujable.h"
#include "cCapa.h"
#include <list>

class cDocumento:public CDibujable
{
public:
	list<cCapa*> Capas;
	cCapa *capaActual;
public:
	bool nuevo = true;
	bool estructura = true;
	bool figuraSeleccionada = true;
	bool visual = true;

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
};