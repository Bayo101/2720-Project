// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#include "Object.h"


Point_t Object_t::getPoint() const {
	return position;
}

double Object_t::getX() const {
	return position.x;
}

double Object_t::getY() const {
	return position.y;
}
