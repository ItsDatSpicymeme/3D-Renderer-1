#pragma once


// Structs

#define P 4
	// 3d Point in space
struct S_Point {
	double x, y, z;
	///	Vertex_Point(double x, double y) : x{}, y{} {};
};


// Functions

	// Distance from a point to another point
double p_dist(S_Point, S_Point);