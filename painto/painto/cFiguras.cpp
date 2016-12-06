#include "stdafx.h"
#include "cFiguras.h"

void cFiguras::setColorLinea(Vector3f nuevoColor)
{
	colorLinea = nuevoColor;
}

Vector3f cFiguras::getColorLinea() {
	return colorLinea;
}
void cFiguras::setColorRelleno(Vector3f nuevoColor) {
	colorRelleno = nuevoColor;
}
Vector3f cFiguras::getColorRelleno() {
	return colorRelleno;
}
void cFiguras::setPosicion(Point coordenadas) {
	posicion = coordenadas;
}
Point cFiguras::getPosition()
{
	return posicion;
}

void cFiguras::setMove(float x, float y)
{
}

void cFiguras::setColor(sf::Color newColor)
{
}

sf::Color cFiguras::getColor()
{
	return sf::Color();
}