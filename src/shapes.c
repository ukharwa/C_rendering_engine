#include "shapes.h"
#include "vector.h"

Cube new_cube(float length, Vec3 bottom_left_front){
	float x = bottom_left_front.vec.x;
	float y = bottom_left_front.vec.y;
	float z = bottom_left_front.vec.z;
	
	Cube c = {bottom_left_front, {x,y+length,z}, {x+length,y+length,z}, {x+length,y,z},
		  {x,y,z-length}, {x,y+length,z-length}, {x+length,y+length,z-length}, {x+length,y,z-length},
		  {{0,1}, {0,3}, {0,4}, 
		   {5,4}, {5,6}, {5,1},
		   {2,1}, {2,3}, {2,6},
		   {7,4}, {7,6}, {7,3}}};
	return c;
}
