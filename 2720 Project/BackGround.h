// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#ifndef GROUND_H
#define GROUND_H

#include <allegro5/allegro_primitives.h>
#include <vector>
#include <cstdint>

#include "Config.h"
#include "Point.h" 
#include "Vector.h" 
#include "AllegroSimulator.h"
#include "Drawable.h"
#include "Moveable.h"

using namespace std;

class BackGround_t : public Drawable_t {
private:
	// member variables
	vector<Point_t> stars; // all the points
	vector<Vector_t> riseAndRun; // fractions of x and y movement between two points

	vector<bool> occupied; // a point is occupied if an object has been assigned to spawn there
	int64_t occupiedCount; // to keep track of the number of points that are occupied

	int64_t width; // of the window
	int64_t height; // of the window

	int64_t red, green, blue; // rbg color ratio of the square

public:
	// constructor
	BackGround_t(const Display_t &displayInput, const int64_t &fpsInput, vector<Point_t> &verticesInput) {
		stars = verticesInput; // a vector of all the points, between which we draw lines.
		occupiedCount = 0; // set to 0, used n conjuncton with the bool array to stop objects from spawning in the same spot
		occupied.assign(stars.size(), false); // set all points as unoccupied, used later so objects don't spawn in the same locations
		width = displayInput.getWidth();
		height = displayInput.getHeight();

		red = 255;
		green = 255;
		blue = 0;
	}

	// destructor
	~BackGround_t() {
		stars.clear();
		stars.resize(0);
		riseAndRun.clear();
		riseAndRun.resize(0);
		occupied.clear();
		occupied.resize(0);
	}

	// draw the line between the two points stored for the object
	void draw() {
		// draw all the lines between two points (-1 since there's one less line than the number of points)
		for (uint64_t i = 0; i < (stars.size() - 1); i++) {
			for (uint64_t j = 0; j < 2; j++) {
				al_draw_pixel((stars[i].x)+j, stars[i].y, al_map_rgb(red, green, blue));
			}
		}
		increment_x(); //move star.x to the left
	}

	// returns the point (x, y) pair at the given index
	Point_t pointAtIndex(int64_t index) const {
		return stars[index];
	}

	// returns the vector/direction the line is going from the point at a given index
	Vector_t vectorAtIndex(int64_t index) const {
		return riseAndRun[index];
	}

	// returns the number of points the ground is made of
	int64_t size() const {
		return stars.size();
	}

	// returns the number of occupied stars
	int64_t numOccupied() const {
		return occupiedCount;
	}

	// returns the boolean array of occupied spots so we can can find an unoccupied spot and set it to occupied once found
	vector<bool>& checkOccupied() {
		return occupied;
	}

	void increment_x() {
		for (int64_t i = 0; i < stars.size(); i++)
			stars[i].x--;
	}
};

#endif