// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#ifndef DISPLAY_H
#define DISPLAY_H

#include "Config.h"
#include <allegro5/allegro.h>
#include <cstdint>

using namespace std;

class Display_t {
private:
	ALLEGRO_DISPLAY *display;
	int64_t width;
	int64_t height;

public:
	Display_t(int64_t widthInput = 800, int64_t heightInput = 600);
	~Display_t();

	int64_t getWidth() const;
	int64_t getHeight() const;

	ALLEGRO_DISPLAY* getAllegroDisplay() const;
};

#endif