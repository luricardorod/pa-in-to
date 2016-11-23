#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include "cDocumento.h"
using namespace sf;

int main()
{
	cDocumento canvas1;
	RenderWindow window(VideoMode(200, 200), "SFML works!");
	CircleShape shape(100.f);
	shape.setFillColor(Color::Green);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
    return 0;
}