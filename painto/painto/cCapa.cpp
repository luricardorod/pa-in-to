#include "stdafx.h"
#include "cCapa.h"
#include <string>


cCapa::cCapa()
{
	visible = true;
	desbloqueado = true;
}

cCapa::~cCapa()
{

}

void cCapa::Insertar(int clsId)
{
	Figuras.push_front(CrearFigura(clsId));
	Figuras.front()->nombre = "figura " + to_string(contador);
	Figuras.front()->visible = true;
	Figuras.front()->desbloqueado = true;
	contador++;
}

void cCapa::Insertar(cFiguras *nuevo)
{
	Figuras.push_front(nuevo);
	Figuras.front()->nombre = "figura " + to_string(contador);
	Figuras.front()->desbloqueado = true;
	Figuras.front()->visible = true;
	contador++;
}

void cCapa::Eliminar(cFiguras* id)
{
	Figuras.remove(id);
}

bool cCapa::hitTest(Point mouseCoords)
{
	return false;
}

void cCapa::Guardar(ofstream &salida)
{
	salida << Figuras.size() << endl;
	for (list<cFiguras*>::iterator it = Figuras.begin(); it != Figuras.end(); ++it)
	{
		salida << (*it)->GetClsId() << endl;
		(*it)->Guardar(salida);
	}
}

void cCapa::Cargar(ifstream &entrada)
{
	int sz;
	string str;
	getline(entrada, str);
	sz = stoi(str);
	Figuras.clear();
	while (Figuras.size() < sz)
	{
		string str;
		Vector3f temp;
		int shapeNumber;
		getline(entrada, str);
		shapeNumber = stoi(str);
		Insertar(shapeNumber);
		(Figuras.front())->Cargar(entrada);
	}
}

int cCapa::GetClsId()
{
	return 0;
}

void cCapa::Dibujar(sf::RenderWindow &Ventana)
{
	for (list<cFiguras*>::reverse_iterator it = Figuras.rbegin(); it != Figuras.rend(); ++it)
	{
		if((*it)->visible)
			(*it)->Dibujar(Ventana);
	}
}