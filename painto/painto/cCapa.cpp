#include "stdafx.h"
#include "cCapa.h"


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
	/*
	*/
	int sz;
	entrada >> sz;

	while (Figuras.size() < sz)
	{
		int shapeNumber;
		entrada >> shapeNumber;
		Figuras.push_back(CrearFigura(shapeNumber));
		Vector3f temp;
		entrada >> temp.x;
		entrada >> temp.y;
		entrada >> temp.z;
		(Figuras.back())->setColorLinea(temp);
		entrada >> temp.x;
		entrada >> temp.y;
		entrada >> temp.z;
		(Figuras.back())->setColorRelleno(temp);
		Point temp1;
		entrada >> temp1.x;
		entrada >> temp1.y;
		(Figuras.back())->setPosicion(temp1);
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