// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <allegro5/allegro.h>
#include <cstdint>

#include "Config.h"
#include "Display.h"

using namespace std;

class AllegroSimulator_t {
protected:
	int64_t FPS;
	ALLEGRO_EVENT_QUEUE *eventQueue;
	ALLEGRO_TIMER *timer;

public:
	AllegroSimulator_t(const Display_t & d, const int64_t &fps);
	~AllegroSimulator_t();
	virtual void runGameLoop() = 0;
};

#endif