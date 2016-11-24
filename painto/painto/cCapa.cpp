#include "stdafx.h"
#include "cCapa.h"
#include <string>


cCapa::cCapa()
{

}

cCapa::~cCapa()
{

}

void cCapa::Insertar()
{

}

void cCapa::Eliminar()
{

}

void cCapa::Subir()
{

}

void cCapa::Bajar()
{

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
		salida << (*it)->getColorLinea().x << endl;
		salida << (*it)->getColorLinea().y << endl;
		salida << (*it)->getColorLinea().z << endl;
		salida << (*it)->getColorRelleno().x << endl;
		salida << (*it)->getColorRelleno().y << endl;
		salida << (*it)->getColorRelleno().z << endl;
		salida << (*it)->getPosition().x << endl;
		salida << (*it)->getPosition().y << endl;
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

		int shapeNumber;
		getline(entrada, str);
		shapeNumber = stoi(str);
		Figuras.push_back(CrearFigura(shapeNumber));
		(Figuras.back())->Cargar(entrada);
	}
}

int cCapa::GetClsId()
{
	return 0;
}

void cCapa::Dibujar()
{
	for (list<cFiguras*>::iterator it = Figuras.begin(); it != Figuras.end(); ++it)
		(*it)->Dibujar();
}