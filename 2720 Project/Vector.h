// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#ifndef VECTOR_H
#define VECTOR_H

#include "Config.h"

using namespace std;

// used to determine the x and y movement of an object (can be positive or negative)
struct Vector_t {
	// member variables
	double x;
	double y;

	// constructor
	Vector_t(double xInput = 0.0, double yInput = 0.0) {
		x = xInput;
		y = yInput;
	};

	// scalar multiplier
	Vector_t operator * (double scalarInput) const {
		return Vector_t(x * scalarInput, y * scalarInput);
	}

	// equality operator
	bool operator == (Vector_t vectorInput) const {
		if ((x == vectorInput.x) && (y == vectorInput.y)) {
			return true;
		} else {
			return false;
		}
	}

	// inequality operator
	bool operator != (Vector_t vectorInput) const {
		if ((x != vectorInput.x) || (y != vectorInput.y)) {
			return true;
		} else {
			return false;
		}
	}
};

#endif