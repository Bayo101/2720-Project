// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#ifndef MOVEABLE_H
#define MOVEABLE_H

#include "Config.h"

using namespace std;

class Moveable_t {
public:
	virtual void deltaMove(double framePeriod) = 0;
	virtual ~Moveable_t() {};
};

#endif