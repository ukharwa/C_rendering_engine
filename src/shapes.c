#include "shapes.h"
#include "vector.h"

Cube new_cube(float length, Vec3 bottom_left_front){
	float x = bottom_left_front.vec.x;
	float y = bottom_left_front.vec.y;
	float z = bottom_left_front.vec.z;

	Cube c = {bottom_left_front, {x, y+length, z}, {x+length, y+length, z}, {x+length, y, z}
		  ,{x, y, z+length}, {x, y+length, z+length}, {x+length, y+length, z+length}, {x+length, y, z+length}};

	return c;
}
