#include "main.h"

double p_dist(S_Point p, S_Point s) {
	return sqrtl((s.x - p.x) * (s.x - p.x) + (s.y - p.y) * (s.y - p.y) + (s.z - p.z) * (s.z - p.z));
}