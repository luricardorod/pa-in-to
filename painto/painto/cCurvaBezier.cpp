#include "stdafx.h"
#include "cCurvaBezier.h"
#include <string>

std::vector<sf::Vector2f> CalcCubicBezier( const sf::Vector2f &start, const sf::Vector2f &end, const sf::Vector2f &startControl, const sf::Vector2f &endControl, const size_t numSegments)
{
	std::vector<sf::Vector2f> ret;
	if (!numSegments) // Any points at all?
		return ret;

	ret.push_back(start); // First point is fixed
	float p = 1.f / numSegments;
	float q = p;
	for (size_t i = 1; i < numSegments; i++, p += q) // Generate all between
		ret.push_back(p * p * p * (end + 3.f * (startControl - endControl) - start) +
			3.f * p * p * (start - 2.f * startControl + endControl) +
			3.f * p * (startControl - start) + start);
	ret.push_back(end); // Last point is fixed
	return ret;
}

int cCurvaBezier::GetClsId()
{
	return ClsId_CurvaBezier;
}

cCurvaBezier::cCurvaBezier()
{
	pInicio.x = NULL;
	pInicio.y = NULL;

	pFinal.x = NULL;
	pFinal.y = NULL;

	pAnclaje1.x = NULL;
	pAnclaje1.y = NULL;

	pAnclaje2.x = NULL;
	pAnclaje2.y = NULL;
}

cCurvaBezier::~cCurvaBezier()
{

}

bool cCurvaBezier::adCosa(Point nP)
{
	if (pInicio.x == NULL && pFinal.x == NULL && pAnclaje1.x == NULL && pAnclaje2.x == NULL)
	{
		pInicio.x = nP.x;
		pInicio.y = nP.y;
	}
	else if (pInicio.x != NULL && pFinal.x == NULL && pAnclaje1.x == NULL && pAnclaje2.x == NULL)
	{
		pFinal.x = nP.x;
		pFinal.y = nP.y;
	}
	else if (pInicio.x != NULL && pFinal.x != NULL && pAnclaje1.x == NULL && pAnclaje2.x == NULL)
	{
		pAnclaje1.x = nP.x;
		pAnclaje1.x = nP.y;
	}
	else if (pInicio.x != NULL && pFinal.x != NULL && pAnclaje1.x != NULL && pAnclaje2.x == NULL)
	{
		pAnclaje2.x = nP.x;
		pAnclaje2.y = nP.y;
	}

	vertices = sf::VertexArray(sf::LinesStrip, 0);

	std::vector<sf::Vector2f> points;
	points.clear();

	if (pInicio.x != NULL && pFinal.x != NULL && pAnclaje1.x == NULL && pAnclaje2.x == NULL)
		points = CalcCubicBezier(pInicio, pFinal, pInicio, pFinal, 20);
	else if (pInicio.x != NULL && pFinal.x != NULL && pAnclaje1.x != NULL && pAnclaje2.x == NULL)
		points = CalcCubicBezier(pInicio, pFinal, pAnclaje1, pFinal, 20);
	else
		points = CalcCubicBezier(pInicio, pFinal, pAnclaje1, pAnclaje2, 20);


	tamano = points.size();

	for (std::vector<sf::Vector2f>::const_iterator a = points.begin(); a != points.end(); ++a)
		vertices.append(sf::Vertex(*a, sf::Color::Black));

	return (pInicio.x != NULL && pFinal.x != NULL && pAnclaje1.x != NULL && pAnclaje2.x != NULL);
}

void cCurvaBezier::Dibujar(sf::RenderWindow &Ventana)
{
	if (pInicio.x != NULL && pFinal.x != NULL)
		Ventana.draw(vertices);
}

bool cCurvaBezier::hitTest(Point mouseCoords)
{
	return false;
}

void cCurvaBezier::Guardar(ofstream &salida)
{
	salida << pInicio.x << endl;
	salida << pInicio.y << endl;

	salida << pFinal.x << endl;
	salida << pFinal.y << endl;

	salida << pAnclaje1.x << endl;
	salida << pAnclaje1.y << endl;

	salida << pAnclaje2.x << endl;
	salida << pAnclaje2.y << endl;
}

void cCurvaBezier::Cargar(ifstream &entrada)
{
	/*
	entrada >> pInicio.x;
	entrada >> pInicio.y;

	entrada >> pFinal.x;
	entrada >> pFinal.y;

	entrada >> pAnclaje1.x;
	entrada >> pAnclaje1.y;

	entrada >> pAnclaje2.x;
	entrada >> pAnclaje2.y;
	*/
	string str;
	getline(entrada, str);
	pInicio.x = stof(str);
	getline(entrada, str);
	pInicio.y = stof(str);

	getline(entrada, str);
	pFinal.x = stof(str);
	getline(entrada, str);
	pFinal.y = stof(str);

	getline(entrada, str);
	pAnclaje1.x = stof(str);
	getline(entrada, str);
	pAnclaje1.y = stof(str);

	getline(entrada, str);
	pAnclaje2.x = stof(str);
	getline(entrada, str);
	pAnclaje2.y = stof(str);
}

string cCurvaBezier::info()
{
	return "lu";
}

void cCurvaBezier::setMove(float x, float y)
{
	for (int i = 0; i < tamano; i++)
	{
		vertices[i].position = vertices[i].position + sf::Vector2f(x, y);
	}
}

void cCurvaBezier::setColor(sf::Color newColor)
{
	for (int i = 0; i < tamano; i++)
	{
		vertices[i].color = newColor;
	}
}