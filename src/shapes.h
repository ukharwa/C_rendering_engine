#pragma once

#include "vector.h"

typedef struct {
	Vector3 points[8];
} Cube;

typedef struct{
	Vector3 points[3];
} Triangle;

Cube new_cube(float length, Vector3 bottom_left_front);
Triangle new_triangle(Vector3 v1, Vector3 v2, Vector3 v3);
