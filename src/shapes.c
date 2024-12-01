#include "shapes.h"
#include "vector.h"
#include "vertex.h"

Cube new_cube(float length, Vec3 bottom_left_front, RGB color){
	float x = bottom_left_front.x;
	float y = bottom_left_front.y;
	float z = bottom_left_front.z;
	
	int indices[36] = {0, 1, 2,
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
	                   6, 2, 1};
	Vertex vertices[8] = {{bottom_left_front,color}, {{x,y+length,z},color}, {{x+length,y+length,z},color}, {{x+length,y,z},color},
	                      {{x,y,z+length},color}, {{x,y+length,z+length},color}, {{x+length,y+length,z+length},color}, {{x+length,y,z+length},color}};
	
	Cube c;
	
	for (int i = 0; i < 8; i++){
		c.vertices[i] = vertices[i];
	}

	for (int i = 0; i < 36; i++){
		c.edges[i] = indices[i];
	}

	return c;
}
