// Class: CPSC 2720
// Term: Spring 2015
// Professor: Robert Benkoczi
// Project: Game
// Members: Alex Hochheiden, Adam Lefaivre, Bayo Adejumo, Cody Crawford

#ifndef CONFIG_H
#define CONFIG_H

#include "Config.h"

#include <cstdint>

using namespace std;

// display settings
const int64_t kDisplayWidth = 1024;
const int64_t kDisplayHeight = 768;

// square settings
const int64_t kSquareSizeVariance = 20;
const int64_t kMinSquareSize = 30;

const int64_t kMinSquareThickness = 6;
const int64_t kSquareThicknessVariance = 6;

const int64_t kSquareGroundOffset = 15;

// circle settings
const int64_t kDiameterVariance = 20;
const int64_t kMinDiameter = 30;

const int64_t kMinCircleThickness = 6;
const int64_t kCircleThicknessVariance = 8;

const int64_t kCircleGroundOffset = 4;

// main settings
const int64_t kFramesPerSecond = 120; // recommend 60 to 120
const int64_t kDefaultNumPoints = 8; // do not change, keep it at 8

const int64_t kNumRandomShapesToGenerate = 8; // this has to be less than the number of points
const int64_t kNumRandomPointsToGenerate = 10;
const int64_t kNumStarsToGenerate = 10;

const bool kCirclesOnly = false;  // set to true to display only circles
const bool kRandomPoints = true; // set to true to generate points randomly

// hero settings
const int64_t kHeroStartingHealth = 200;
#endif