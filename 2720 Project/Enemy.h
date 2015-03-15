// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#ifndef ENEMY_H
#define ENEMY_H

#include "Config.h"
#include "Object.h"
#include "Drawable.h"
#include "Moveable.h"

using namespace std;
class Enemy_t : public Object_t, public Drawable_t, public Moveable_t {
private:


public:
	Enemy_t();
	~Enemy_t();

	void draw();
	void move(double framePeriod);
};

#endif