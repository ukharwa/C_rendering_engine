#include <stdio.h>
#include "vector.h"

int main(){
	Vec3 v = {4, 6, 6};
	Vec3 v2 = {3, 1, 2};

	Vec3 sub = sub_v3(&v, &v2);
	
	printf("sub: {%f, %f, %f}\n", sub.vec.x, sub.vec.y, sub.vec.z);
	return 0;
}
