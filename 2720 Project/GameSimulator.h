// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#ifndef GAMESIMULATOR_H
#define GAMESIMULATOR_H

#include <vector>
#include <memory>

#include "Config.h"
#include "Display.h"
#include "AllegroSimulator.h"
#include "Drawable.h"
#include "Moveable.h"
#include "Ground.h"

using namespace std;

class GameSimulator_t : public AllegroSimulator_t {
private:
	// containers
	vector<shared_ptr<Drawable_t> > drawable;
	vector<shared_ptr<Moveable_t> > moveable;
	// used to simplify contructing objects in main by minimizing function parameter count
	shared_ptr<Ground_t> groundPtr;

public:
	// constructor
	GameSimulator_t(const Display_t &d, const int64_t &fps);
	// destructor
	~GameSimulator_t();
	// called by runGameLoop()
	void update(double framePeriod);
	void render();
	// runGameLoop()time loop
	void runGameLoop();
	// used to prepare for a runGameLoop()
	void addGround(const shared_ptr<Ground_t> &groundPtrInput);
	void addDrawable(const shared_ptr<Drawable_t> &drawPtr);
	void addMoveable(const shared_ptr<Moveable_t> &movePtr);
	// used to simplify contructing objects in main by minimizing function parameter count
	shared_ptr<Ground_t> getGround();
};

#endif