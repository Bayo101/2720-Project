// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#ifndef POINT_H
#define POINT_H

#include "Config.h"
#include "Vector.h" 

using namespace std;

// x and y point pair in an object with some overloaded operators
struct Point_t {
	// member variables
	double x;
	double y;

	// constructor
	Point_t(double xInput = 0.0, double yInput = 0.0) {
		x = xInput;
		y = yInput;
	};

	// addition operator
	Point_t operator + (Vector_t vectorInput) const {
		return Point_t((x + vectorInput.x), (y + vectorInput.y));
	};

	// equality operator
	bool operator == (Point_t pointInput) const {
		if ((x == pointInput.x) && (y == pointInput.y)) {
			return true;
		} else {
			return false;
		}
	}

	// inequality operator
	bool operator != (Point_t pointInput) const {
		if ((x != pointInput.x) || (y != pointInput.y)) {
			return true;
		} else {
			return false;
		}
	}
};

#endif