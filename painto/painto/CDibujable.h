#pragma once
#include <SFML\Graphics.hpp>
#include <fstream>
using namespace std;

struct Vector3f
{
	float x; float y; float z;
};

struct Point
{
	float x; float y;
};

class CDibujable
{
public:
	virtual void Guardar(ofstream &salida) = 0;
	virtual void Cargar(ifstream &entrada) = 0;
	virtual int GetClsId() = 0;
	virtual void Dibujar(sf::RenderWindow &Ventana) = 0;
};