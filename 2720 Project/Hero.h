// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#ifndef HERO_H
#define HERO_H

#include "Object.h"
#include "Drawable.h"
#include "Moveable.h"
#include "Killable.h"

class Hero_t : public Object_t, public Drawable_t, public Moveable_t, public Killable_t {
private:
	int64_t health;
	bool alive;

public:
	Hero_t();
	~Hero_t();

	void draw();
	void move(double framePeriod);

	void setStartingHealth();
};

#endif