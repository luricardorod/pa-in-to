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
		switch (shapeNumber)
		{
		case ClsId_Rectangulo:
			Figuras.push_back(new cRectangulo());
			break;
		case ClsId_RectanguloRedondeado:
			Figuras.push_back(new cRectanguloRedondeado());
			break;
		case ClsId_Elipse:
			Figuras.push_back(new cElipse());
			break;
		case ClsId_Triangulo:
			Figuras.push_back(new cTriangulo());
			break;
		case ClsId_Polignos:
			Figuras.push_back(new cPoligonos());
			break;
		case ClsId_CurvaBezier:
			Figuras.push_back(new cCurvaBezier());
			break;
		case ClsId_Linea:
			Figuras.push_back(new cLinea());
			break;
		case ClsId_TiraDeLinea:
			Figuras.push_back(new cTiraDeLinea());
			break;
		case ClsId_Texto:
			Figuras.push_back(new cTexto());
			break;
		default:
			break;
		}
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