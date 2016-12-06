#include "stdafx.h"
#include "cInformacion.h"
#include "cFiguras.h"


cInformacion::cInformacion(cDocumento* doc, sf::RenderWindow* win)
{
	documento = doc;
	window = win;
}


cInformacion::~cInformacion()
{
}

void cInformacion::update() {
	//tama�o de ventanoa (1024, 60) posicion  660
	// debe de mostrar que figura su posicion, color en rgb del relleno y de la linea
	// ademas imprimir la informacion de cada figura info()
	if (documento->figuraActual == 0 || documento->figuraActual->infoFig == 0)
	{
		return;
	}
	sf::Font fuente;
	fuente.loadFromFile("comic.ttf");

	sf::Vector2f Position(0, 660);
	cFiguras* infoFigura = documento->figuraActual;

	if (infoFigura->GetClsId() == ClsId_Texto)
	{
		
	}
	else if (infoFigura->GetClsId() == ClsId_Linea)
	{

	}
	else if (infoFigura->GetClsId() == ClsId_TiraDeLinea)
	{

	}
	else if (infoFigura->GetClsId() == ClsId_CurvaBezier)
	{
		
	}
	
	float posX = infoFigura->infoFig->getPosition().x;
	float posY = infoFigura->infoFig->getPosition().y;

	float colRr = infoFigura->infoFig->getFillColor().r;
	float colRg = infoFigura->infoFig->getFillColor().g;
	float colRb = infoFigura->infoFig->getFillColor().b;

	float colLr = infoFigura->infoFig->getOutlineColor().r;
	float colLg = infoFigura->infoFig->getOutlineColor().g;
	float colLb = infoFigura->infoFig->getOutlineColor().b;
	string PosX = to_string(posX);
	string PosY = to_string(posY);

	string ColRr = to_string(colRr);
	string ColRg = to_string(colRg);
	string ColRb = to_string(colRb);

	string ColLr = to_string(colLr);
	string ColLg = to_string(colLg);
	string ColLb = to_string(colLb);

	string Linea1 = "Pos X = " + PosX + "						  R: " + ColRr + "					  R: " + ColLr;;
	string Linea2 = "Pos Y = " + PosY + "	Col. Relleno  G: " + ColRg + "	Col. Linea  G: " + ColLg;
	string Linea3 = "										 					B: " + ColRb + "					   B: " + ColLb;

	string info1 = Linea1 + "\n" + Linea2 + "\n" + Linea3;

	sf::Text totalInfo(info1, fuente);
	totalInfo.setCharacterSize(15);
	totalInfo.setPosition(4, 660);
	totalInfo.setFillColor(sf::Color::Black);
	window->draw(totalInfo);
}