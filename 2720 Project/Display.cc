// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <cstdlib>
#include <cstdint>

#include "Config.h"
#include "Display.h"

using namespace std;

Display_t::Display_t(int64_t w, int64_t h) {
	width = w;
	height = h;

	al_init();

	// if the display cannot be initialized, we should throw an
	// exception. We will deal with exceptons later in the course, so
	// for now, we simply exit
	if ((display = al_create_display(width, height)) == NULL) {
		std::cerr << "Cannot initialize the display" << std::endl;
		exit(1); // non-zero argument means "trouble"
	}

	al_init_primitives_addon();
}

Display_t::~Display_t() {
	al_destroy_display(display);
}