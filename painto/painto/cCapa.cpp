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

void cCapa::Guardar(ofstream & salida)
{
	salida << Figuras.size() << endl;
	for (std::list<cFiguras>::iterator it = Figuras.begin(); it != Figuras.end(); ++it)
	{
		salida << (*it).GetClsId() << endl;
		(*it).Guardar(salida);
	}
}

void cCapa::Cargar(ifstream & entrada)
{
	int sz;
	entrada >> sz;

	while (Figuras.size() < sz)
	{
		int shapeNumber;
		entrada >> shapeNumber;
		switch (shapeNumber)
		{
		case ClsId_Rectangulo:
			Figuras.push_back(cRectangulo());
			break;
		case ClsId_RectanguloRedondeado:
			Figuras.push_back(cRectanguloRedondeado());
			break;
		case ClsId_Elipse:
			Figuras.push_back(cElipse());
			break;
		case ClsId_Triangulo:
			Figuras.push_back(cTriangulo());
			break;
		case ClsId_Polignos:
			Figuras.push_back(cPoligonos());
			break;
		case ClsId_CurvaBezier:
			Figuras.push_back(cCurvaBezier());
			break;
		case ClsId_Linea:
			Figuras.push_back(cLinea());
			break;
		case ClsId_TiraDeLinea:
			Figuras.push_back(cTiraDeLinea());
			break;
		case ClsId_Texto:
			Figuras.push_back(cTexto());
			break;
		default:
			break;
		}

		Figuras.back().Cargar(entrada);
	}
}

int cCapa::GetClsId()
{
	return 0;
}

void cCapa::Dibujar()
{

}