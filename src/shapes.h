#pragma once

#include "vector.h"

typedef struct{
	Vec3 vertex[3];
} Triangle;

typedef struct {
	Triangle mesh[12];
} Cube;

Cube new_cube(float length, Vec3 bottom_left_front);
