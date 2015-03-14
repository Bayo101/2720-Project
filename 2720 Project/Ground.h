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

class Ground_t : public Drawable_t {
private:
	// member variables
	vector<Point_t> vertices; // all the points
	vector<Vector_t> riseAndRun; // fractions of x and y movement between two points

	vector<bool> occupied; // a point is occupied if an object has been assigned to spawn there
	int64_t occupiedCount; // to keep track of the number of points that are occupied

	int64_t width; // of the window
	int64_t height; // of the window

	int64_t red, green, blue; // rbg color ratio of the square

	int64_t thickness; // how thick the ground is

public:
	// constructor
	Ground_t(const Display_t & d, const int64_t & fps, vector<Point_t> verticesInput) {
		vertices = verticesInput; // a vector of all the points, between which we draw lines.
		occupiedCount = 0; // set to 0, used n conjuncton with the bool array to stop objects from spawning in the same spot
		occupied.assign(vertices.size(), false); // set all points as unoccupied, used later so objects don't spawn in the same locations
		width = d.getWidth();  // store window height, not really used
		height = d.getHeight(); // store window height, not really used
		// set the color of the line, hardcoded to brown (139, 69, 19)
		red = 139;
		green = 69;
		blue = 19;
		// set the  thickness of the line
		thickness = kGroundThickness;
		// calculate the rise and runGameLoop() of a line (slope between two points)
		for (uint64_t i = 0; i < (vertices.size() - 1); i++) {
			// two connected points
			Point_t point1 = vertices[i];
			Point_t point2 = vertices[i + 1];
			// x2 - x1 and y2 - y1
			Vector_t temp((point2.x - point1.x), (point2.y - point1.y));
			// store our slops for later use via indexing
			riseAndRun.push_back(temp);
		}
	}

	// destructor
	~Ground_t() {
		vertices.clear();
		vertices.resize(0);
		riseAndRun.clear();
		riseAndRun.resize(0);
		occupied.clear();
		occupied.resize(0);
	}

	// draw the line between the two points stored for the object
	void draw() {
		// draw all the lines between two points (-1 since there's one less line than the number of points)
		for (uint64_t i = 0; i < (vertices.size() - 1); i++) {
			al_draw_line(vertices[i].x, vertices[i].y, vertices[i + 1].x, vertices[i + 1].y, al_map_rgb(red, green, blue), thickness);
		}
	}

	// returns the point (x, y) pair at the given index
	Point_t pointAtIndex(int64_t index) const {
		return vertices[index];
	}

	// returns the vector/direction the line is going from the point at a given index
	Vector_t vectorAtIndex(int64_t index) const {
		return riseAndRun[index];
	}

	// returns the number of points the ground is made of
	int64_t size() const {
		return vertices.size();
	}

	// returns the number of occupied vertices
	int64_t numOccupied() const {
		return occupiedCount;
	}

	// returns the boolean array of occupied spots so we can can find an unoccupied spot and set it to occupied once found
	vector<bool>& checkOccupied() {
		return occupied;
	}
};

#endif