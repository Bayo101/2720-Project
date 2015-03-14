// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "Config.h"

using namespace std;

class Drawable_t {
public:
	virtual void draw() = 0;
	virtual ~Drawable_t() {};
};

#endif