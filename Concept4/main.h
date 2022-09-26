#pragma once

#include <stdio.h>
#include <math.h>
#include "SFML/Graphics.hpp"

#include "points.h"

using namespace sf;


// Defines

	// Preferences
#define Colour Color

	// Shorteners



// Main Window

	// Frames Per Second to run main window
#define FPS 60
	// Main window sizes
		// Screen Height Multiplier (to always have a 16:9 Aspect Ratio)
#define MUL 60
#define s_l (9 * MUL)
#define s_h (9 * MUL)