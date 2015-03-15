// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#ifndef KILLABLE_H
#define KILLABLE_H

#include <cstdint>

#include "Config.h"
#include "Object.h"

using namespace std;

class Killable_t {
private:
	int64_t health;
	bool alive;

public:
	virtual void setStartingHealth() = 0;
	virtual ~Killable_t() {};
};

#endif