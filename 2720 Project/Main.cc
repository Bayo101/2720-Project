// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#include <iostream>
#include <memory>
#include <ctime>
#include <random>
#include <vector>
#include <cstdint>

#include "Config.h"
#include "Display.h"
#include "GameSimulator.h"
#include "Drawable.h"
#include "Moveable.h"
#include "BackGround.h"
#include "Circle.h"
#include "Square.h"
#include "Point.h" 
#include "Vector.h" 

using namespace std;

void generateBackGround(GameSimulator_t &simulator, const Display_t &display);
void generateShapes(GameSimulator_t &simulator, const Display_t &display);
void addCircle(GameSimulator_t &simulator, const Display_t &display);
void addSquare(GameSimulator_t &simulator, const Display_t &display);

int main() {
	Display_t display;
	GameSimulator_t simulator(display, kFramesPerSecond);

	srand(time(NULL));

	generateBackGround(simulator, display);
	//generateShapes(simulator, display);

	simulator.runGameLoop();

	return 0;
}

void generateBackGround(GameSimulator_t &simulator, const Display_t &display) {
	vector<Point_t> tempPoints;
	int64_t starCount = 0;
	while (starCount != kNumStarsToGenerate) {
		//set x to be off the right side of the screen to generate the stars
		int64_t offScreenRightX = display.getWidth()+100;
		//create a point to draw a star at a random y with in the screen height
		Point_t temp(offScreenRightX, ((rand() % display.getHeight())));
		// push our random point to the vector that will be used to make the Stars
		tempPoints.push_back(temp);
		starCount++;
	}

	shared_ptr<BackGround_t> tempGround = make_shared<BackGround_t>(display, kFramesPerSecond, tempPoints);
	simulator.addBackGround(tempGround);
	simulator.addDrawable(tempGround);
}

void generateShapes(GameSimulator_t &simulator, const Display_t &display) {
	int64_t max;
	(kRandomPoints) ? (max = kNumRandomShapesToGenerate) : (max = kDefaultNumPoints);
	if (kCirclesOnly) {
		for (int64_t i = 0; i < max; i++) {
			addCircle(simulator, display);
		}
	}
	else {
		for (int64_t i = 0; i < max; i++) {
			if ((rand() % 2) == 1) {
				addCircle(simulator, display);
			}
			else {
				addSquare(simulator, display);
			}
		}
	}
}

void addCircle(GameSimulator_t &simulator, const Display_t &display) {
	shared_ptr<Circle_t> tempCircle = make_shared<Circle_t>(display, kFramesPerSecond, simulator.getGround());
	simulator.addDrawable(tempCircle);
	simulator.addMoveable(tempCircle);
}

void addSquare(GameSimulator_t &simulator, const Display_t &display) {
	shared_ptr<Square_t> tempSquare = make_shared<Square_t>(display, kFramesPerSecond, simulator.getGround());
	simulator.addDrawable(tempSquare);
	simulator.addMoveable(tempSquare);
}