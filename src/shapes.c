#include "shapes.h"
#include "vector.h"

Cube new_cube(float length, Vec3 bottom_left_front){
	float x = bottom_left_front.vec.x;
	float y = bottom_left_front.vec.y;
	float z = bottom_left_front.vec.z;
	
	Vec3 vertices[8] = {bottom_left_front, {x,y+length,z}, {x+length,y+length,z}, {x+length,y,z},
			    {x,y,z-length}, {x,y+length,z-length}, {x+length,y+length,z-length}, {x+length,y,z-length}};
	
	//FRONT
	Triangle t1 = {vertices[0], vertices[1], vertices[2]};
	Triangle t2 = {vertices[2], vertices[3], vertices[0]};
	
	//LEFT
	Triangle t3 = {vertices[4], vertices[5], vertices[1]};
	Triangle t4 = {vertices[1], vertices[0], vertices[4]};
	
	//BOTTOM
	Triangle t5 = {vertices[4], vertices[0], vertices[3]};
	Triangle t6 = {vertices[3], vertices[7], vertices[4]};

	//BACK
	Triangle t7 = {vertices[7], vertices[6], vertices[5]};
	Triangle t8 = {vertices[5], vertices[4], vertices[7]};

	//RIGHT
	Triangle t9 = {vertices[3], vertices[2], vertices[6]};
	Triangle t10 = {vertices[6], vertices[7], vertices[3]};

	//TOP
	Triangle t11 = {vertices[1], vertices[5], vertices[6]};
	Triangle t12 = {vertices[6], vertices[2], vertices[1]};

	Cube c = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12};

	return c;
}
