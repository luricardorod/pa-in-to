#include "stdafx.h"
#include "Fabrica.h"


cFiguras* CrearFigura(int shapeNumber)
{
	switch (shapeNumber)
	{
	case ClsId_Rectangulo:
		return new cRectangulo();
		break;
	case ClsId_RectanguloRedondeado:
		return new cRectanguloRedondeado();
		break;
	case ClsId_Elipse:
		return new cElipse();
		break;
	case ClsId_Triangulo:
		return new cTriangulo();
		break;
	case ClsId_Poligono:
		return new cPoligonos();
		break;
	case ClsId_CurvaBezier:
		return new cCurvaBezier();
		break;
	case ClsId_Linea:
		return new cLinea();
		break;
	case ClsId_TiraDeLinea:
		return new cTiraDeLinea();
		break;
	case ClsId_Texto:
		return new cTexto();
		break;
	default:
		break;
	}
}

