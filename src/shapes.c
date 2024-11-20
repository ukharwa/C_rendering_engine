#include "shapes.h"
#include "vector.h"

Cube new_cube(float length, Vector3 bottom_left_front){
	float x = bottom_left_front.x;
	float y = bottom_left_front.y;
	float z = bottom_left_front.z;

	Cube c = {bottom_left_front, {x, y+length, z}, {x+length, y+length, z}, {x+length, y, z}
		  ,{x, y, z+length}, {x, y+length, z+length}, {x+length, y+length, z+length}, {x+length, y, z+length}};

	return c;
}

Triangle new_triangle(Vector3 v1, Vector3 v2, Vector3 v3){
	Triangle t = {v1, v2, v3};
	return t;
}
