#pragma once

#include "vector.h"

typedef struct{
	int r,g,b;
} RGB;

typedef struct{
	Vec3 pos;
	RGB color;
} Vertex;
