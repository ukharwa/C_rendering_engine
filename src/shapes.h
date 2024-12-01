#pragma once

#include "vector.h"
#include "vertex.h"

typedef struct {
	Vertex vertices[8];
	int edges[36];
} Cube;

Cube new_cube(float length, Vec3 bottom_left_front, RGB color);
