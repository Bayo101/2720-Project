// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#ifndef DISPLAY_H
#define DISPLAY_H

#include <allegro5/allegro.h>
#include <cstdint>

using namespace std;

class Display_t {
private:
	ALLEGRO_DISPLAY *display;
	int64_t width;
	int64_t height;

public:
	Display_t(int64_t w = 800, int64_t h = 600);
	~Display_t();

	/// Returns the width of the window
	int64_t getWidth() const {
		return width;
	};

	/// Returns the height of the window
	int64_t getHeight() const {
		return height;
	};

	/// Returns the Allegro display
	ALLEGRO_DISPLAY * getAllegroDisplay() const {
		return display;
	}
};

#endif