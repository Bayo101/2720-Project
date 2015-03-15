// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#ifndef SQUARE_H
#define SQUARE_H

#include <allegro5/allegro_primitives.h>
#include <random>
#include <ctime>
#include <memory>
#include <iostream>
#include <cstdint>

#include "Config.h"
#include "AllegroSimulator.h"
#include "Background.h"
#include "Point.h" 
#include "Vector.h" 
#include "Drawable.h"
#include "Moveable.h"

using namespace std;

class Square_t : public Drawable_t, public Moveable_t {
private:
	// member variables
	shared_ptr<BackGround_t> groundPtr; // pointer to the ground object

	Point_t currentPosition; // the currentPosition of the square
	Point_t mostRecentPointReached; // the previous point we started at
	Point_t targetPoint;     // x and y of where the square is headed
	Vector_t currentVector;  // essentially the slope, or direction the square is moving in
	int64_t indexOfMostRecentPointReached;  // need to keep track of this so we can determine next point to go to, also needed to loop around

	int64_t width; // of the window
	int64_t height; // of the window

	int64_t squareSize; // of the drawn block in pixels

	int64_t red, green, blue; // rbg color ratio of the square
	int64_t thickness; // of the square

public:
	// constructor
	Square_t(const Display_t &d, const int64_t &fps, const shared_ptr<BackGround_t> &groundPtrInput) {
		groundPtr = groundPtrInput; // store pointer to the ground object for later use, very important
		width = d.getWidth();  // store window width, not really used
		height = d.getHeight(); // store window height, not really used
		// find an unoccupied point to spawn our object at
		findUnoccupiedPoint();
		// set current point and next point
		mostRecentPointReached = groundPtr->pointAtIndex(indexOfMostRecentPointReached);
		currentPosition = mostRecentPointReached;
		targetPoint = groundPtr->pointAtIndex(indexOfMostRecentPointReached + 1);
		// set random size
		squareSize = ((rand() % kSquareSizeVariance) + kMinSquareSize);
		// set random color in the specified ranges, hard coded since it wouldn't be worth it to set globals for them
		red = (rand() % 50);
		green = ((rand() % 200) + 50);
		blue = ((rand() % 200) + 50);
		// set random thickness
		thickness = (rand() % kSquareThicknessVariance) + kMinSquareThickness;
		// determine the initial vector/slope
		currentVector = groundPtr->vectorAtIndex(indexOfMostRecentPointReached);
	}

	// find an unoccupied point to spawn at so shapes don't overlap
	void findUnoccupiedPoint() {
		// if there exists at least one free spot
		if (groundPtr->numOccupied() != (groundPtr->size() - 1)) {
			// loop until we randomly get one of them
			while (true) {
				indexOfMostRecentPointReached = (rand() % groundPtr->size());
				// if the spot we get it unoccupied
				if (groundPtr->checkOccupied()[indexOfMostRecentPointReached] == false) {
					groundPtr->checkOccupied()[indexOfMostRecentPointReached] = true;
					// we set the flag to it being occupied and break
					break;
				}
			}
		} else {
			(*this).~Square_t();
		}
	}

	// draw the square based on its attributes
	void draw() {
		al_draw_rectangle(currentPosition.x + kSquareGroundOffset, (currentPosition.y - squareSize), (currentPosition.x + kSquareGroundOffset + squareSize), (currentPosition.y + squareSize - squareSize), al_map_rgb(red, green, blue), thickness);
	}

	// changes the objects coordinates based on the current vector, vectors are calculated inside the ground class
	void move(double framePeriod) {
		// need to do this before we can determine our vector/slope
		determineTarget();
		// do the movement
		currentPosition = (currentPosition + (currentVector * framePeriod));
		// if we're past the point(s), we set them to the target so we can calculate our next target
		overshotAdjustmentIfNecessary();
	}

	// check if we've reached our target, if yes, update the appropriate variables
	void determineTarget() {
		//check to see if we've reached the targetPoint
		if (currentPosition == targetPoint) {
			// if we've reached the point, we set our index to the next one, so our index is now at the point we're at
			indexOfMostRecentPointReached++;
			// next we need to set our new targetPosition
			if (indexOfMostRecentPointReached == (groundPtr->size() - 1)) {
				// if we're at the last point, we reset our index and set our current point to the first point
				indexOfMostRecentPointReached = 0;
				currentPosition = groundPtr->pointAtIndex(0);
				mostRecentPointReached = currentPosition;
				// and we set our next target position as the second point
				targetPoint = groundPtr->pointAtIndex(1);
				// this essentially takes care of the looping
			} else {
				// if we're not at the last point, we set our targetPoint to the next point
				mostRecentPointReached = groundPtr->pointAtIndex(indexOfMostRecentPointReached);
				targetPoint = groundPtr->pointAtIndex(indexOfMostRecentPointReached + 1);
			}
			// determine the vector/slope
			currentVector = groundPtr->vectorAtIndex(indexOfMostRecentPointReached);
		}
	}

	// protection against overshooting our targets for x and y
	void overshotAdjustmentIfNecessary() {
		// check if we were going up or down
		if (targetPoint.y < mostRecentPointReached.y) {
			// check if we overshot the y
			if (currentPosition.y < targetPoint.y) {
				// if we did, set the current y position to the exact y target position
				currentPosition.y = targetPoint.y;
			}
		} else {
			// check if we overshot the y
			if (currentPosition.y > targetPoint.y) {
				// if we did, set the current y position to the exact y target position
				currentPosition.y = targetPoint.y;
			}
		}

		// check if we're going left or right (we only go right, so it's not really necessary, but future proof this way)
		if (targetPoint.x < mostRecentPointReached.x) {
			// check if we overshot the x
			if (currentPosition.x < targetPoint.x) {
				// if we did, set the current x position to the exact x target position
				currentPosition.x = targetPoint.x;
			}
		} else {
			// check if we overshot the x
			if (currentPosition.x > targetPoint.x) {
				// if we did, set the current x position to the exact x target position
				currentPosition.x = targetPoint.x;
			}
		}
	}
};

#endif