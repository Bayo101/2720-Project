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

#include "Display.h"
#include "GameSimulator.h"
#include "Drawable.h"
#include "Moveable.h"
#include "Ground.h"
#include "Circle.h"
#include "Square.h"
#include "Structs.h"

using namespace std;

void generateGround(GameSimulator_t &simulator, const Display_t &display);
void generateShapes(GameSimulator_t &simulator, const Display_t &display);
void addCircle(GameSimulator_t &simulator, const Display_t &display);
void addSquare(GameSimulator_t &simulator, const Display_t &display);

/********* Settings *******/
const int64_t kFramesPerSecond = 120; // recommend 60 to 120
const int64_t kDefaultNumPoints = 8; // do not change, keep it at 8

const int64_t kNumRandomShapesToGenerate = 8; // this has to be less than the number of points
const int64_t kNumRandomPointsToGenerate = 10;
const int64_t kRandomPointYValueVariance = 50;

const bool kCirclesOnly = false;  // set to true to display on circles
const bool kRandomPoints = false; // set to true to generate points randomly
/**************************/

int main() {
	// initialize the display and our simulator
	Display_t display; // initialize a display with default values
	GameSimulator_t simulator(display, kFramesPerSecond); // attach a simulator to the display with predefined FPS

	// seed random with the current time
	srand(time(NULL));

	// generate the ground before the shapes for two reasons, 
	// 1) layering, so the ground is drawn first and objects infront
	// 2) all other shapes need a pointer to the ground because they need to know the vertices, so the ground need to be constructed before they are
	generateGround(simulator, display);
	// after the ground is made we can make some shopes
	generateShapes(simulator, display);

	// once we've generated our ground and shapes, we runGameLoop() the simulation
	simulator.runGameLoop();

	return 0;
}

// generates the ground, either randomly or using predefined values, determined via settings at the top
void generateGround(GameSimulator_t &simulator, const Display_t &display) {
	// a vector that will hold our random points or predefined points and will be used to construct the ground
	vector<Point_t> tempPoints;

	if (kRandomPoints) {
		// random points between 3 predefined points
		Point_t leftOffScreenPoint(-100, ((display.getHeight() / 2) - 100));
		// off screen points so that objects don't disappear and reappear partially on the screen, intead they ease smoothly onto the screen
		tempPoints.push_back(leftOffScreenPoint);
		int64_t currentX = 0;
		// evenly determined gaps between x values
		int64_t gapSize = (display.getWidth() / kNumRandomPointsToGenerate);
		for (int64_t i = 0; i < kNumRandomPointsToGenerate; i++) {
			// y coordinate is randomly chosen
			Point_t temp(currentX, ((rand() % kRandomPointYValueVariance) + (display.getHeight() / 2)));
			// increment the x for next runGameLoop() through the loop
			currentX += gapSize;
			// push our random point to the vector that will be used to make the ground
			tempPoints.push_back(temp);
		}
		// edge and off screen point to make objects leave the screen smoothly, as mentioned before
		Point_t rightEdgeScreenPoint(display.getWidth(), ((display.getHeight() / 2) + kRandomPointYValueVariance));
		tempPoints.push_back(rightEdgeScreenPoint);
		Point_t rightOffScreenPoint((display.getWidth() + kRandomPointYValueVariance), (display.getHeight() / 2) + kRandomPointYValueVariance);
		tempPoints.push_back(rightOffScreenPoint);
	} else {
		// predefined points
		Point_t point0(-150, 200);
		Point_t point1(0, 250);
		Point_t point2(150, 300);
		Point_t point3(300, 380);
		Point_t point4(450, 410);
		Point_t point5(600, 500);
		Point_t point6(750, 510);
		Point_t point7(900, 600);
		// push them individually onto the vector used to create the ground
		tempPoints.push_back(point0);
		tempPoints.push_back(point1);
		tempPoints.push_back(point2);
		tempPoints.push_back(point3);
		tempPoints.push_back(point4);
		tempPoints.push_back(point5);
		tempPoints.push_back(point6);
		tempPoints.push_back(point7);
	}

	shared_ptr<Ground_t> tempGround = make_shared<Ground_t>(display, kFramesPerSecond, tempPoints);
	simulator.addGround(tempGround);
	simulator.addDrawable(tempGround);
}

void generateShapes(GameSimulator_t &simulator, const Display_t &display) {
	int64_t max;
	(kRandomPoints) ? (max = kNumRandomShapesToGenerate) : (max = kDefaultNumPoints);
	if (kCirclesOnly) {
		for (int64_t i = 0; i < max; i++) {
			addCircle(simulator, display);
		}
	} else {
		for (int64_t i = 0; i < max; i++) {
			if ((rand() % 2) == 1) {
				addCircle(simulator, display);
			} else {
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