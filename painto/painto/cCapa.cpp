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
	Figuras.push_back(CrearFigura(clsId));
	Figuras.back()->nombre = "figura " + to_string(contador);
	Figuras.back()->visible = true;
	Figuras.back()->desbloqueado = true;
	contador++;
}

void cCapa::Insertar(cFiguras *nuevo)
{
	Figuras.push_back(nuevo);
	Figuras.back()->nombre = "figura " + to_string(contador);
	Figuras.back()->desbloqueado = true;
	Figuras.back()->visible = true;
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
		salida << (*it)->getColorLinea().x << endl;
		salida << (*it)->getColorLinea().y << endl;
		salida << (*it)->getColorLinea().z << endl;
		salida << (*it)->getColorRelleno().x << endl;
		salida << (*it)->getColorRelleno().y << endl;
		salida << (*it)->getColorRelleno().z << endl;
		salida << (*it)->getPosition().x << endl;
		salida << (*it)->getPosition().y << endl;

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
		(Figuras.back())->Cargar(entrada);

		getline(entrada, str);
		temp.x = stof(str);
		getline(entrada, str);
		temp.y = stof(str);
		getline(entrada, str);
		temp.z = stof(str);
		(Figuras.back())->setColorLinea(temp);
		
		getline(entrada, str);
		temp.x = stof(str);
		getline(entrada, str);
		temp.y = stof(str);
		getline(entrada, str);
		temp.z = stof(str);
		(Figuras.back())->setColorRelleno(temp);

		Point temp1;
		getline(entrada, str);
		temp1.x = stof(str);
		getline(entrada, str);
		temp1.y = stof(str);
		(Figuras.back())->setPosicion(temp1);
	}
}

int cCapa::GetClsId()
{
	return 0;
}

void cCapa::Dibujar(sf::RenderWindow &Ventana)
{
	for (list<cFiguras*>::iterator it = Figuras.begin(); it != Figuras.end(); ++it)
	{
		if((*it)->visible)
			(*it)->Dibujar(Ventana);
	}
}