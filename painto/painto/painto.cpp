#include "stdafx.h"
#include "cDocumento.h"
#include <iostream>
#include "cExplorador.h"
#include "cMouse.h"
using namespace std;

int main()
{
	cDocumento canvas1;

	cCapa *CapaInicial;
	canvas1.Insertar();
	ifstream fIn;

	fIn.open("loquesea.txt");
	if (fIn.is_open())
	{
		canvas1.Cargar(fIn);
		fIn.close();
	}
	canvas1.capaActual->Insertar(ClsId_CurvaBezier);
	/*

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
	
	
	//----------------------------------------------------//
	//---------------Esto es una ventana------------------//
	//----------------------------------------------------//
	sf::RenderWindow window(sf::VideoMode(1024, 720), "Painto!", sf::Style::Close);
	//----------------------------------------------------//
	//----------------------------------------------------//
	//----------------------------------------------------//


	//--------------------Inicio de-----------------------//
	//---------------Cargado de texturas------------------//
	//----------------------------------------------------//
	sf::Texture patoTextura;
	patoTextura.loadFromFile("Assets/pato8bit.png");

	sf::Texture textures[10];
	textures[0].loadFromFile("Assets/pointer.png");
	textures[1].loadFromFile("Assets/rectangle.png");
	textures[2].loadFromFile("Assets/roundedRectangle.png");
	textures[3].loadFromFile("Assets/elipse.png");
	textures[4].loadFromFile("Assets/triangle.png");
	textures[5].loadFromFile("Assets/polygon.png");
	textures[6].loadFromFile("Assets/bezierCurve.png");
	textures[7].loadFromFile("Assets/line.png");
	textures[8].loadFromFile("Assets/multilines.png");
	textures[9].loadFromFile("Assets/text.png");

	sf::Texture texturesModificadores[21];
	texturesModificadores[0].loadFromFile("Assets/arriba.png");
	texturesModificadores[1].loadFromFile("Assets/abajo.png");
	texturesModificadores[2].loadFromFile("Assets/derecha.png");
	texturesModificadores[3].loadFromFile("Assets/izquierda.png");
	texturesModificadores[4].loadFromFile("Assets/ancho.png");
	texturesModificadores[5].loadFromFile("Assets/largo.png");
	texturesModificadores[6].loadFromFile("Assets/borde.png");
	texturesModificadores[7].loadFromFile("Assets/RGB1.png");
	texturesModificadores[8].loadFromFile("Assets/RGBabajo.png");
	texturesModificadores[9].loadFromFile("Assets/RGB3.png");
	texturesModificadores[10] = texturesModificadores [8];
	texturesModificadores[11].loadFromFile("Assets/RGB2.png");
	texturesModificadores[12] = texturesModificadores[8];
	texturesModificadores[13].loadFromFile("Assets/relleno.png");
	texturesModificadores[14] = texturesModificadores[7];
	texturesModificadores[15] = texturesModificadores[8];
	texturesModificadores[16] = texturesModificadores[9];
	texturesModificadores[17] = texturesModificadores[8];
	texturesModificadores[18] = texturesModificadores[11];
	texturesModificadores[19] = texturesModificadores[8];
	texturesModificadores[20].loadFromFile("Assets/RGBarriba.png");

		//----------------------Fin de------------------------//
	//---------------Cargado de texturas------------------//
	//----------------------------------------------------//



	//--------------------Inicio de-----------------------//
	//---------------Creacion y aginacion-----------------//
	//--------------------Sprites-------------------------//
	sf::Sprite patoSprite;
	patoSprite.setTexture(patoTextura);
	patoSprite.setPosition(0, 0);
	patoSprite.setScale((float)40 / 13, (float)40 / 12);
	sf::Sprite spriteBotones[10];
	for (int i = 0; i < 10; i++)
	{
		spriteBotones[i].setTexture(textures[i]);
		spriteBotones[i].setPosition(0, (20 * (i + 1)) + (i + 1) * 40);
		spriteBotones[i].setScale((float)40 / 200, (float)40 / 200);
	}

	sf::Sprite spriteBotonesModificadores[26];
	int counterButons = 20;
	for (int i = 0; i < 20; i++)
	{
		spriteBotonesModificadores[i].setTexture(texturesModificadores[i]);
		spriteBotonesModificadores[i].setPosition(40*(i+1), 0);
		spriteBotonesModificadores[i].setScale((float)40 / 200, (float)40 / 200);
		if (i == 8 || i == 10 || i == 12 || i == 15 || i == 17 || i == 19)
		{
			spriteBotonesModificadores[i].setPosition(40 * (i + 1) + 10, 0);
			spriteBotonesModificadores[counterButons].setTexture(texturesModificadores[20]);
			spriteBotonesModificadores[counterButons].setPosition(40 * (i + 1) +10, 20);
			spriteBotonesModificadores[counterButons].setScale((float)40 / 200, (float)40 / 200);
			counterButons++;
		}
	}

	
	//----------------------Fin de------------------------//
	//---------------Creacion y aginacion-----------------//
	//--------------------Sprites-------------------------//



	//--------------------Inicio de-----------------------//
	//--------------------fondos UI-----------------------//
	//----------------------------------------------------//

	//Color de fondo de la app
	sf::Color UIBground = sf::Color(60, 60, 60, 255);
	//Color de fondo de las areas
	sf::Color colorBgroundUI = sf::Color(190, 190, 190, 255);
	//Color del borde de las areas
	sf::Color colorOutlineUI = sf::Color(50, 50, 50, 255);
	//Grosor del borde de las areas
	float lineThick = 2;

	sf::RectangleShape logoBground;
	logoBground.setSize(sf::Vector2f(40, 40));
	logoBground.setFillColor(sf::Color::Red);
	logoBground.setPosition(sf::Vector2f(0, 0));
	logoBground.setOutlineColor(colorOutlineUI);
	logoBground.setOutlineThickness(lineThick);

	sf::RectangleShape bground;
	bground.setSize(sf::Vector2f(1024, 720));
	bground.setFillColor(UIBground);
	bground.setPosition(sf::Vector2f(0, 0));

	sf::RectangleShape canvasBground;
	canvasBground.setSize(sf::Vector2f(720, 480));
	canvasBground.setFillColor(sf::Color::White);
	canvasBground.setPosition(sf::Vector2f(97, 110));

	sf::RectangleShape modifiers;
	modifiers.setSize(sf::Vector2f(984, 40));
	modifiers.setFillColor(colorBgroundUI);
	modifiers.setPosition(sf::Vector2f(40, 0));
	modifiers.setOutlineColor(colorOutlineUI);
	modifiers.setOutlineThickness(lineThick);

	sf::RectangleShape tools;
	tools.setSize(sf::Vector2f(40, 620));
	tools.setFillColor(colorBgroundUI);
	tools.setPosition(sf::Vector2f(0, 40));
	tools.setOutlineColor(colorOutlineUI);
	tools.setOutlineThickness(lineThick);

	sf::RectangleShape layers;
	layers.setSize(sf::Vector2f(150, 620));
	layers.setFillColor(colorBgroundUI);
	layers.setPosition(sf::Vector2f(874, 40));
	layers.setOutlineColor(colorOutlineUI);
	layers.setOutlineThickness(lineThick);

	sf::RectangleShape data;
	data.setSize(sf::Vector2f(1024, 60));
	data.setFillColor(colorBgroundUI);
	data.setPosition(sf::Vector2f(0, 660));
	data.setOutlineColor(colorOutlineUI);
	data.setOutlineThickness(lineThick);
	//----------------------Fin de------------------------//
	//--------------------fondos UI-----------------------//
	//----------------------------------------------------//


	//Esto es un mouse, tiene funciones que te dan la posicion del mouse respecto a la ventana
	//Tiene funciones que te devuelven el estado del clic izquierdo y derecho en forma de string
	//"Pressed"		El mouse acaba de ser presionado (dura un frame/instante)
	//"Down"		El mouse esta presionado
	//"Released";	El mouese acaba de dejar de ser presionado (dura un frame/instante)
	//"Up";			El mouse no esta siendo presionado

	cMouse mousePointer; //La clase mas inutil de todas, no es para nada importante, el uso de esta clase requiere un terabyte de RAM


	window.setFramerateLimit(60); //Los usuarios de consola no podran creer que esta app tiene mas fps que sus juegos.
	cExplorador chemonky(&canvas1, &window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Actualizar informacion del mouse
		mousePointer.actualizarDatos(sf::Mouse::isButtonPressed(sf::Mouse::Left), sf::Mouse::isButtonPressed(sf::Mouse::Right), sf::Mouse::getPosition(window));


		//Si el mouse esta dentro del canvas
		if (canvasBground.getGlobalBounds().contains(mousePointer.getPosition().x, mousePointer.getPosition().y))
		{
			if (mousePointer.getLeftState() == "Pressed") //Si hizo clic izquierdo
			{
				//Codigo
				cout << "canvas haola" << endl;

			}
		}
		//Si el mouse esta dentro del area de layers
		else if (layers.getGlobalBounds().contains(mousePointer.getPosition().x, mousePointer.getPosition().y))
		{
			if (mousePointer.getLeftState() == "Pressed") //Si hizo clic izquierdo
			{
				//Codigo
				Point cordenadas;
				cordenadas.x = mousePointer.getPosition().x;
				cordenadas.y = mousePointer.getPosition().y;
				chemonky.checarClick(cordenadas);
				cout << "hola modi" << endl;

			}
		}
		//Si el mouse esta dentro de la seccion de Tools
		else if (tools.getGlobalBounds().contains(mousePointer.getPosition().x, mousePointer.getPosition().y))
		{
			if (mousePointer.getLeftState() == "Pressed") //Si hizo clic izquierdo
			{
				for (int i = 0; i < 10; i++) //Buscar a que "boton" le dio clic
				{
					if (spriteBotones[i].getGlobalBounds().contains(mousePointer.getPosition().x, mousePointer.getPosition().y))
						cout << i << endl; //imprimir numero de boton
				}
			}
		}
		//Si el mouse esta dentro de el area de layers
		else if (modifiers.getGlobalBounds().contains(mousePointer.getPosition().x, mousePointer.getPosition().y))
		{
			if (mousePointer.getLeftState() == "Pressed") //Si hizo clic izquierdo
			{
				//Codigo
				cout << "hola" << endl;
			}
		}



		window.clear();

		window.draw(bground);

		window.draw(canvasBground);
		/*Dibujar aqui todas las figuras*/
		canvas1.Dibujar(window);

		window.draw(layers);
		/*Dibujar aqui las capas*/
		chemonky.update();
		

		window.draw(tools);
		/*Dibujar aqui los botones de herramientas*/
		for(int i = 0; i < 10; i++)
			window.draw(spriteBotones[i]);

		window.draw(modifiers);
		/*Dibujar aqui los botones modificadores*/
		for (int i = 0; i < 26; i++)
			window.draw(spriteBotonesModificadores[i]);

		window.draw(data);
		/*Dibujar aqui los datos de la figura seleccionada*/

		/*<No tocar esta parte del codigo>*/
		window.draw(logoBground);
		window.draw(patoSprite);
		/*</No tocar esta parte del codigo>*/

		window.display();
	}
    return 0;
}