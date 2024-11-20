#include <stdio.h>
#include "vector.h"

int main(){
	printf("Vector3 size: %d\n", (int)sizeof(Vector3));
	printf("float size: %d\n", (int)sizeof(float));
	printf("union vec size: %d\n", (int)sizeof(Vec3));

	Vec3 v = {1, 2, 3};
	
	printf("arrVec: \{%f, %f, %f}\n", v.arrVec[0], v.arrVec[1], v.arrVec[2]);
	printf("Vec vec: \{%f, %f, %f}\n", v.vec.x, v.vec.y, v.vec.z);
	return 0;
}
