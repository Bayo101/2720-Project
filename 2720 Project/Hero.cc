// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#include "Config.h"
#include "Hero.h"

using namespace std;

Hero_t::Hero_t() {
	setStartingHealth();

}


Hero_t::~Hero_t() {



}

void Hero_t::draw() {



}

void Hero_t::move(double framePeriod) {



}

void Hero_t::setStartingHealth() {
	health = kHeroStartingHealth;
}