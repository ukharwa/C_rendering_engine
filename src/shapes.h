#pragma once

#include "vector.h"

typedef struct {
	Vec3 points[8];
} Cube;

Cube new_cube(float length, Vec3 bottom_left_front);
