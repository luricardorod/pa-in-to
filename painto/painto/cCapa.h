#pragma once
#include "cSeleccionable.h"
#include <list>
#include "cFiguras.h"
#include "Fabrica.h"

class cCapa:public cSeleccionable
{
public:
	list<cFiguras*> Figuras;
	int contador = 0;
public:
	cCapa();
	~cCapa();

	void Insertar(int clsId);
	void Eliminar(cFiguras* id);
	void Subir();
	void Bajar();

	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	void Dibujar(sf::RenderWindow &Ventana);
};