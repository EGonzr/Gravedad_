#include <SFML/Graphics.hpp>
#include "NewtonWorld.h"

using namespace std; 

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Se cayó"); //Esta linea de coidgo se utiliza para crear ventanas del tamaño que querramos
	window.setFramerateLimit(60);

	sf::Event event; //Se crea un objeto tipo evento, llamado event. 
	sf::Clock clock; //Para llevar el tiempo que toma hacer un frame en el ciclo de window. 

	//Para poder utilizar las sprites
	sf::Texture boxTex1;
	sf::Sprite boxSprite1;

	if (!boxTex1.loadFromFile("Assets/Sprites/box1.png"))
	{
		cout << "Could not load texture. . ." << endl;
		system("pause");
	}

	//Configuramos nuestro mundo
	World w1;
	w1.setGravity(Vec2(0.0f, 900.0f));

	Body b1;
	b1.setMass(1.0f);
	b1.setPos(Vec2(500.0f, 0.0f));
	b1.setVel(Vec2(50.0f, 0.0f));

	w1.addBody(&b1);

	//Configurando sprites

	boxSprite1.setTexture(boxTex1);
	boxSprite1.setScale(sf::Vector2f(0.35f, 0.35f));

	//Colocamos el origen del sprite 
	sf::Rect<float> size = boxSprite1.getGlobalBounds();
	boxSprite1.setOrigin(sf::Vector2f(size.width / 2, size.height / 2));

	//Coloca la caja en el centro de la pantalla
	//El sprite usa la misma posición inicial que se le da al cuerpo en la configuración de cuerpo
	boxSprite1.setPosition(sf::Vector2f(b1.getPos().getX(), b1.getPos().getY()));


	//Lo que se muestra
	while (window.isOpen()) //Se mantiene el ciclo while mientras la ventana esté abierta
	{
		while (window.pollEvent(event)) //Lee si hubo alguna señal de entrada (mouse, teclado, joystick...) 
		{
			if (event.type == sf::Event::Closed) //Si el usuario presiona X (para salir de la ventana)...
			{
				window.close(); //... Cierra la ventana
			}
		}

		//Calculo el tiempo que toma hacer un frame
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		//Uso el tiempo calculado para usar la función Step() de World w1
		w1.Step(dt);

		boxSprite1.setPosition(sf::Vector2f(b1.getPos().getX(), b1.getPos().getY()));

		window.clear(sf::Color::Black);
		window.draw(boxSprite1);
		window.display();
	}

	return 0;
}