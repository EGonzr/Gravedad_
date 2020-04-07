#include "NewtonBody.h"

struct World //Se encarga de hacer las iteraciones necesarias para la simulación. 
{
	//Constructores
	World() : gravity(Vec2(0.0f, 9.81f)) {} //Constructor predefinido
	World(Vec2 gravity) : gravity(gravity) {}

	//Establecer gravedad
	void setGravity(Vec2 v);

	//Creacion del cuerpo
	void addBody(Body* b);

	//Simulacion 
	void Step(float dt);

private:
	Vec2 gravity;
	std::vector<Body*> bodies;
};
