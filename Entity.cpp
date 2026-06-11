#include "Entity.h"

Entity::Entity::Entity(float startX, float startY, float radius) : shape{ radius }
{
	//shape.setPosition(startX, startY);
	shape.setFillColor(sf::Color::White);
}