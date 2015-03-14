// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdexcept>
#include <cstdint>

#include "GameSimulator.h"
#include "AllegroSimulator.h"
#include "Display.h"
#include "Drawable.h"
#include "Moveable.h"
#include "Ground.h"
#include "Square.h"
#include "Circle.h"

using namespace std;

// constructor, empty since the simulator base class does everything we need
GameSimulator_t::GameSimulator_t(const Display_t &d, const int64_t &fps) : AllegroSimulator_t(d, fps) {}

GameSimulator_t::~GameSimulator_t() {
	drawable.clear();
	drawable.resize(0);
	moveable.clear();
	moveable.resize(0);
}

// update the position of all objectss in the moveable container
void GameSimulator_t::update(double framePeriod) {
	for (uint64_t i = 0; i < moveable.size(); i++) {
		moveable[i]->deltaMove(framePeriod);
	}
}

// draw all objectss in the drawable container
void GameSimulator_t::render() {
	al_clear_to_color(al_map_rgb(5, 20, 20)); // resets the screen to a solid color, currently set as a dark blue
	for (uint64_t i = 0; i < drawable.size(); i++) {
		drawable[i]->draw();
	}
	al_flip_display(); // puts the newest rendered frame in the display window
}

// the runGameLoop()time loop
void GameSimulator_t::runGameLoop() {
	// switch to trigger model drawing
	bool redraw = true;
	// current time and timeOfLastUpdate in milliseconds
	// we need them to determine the ratio of movement for a given fps
	double currentTime = 0;
	double timeOfLastUpdate = 0;

	while (true) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(eventQueue, &ev);
		// update
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			currentTime = al_current_time();
			// update the position of all moveable objects with a fraction of time elapsed as a multiplier
			// this works in conjunction with the fps to make it move as much as it should in a given timeframe
			update(currentTime - timeOfLastUpdate);
			// set last update time to now
			timeOfLastUpdate = currentTime;
			// since we updated, we need to redraw
			redraw = true;
		} else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break; // if we close the window, we break out of this infinite loop
		}
		// render
		if (redraw && al_is_event_queue_empty(eventQueue)) {
			render(); // draw all drawable objects
			redraw = false;
		}
	}
}

// used in main to add the ground to the simulator to ease parameter passing when constructing shapes
void GameSimulator_t::addGround(const shared_ptr<Ground_t> &groundPtrInput) {
	groundPtr = groundPtrInput;
}

// used in main to add drawables to the simulator
void GameSimulator_t::addDrawable(const shared_ptr<Drawable_t> &drawPtr) {
	drawable.push_back(drawPtr);
}

// used in main to add moveables tothe simulator
void GameSimulator_t::addMoveable(const shared_ptr<Moveable_t> &movePtr) {
	moveable.push_back(movePtr);
}

// used when constructing shapes in main once the ground has been set
shared_ptr<Ground_t> GameSimulator_t::getGround() {
	return groundPtr;
}