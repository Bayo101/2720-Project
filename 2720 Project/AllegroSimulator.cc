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
#include "AllegroSimulator.h"

using namespace std;

AllegroSimulator_t::AllegroSimulator_t(const Display_t &displayInput, const int64_t &fpsInput) {
	FPS = fpsInput;
	timer = NULL;
	eventQueue = NULL;

	if ((timer = al_create_timer(1.0 / FPS)) == NULL) {
		throw std::runtime_error("Cannot create allegro timer");
	}

	if ((eventQueue = al_create_event_queue()) == NULL) {
		throw std::runtime_error("Cannot create event queue");
	}

	al_register_event_source(eventQueue, al_get_display_event_source(displayInput.getAllegroDisplay()));
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
	al_start_timer(timer);
}

AllegroSimulator_t::~AllegroSimulator_t() {
	if (timer != NULL) {
		al_destroy_timer(timer);
	}
	if (eventQueue != NULL) {
		al_destroy_event_queue(eventQueue);
	}
}