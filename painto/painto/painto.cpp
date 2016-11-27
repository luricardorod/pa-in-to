#include "stdafx.h"
#include "cDocumento.h"
#include <iostream>
using namespace std;

int main()
{
	/*
	cDocumento canvas1;

	cCapa *CapaInicial;
	canvas1.Insertar();

	int decision;
	ofstream fOut;
	ifstream fIn;

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
		cout << "12. Cargar" << endl;
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
		case 12:
			fIn.open("loquesea.txt");
			if (fIn.is_open())
			{
				canvas1.Cargar(fIn);
				fIn.close();
			}
			break;
		default:
			break;
		}
	}


	*/
	vector<sf::RenderWindow*> ventanas;

	ventanas.push_back(new sf::RenderWindow(sf::VideoMode(1040, 128), "Modificadores"));
	ventanas.back()->setPosition(sf::Vector2i(50, 0));
	ventanas.push_back(new sf::RenderWindow(sf::VideoMode(120, 600), "Herramientas"));
	ventanas.back()->setPosition(sf::Vector2i(50, 128));
	ventanas.push_back(new sf::RenderWindow(sf::VideoMode(800, 600), "Canvas"));
	ventanas.back()->setPosition(sf::Vector2i(ventanas[1]->getPosition().x + ventanas[1]->getSize().x, 128));
	ventanas.push_back(new sf::RenderWindow(sf::VideoMode(120, 600), "Capas"));
	ventanas.back()->setPosition(sf::Vector2i(ventanas[2]->getPosition().x + ventanas[2]->getSize().x, 128));
	ventanas.push_back(new sf::RenderWindow(sf::VideoMode(1040, 100), "Propiedades"));
	ventanas.back()->setPosition(sf::Vector2i(50, 728));

	bool TodasAbiertas = true;

	//0 modificadores
	//1 Herramientas
	//2 canvas
	//3 capas
	//4 propiedades

	while (TodasAbiertas)
	{
		if (ventanas[0]->isOpen())
		{
			sf::Event event;
			while (ventanas[0]->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					ventanas[0]->close();
					ventanas[1]->close();
					ventanas[2]->close();
					ventanas[3]->close();
					ventanas[4]->close();
				}
			}
			ventanas[0]->clear();
			ventanas[0]->display();
		}

		if (ventanas[1]->isOpen())
		{
			sf::Event event;
			while (ventanas[1]->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					ventanas[0]->close();
					ventanas[1]->close();
					ventanas[2]->close();
					ventanas[3]->close();
					ventanas[4]->close();
				}
			}
			ventanas[1]->clear();
			ventanas[1]->display();
		}

		if (ventanas[2]->isOpen())
		{
			sf::Event event;
			while (ventanas[2]->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					ventanas[0]->close();
					ventanas[1]->close();
					ventanas[2]->close();
					ventanas[3]->close();
					ventanas[4]->close();
				}
			}
			ventanas[2]->clear();
			ventanas[2]->display();
		}

		if (ventanas[3]->isOpen())
		{
			sf::Event event;
			while (ventanas[3]->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					ventanas[0]->close();
					ventanas[1]->close();
					ventanas[2]->close();
					ventanas[3]->close();
					ventanas[4]->close();
				}
			}
			ventanas[3]->clear();
			ventanas[3]->display();
		}

		if (ventanas[4]->isOpen())
		{
			sf::Event event;
			while (ventanas[4]->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					ventanas[0]->close();
					ventanas[1]->close();
					ventanas[2]->close();
					ventanas[3]->close();
					ventanas[4]->close();
				}
			}
			ventanas[4]->clear();
			ventanas[4]->display();
		}

		for (vector<sf::RenderWindow*>::iterator it = ventanas.begin(); it != ventanas.end(); ++it)
		{
			TodasAbiertas = TodasAbiertas && (*it)->isOpen();
		}
	}
    return 0;
}