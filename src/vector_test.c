#include <stdio.h>
#include "vector.h"

int main(){
	Vector2 v2_1 = {12, 2};
	Vector2 v2_2 = {3, 64};

	Vector3 v3_1 = {1, 2, 300};
	Vector3 v3_2 = {14, 5, 6};
	Vector3 v3_3 = {4, 6, 6};
	Vector3 v3_4 = {12, 3, 2};

	Vector4 v4_1 = {32, 234, 2, 94};
	Vector4 v4_2 = {3, 4, 0, 0};
	Vector4 v4_3 = {4, 32, 21, 23};
	Vector4 v4_4 = {29, 12, 39, 2};
	Vector4 v4_5 = {94, 309, 0, 1};

	Vector2 sum2 = add_v2(&v2_1, &v2_2);
	Vector2 diff2 = sub_v2(&v2_2, &v2_1);
	float dot2 = dot_v2(&v2_1, &v2_2);
	float cross2 = cross_v2(&v2_1, &v2_2);

	Vector3 sum3 = add_v3(&v3_1, &v3_2);
	Vector3 diff3 = sub_v3(&v3_2, &v3_1);
	float dot3 = dot_v3(&v3_1, &v3_2);
	Vector3 cross3 = cross_v3(&v3_1, &v3_2);
	
	Vector4 sum4 = add_v4(&v4_1, &v4_2);
	Vector4 diff4 = sub_v4(&v4_2, &v4_1);
	float dot4 = dot_v4(&v4_1, &v4_2);
	
	printf("Vector2:\n");
	printf("   add: \{%f, %f}\n", sum2.x, sum2.y);
	printf("   sub: \{%f, %f}\n", diff2.x, diff2.y);
	printf("   dot: %f\n", dot2);
	printf(" cross: %f\n", cross2);

	printf("\nVector3:\n");
	printf("   add: \{%f, %f, %f}\n", sum3.x, sum3.y, sum3.z);
	printf("   sub: \{%f, %f, %f}\n", diff3.x, diff3.y, diff3.z);
	printf("   dot: %f\n", dot3);
	printf(" cross: \{%f, %f, %f}\n", cross3.x, cross3.y, cross3.z);

	printf("\nVector4:\n");
	printf("   add: \{%f, %f, %f, %f}\n", sum4.x, sum4.y, sum4.z, sum4.w);
	printf("   sub: \{%f, %f, %f, %f}\n", diff4.x, diff4.y, diff4.z, diff4.w);
	printf("   dot: %f\n", dot4);

	Matrix3 m3 = {v3_1, v3_2, v3_3};
	Matrix4 m4 = {v4_1, v4_2, v4_3, v4_4};

	Vector3 m3_mult = multM3V3(&m3, &v3_4);
	Vector4 m4_mult = multM4V4(&m4, &v4_5);
	
	printf("   m3xv3: \{%f, %f, %f}\n", m3_mult.x, m3_mult.y, m3_mult.z);
	printf("   m4xv4: \{%f, %f, %f, %f}\n", m4_mult.x, m4_mult.y, m4_mult.z, m4_mult.w);

	return 0;
}
