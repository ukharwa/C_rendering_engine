#include "shapes.h"
#include "vector.h"

Cube new_cube(float length, Vec3 bottom_left_front){
	float x = bottom_left_front.x;
	float y = bottom_left_front.y;
	float z = bottom_left_front.z;
	
	Cube c = {{(Vec3)bottom_left_front, (Vec3){x,y+length,z}, (Vec3){x+length,y+length,z}, (Vec3){x+length,y,z},
		   (Vec3){x,y,z-length}, (Vec3){x,y+length,z-length}, (Vec3){x+length,y+length,z-length}, (Vec3){x+length,y,z-length}},
	           {0, 1, 2,
	            2, 3, 0,
	            4, 5, 1,
	            1, 0, 4,
	            4, 0, 3,
	            3, 7, 4,
	            7, 6, 5,
	            5, 4, 7,
	            3, 2, 6,
	            6, 7, 3,
	            1, 5, 6,
	            6, 2, 1}};

	return c;
}
