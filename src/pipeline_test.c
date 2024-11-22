#include "pipeline.h"
#include "vector.h"
#include <stdio.h>

int main(){
	Matrix3 camera = {new_vec3(1, 0, 0), new_vec3(0, 0, -1), new_vec3(0, 1, 0)};
	Matrix4 view = get_view_matrix(&camera.arr[0], &camera.arr[1], &camera.arr[2]);
	Vec4 v =  {2, 2, -2, 1};
	Vec4 trans = multM4V4(&view, &v);

	printf("View Matrix: {%f, %f, %f, %f}\n", view.arr[0].vec.x, view.arr[0].vec.y, view.arr[0].vec.z, view.arr[0].vec.w);
	printf("             {%f, %f, %f, %f}\n", view.arr[1].vec.x, view.arr[1].vec.y, view.arr[1].vec.z, view.arr[1].vec.w);
	printf("             {%f, %f, %f, %f}\n", view.arr[2].vec.x, view.arr[2].vec.y, view.arr[2].vec.z, view.arr[2].vec.w);
	printf("             {%f, %f, %f, %f}\n", view.arr[3].vec.x, view.arr[3].vec.y, view.arr[3].vec.z, view.arr[3].vec.w);
	
	printf("Vec: {%f, %f, %f, %f}\n", trans.vec.x, trans.vec.y, trans.vec.z, trans.vec.w);

	return 0;
}
