#include "stdafx.h"
#include "cInformacion.h"
#include <iostream>
#include "cFiguras.h"


cInformacion::cInformacion(cDocumento* doc, sf::RenderWindow* win)
{
	documento = doc;
	window = win;
}


cInformacion::~cInformacion()
{
}

void cInformacion::update()
{
	//tamaño de ventanoa (1024, 60) posicion  660
	// debe de mostrar que figura su posicion, color en rgb del relleno y de la linea
	// ademas imprimir la informacion de cada figura info()
	if (documento->figuraActual == 0)
	{
		return;
	}
	sf::Font fuente;
	fuente.loadFromFile("comic.ttf");

	sf::Vector2f Position(0, 660);
	cFiguras* infoFigura = documento->figuraActual;

	if (infoFigura->GetClsId() == ClsId_Texto)
	{
		int posTxtX = ((cTexto*)(infoFigura))->cajaTexto.getPosition().x;
		int posTxtY = ((cTexto*)(infoFigura))->cajaTexto.getPosition().y;

		int colTxtR = ((cTexto*)(infoFigura))->getColor().r;
		int colTxtG = ((cTexto*)(infoFigura))->getColor().g;
		int colTxtB = ((cTexto*)(infoFigura))->getColor().b;

		string PosTxtX = to_string(posTxtX);
		string PosTxtY = to_string(posTxtY);

		string ColTxtR = to_string(colTxtR);
		string ColTxtG = to_string(colTxtG);
		string ColTxtB = to_string(colTxtB);

		string line1 = "Pos. X: " + PosTxtX + "	  Color: R (" + ColTxtR + ")	G (" + ColTxtG + ")	B (" + ColTxtB + ")";
		string line2 = "Pos. Y: " + PosTxtY;

		string lineFull0 = line1 + "\n" + line2;

		sf::Text totalInfo(lineFull0, fuente);
		totalInfo.setCharacterSize(20);
		totalInfo.setPosition(4, 660);
		totalInfo.setFillColor(sf::Color::Black);
		window->draw(totalInfo);
	}
	else if (infoFigura->GetClsId() == ClsId_Linea)
	{
		sf::Uint8 LineColorR = (infoFigura->getColor().r);
		sf::Uint8 LineColorG = (infoFigura->getColor().g);
		sf::Uint8 LineColorB = (infoFigura->getColor().b);

		string colorR = to_string(LineColorR);
		string colorG = to_string(LineColorG);
		string colorB = to_string(LineColorB);

		string lineFull1 = "Color: R (" + colorR + ")	G (" + colorG + ")	B (" + colorB + ")";

		sf::Text totalInfo(lineFull1, fuente);
		totalInfo.setCharacterSize(20);
		totalInfo.setPosition(4, 660);
		totalInfo.setFillColor(sf::Color::Black);
		window->draw(totalInfo);
	}	
	else if (infoFigura->GetClsId() == ClsId_TiraDeLinea)
	{
		sf::Uint8 LineColorR = (infoFigura->getColor().r);
		sf::Uint8 LineColorG = (infoFigura->getColor().g);
		sf::Uint8 LineColorB = (infoFigura->getColor().b);

		string colorR = to_string(LineColorR);
		string colorG = to_string(LineColorG);
		string colorB = to_string(LineColorB);

		string lineFull2 = "Color: R (" + colorR + ")	G (" + colorG + ")	B (" + colorB + ")"; + "B: " + colorB;

		sf::Text totalInfo(lineFull2, fuente);
		totalInfo.setCharacterSize(20);
		totalInfo.setPosition(4, 660);
		totalInfo.setFillColor(sf::Color::Black);
		window->draw(totalInfo);
	}
	else if (infoFigura->GetClsId() == ClsId_CurvaBezier)
	{
		sf::Uint8 LineColorR = (infoFigura->getColor().r);
		sf::Uint8 LineColorG = (infoFigura->getColor().g);
		sf::Uint8 LineColorB = (infoFigura->getColor().b);

		string colorR = to_string(LineColorR);
		string colorG = to_string(LineColorG);
		string colorB = to_string(LineColorB);

		string lineFull3 = "Color: R (" + colorR +  ")	G (" + colorG + ")	B (" + colorB + ")";

		sf::Text totalInfo(lineFull3, fuente);
		totalInfo.setCharacterSize(20);
		totalInfo.setPosition(4, 660);
		totalInfo.setFillColor(sf::Color::Black);
		window->draw(totalInfo);
	}
	else
	{
		int posX = infoFigura->infoFig->getPosition().x;
		int posY = infoFigura->infoFig->getPosition().y;

		int colRr = infoFigura->infoFig->getFillColor().r;
		int colRg = infoFigura->infoFig->getFillColor().g;
		int colRb = infoFigura->infoFig->getFillColor().b;

		int colLr = infoFigura->infoFig->getOutlineColor().r;
		int colLg = infoFigura->infoFig->getOutlineColor().g;
		int colLb = infoFigura->infoFig->getOutlineColor().b;

		string PosX = to_string(posX);
		string PosY = to_string(posY);

		string ColRr = to_string(colRr);
		string ColRg = to_string(colRg);
		string ColRb = to_string(colRb);

		string ColLr = to_string(colLr);
		string ColLg = to_string(colLg);
		string ColLb = to_string(colLb);

		string Linea1 = "Pos X = " + PosX + "	Col. Linea: R (" + ColLr + ")	 G (" + ColLg + ")	B (" + ColLb + ")";
		string Linea2 = "Pos Y = " + PosY + "	Col. Relleno: R (" + ColRr + ")    G (" + ColRg + ")	  B (" + ColRb + ")";

		string info1 = Linea1 + "\n" + Linea2;

		sf::Text totalInfo(info1, fuente);
		totalInfo.setCharacterSize(20);
		totalInfo.setPosition(4, 660);
		totalInfo.setFillColor(sf::Color::Black);
		window->draw(totalInfo);
	}
}