// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdexcept>
#include <cstdint>

#include "Config.h"
#include "GameSimulator.h"
#include "AllegroSimulator.h"
#include "Display.h"
#include "Drawable.h"
#include "Moveable.h"
#include "Background.h"
#include "Square.h"
#include "Circle.h"

using namespace std;

// constructor
GameSimulator_t::GameSimulator_t(const Display_t &displayInput, const int64_t &fpsInput) : AllegroSimulator_t(displayInput, fpsInput) {
	stop = false;
	redraw = true;
	currentTime = 0;
	timeOfLastUpdate = 0;
}

// destructor
GameSimulator_t::~GameSimulator_t() {
	drawable.clear();
	drawable.resize(0);
	moveable.clear();
	moveable.resize(0);
}

// gets user input keystrokes, step 1 of game loop
void GameSimulator_t::input() {
	al_wait_for_event(eventQueue, &event);


}

// update the position of all objects based on user input, step 2 of game loop
void GameSimulator_t::update() {
	if (event.type == ALLEGRO_EVENT_TIMER) {
		currentTime = al_current_time();
		auto framePeriod = (currentTime - timeOfLastUpdate);
		for (uint64_t i = 0; i < moveable.size(); i++) {
			moveable[i]->move(framePeriod);
		}
		// set last update time to now
		timeOfLastUpdate = currentTime;
		// since we updated, we need to redraw
		redraw = true;
	} else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		stop = true;
	}
}

// draw all objectss in the drawable container, step 3 of game loop
void GameSimulator_t::render() {
	if (redraw && al_is_event_queue_empty(eventQueue)) {
		al_clear_to_color(al_map_rgb(3, 12, 12)); // resets the screen to a solid color every frame
		for (uint64_t i = 0; i < drawable.size(); i++) {
			drawable[i]->draw();
		}
		al_flip_display(); // puts the rendered frame in the display window
		redraw = false;
	}
}

// the runtime game loop
void GameSimulator_t::runGameLoop() {
		while (!stop) {		
		input();
		update();
		render();
	}
}

// used in main to add the ground to the simulator to ease parameter passing when constructing shapes
void GameSimulator_t::addBackGround(const shared_ptr<BackGround_t> &groundPtrInput) {
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
shared_ptr<BackGround_t> GameSimulator_t::getGround() {
	return groundPtr;
}