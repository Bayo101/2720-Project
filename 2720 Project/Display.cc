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

// constructor
Display_t::Display_t(int64_t widthInput, int64_t heightInput) {
	width = widthInput;
	height = heightInput;

	al_init();

	if ((display = al_create_display(width, height)) == NULL) {
		std::cerr << "Cannot initialize the display" << std::endl;
		exit(1); // non-zero argument means "trouble"
	}

	al_init_primitives_addon();
}

// destructor
Display_t::~Display_t() {
	al_destroy_display(display);
}

/// Returns the width of the window
int64_t Display_t::getWidth() const {
	return width;
};

/// Returns the height of the window
int64_t Display_t::getHeight() const {
	return height;
};

/// Returns the Allegro display
ALLEGRO_DISPLAY* Display_t::getAllegroDisplay() const {
	return display;
};