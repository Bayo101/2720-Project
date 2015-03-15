// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#ifndef OBJECT_H
#define OBJECT_H

#include "Point.h"

class Object_t {
private:
	Point_t position;
	
public:
	Point_t getPoint() const;
	double getX() const;
	double getY() const;

	virtual ~Object_t() {};
};

#endif