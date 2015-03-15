// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#ifndef GAMESIMULATOR_H
#define GAMESIMULATOR_H

#include <vector>
#include <memory>
#include <list>

#include "Config.h"
#include "Display.h"
#include "AllegroSimulator.h"
#include "Drawable.h"
#include "Moveable.h"
#include "Killable.h"
#include "Background.h"
#include "Hero.h"

using namespace std;

class GameSimulator_t : public AllegroSimulator_t {
private:
	// object pointers
	vector<shared_ptr<Moveable_t> > moveable;
	vector<shared_ptr<Drawable_t> > drawable;

	list<shared_ptr<Killable_t> > killable;

	shared_ptr<Hero_t> hero;
	// used to simplify contructing objects in main by minimizing function parameter count
	shared_ptr<BackGround_t> groundPtr;
	ALLEGRO_EVENT event;
	bool stop;
	bool redraw;
	double currentTime;
	double timeOfLastUpdate;

public:
	// constructor
	GameSimulator_t(const Display_t &displayInput, const int64_t &fpsInput);

	// destructor
	~GameSimulator_t();

	// three stages of the game loop
	void input();
	void update();
	void render();

	// game loop
	void runGameLoop();

	void addBackGround(const shared_ptr<BackGround_t> &groundPtrInput);
	void addDrawable(const shared_ptr<Drawable_t> &drawPtr);
	void addMoveable(const shared_ptr<Moveable_t> &movePtr);
	// used to simplify contructing objects in main by minimizing function parameter count
	shared_ptr<BackGround_t> getGround();
};

#endif