#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include "cDocumento.h"
#include <iostream>
using namespace std;

int main()
{
	cDocumento canvas1;

	cCapa *CapaInicial;
	canvas1.Insertar();

	int decision;
	ofstream fOut;
	while (true)
	{
		cout << "Hola, bienvenido al corel chafa" << endl;
		cout << "Que deseas hacer?" << endl;
		cout << "1. Crear Capa" << endl;
		cout << "2. Crear Rectangulo" << endl;
		cout << "3. Crear Rectangulo Redondeado" << endl;
		cout << "4. Crear Triangulo" << endl;
		cout << "5. Crear Elipse" << endl;
		cout << "6. Crear Linea" << endl;
		cout << "7. Crear Poligono" << endl;
		cout << "8. Crear Tira de Lineas" << endl;
		cout << "9. Crear Curva de Bezier" << endl;
		cout << "10. Crear Texto" << endl;
		cout << "11. Guardar" << endl;
		cin >> decision;

		switch (decision)
		{
		case 1:
			canvas1.Insertar();
			break;
		case 2:
			canvas1.capaActual->Insertar(ClsId_Rectangulo);
			break;
		case 3:
			canvas1.capaActual->Insertar(ClsId_RectanguloRedondeado);
			break;
		case 4:
			canvas1.capaActual->Insertar(ClsId_Triangulo);
			break;
		case 5:
			canvas1.capaActual->Insertar(ClsId_Elipse);
			break;
		case 6:
			canvas1.capaActual->Insertar(ClsId_Linea);
			break;
		case 7:
			canvas1.capaActual->Insertar(ClsId_Poligono);
			break;
		case 8:
			canvas1.capaActual->Insertar(ClsId_TiraDeLinea);
			break;
		case 9:
			canvas1.capaActual->Insertar(ClsId_CurvaBezier);
			break;
		case 10:
			canvas1.capaActual->Insertar(ClsId_Texto);
			break;
		case 11:
			fOut.open("loquesea.txt", ios_base::out);
			if (fOut.is_open())
			{
				canvas1.Guardar(fOut);
				fOut.close();
			}
			break;
		default:
			break;
		}
	}

	/*
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	*/
    return 0;
}