#include <SFML/Graphics.hpp>
using namespace sf;

sf::View view;
float vX, vY;
void getplayercoordinateforview(float x, float y) { 
	float tempX = x; float tempY = y;
	view.setCenter(tempX, tempY);
}
