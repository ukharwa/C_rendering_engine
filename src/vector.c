#include "vector.h"
#include <math.h>

Vector2 add_v2(Vector2 *v1, Vector2 *v2){
	Vector2 v3;
	v3.x = v1->x + v2->x;
	v3.y = v1->y + v2->y;
	return v3;
}

Vector2 sub_v2(Vector2 *v1, Vector2 *v2){
	Vector2 v3;
	v3.x = v1->x - v2->x;
	v3.y = v1->y - v2->y;
	return v3;
}

float dot_v2(Vector2 *v1, Vector2 *v2){
	return (((v1->x) * (v2->x)) + ((v1->y) * (v2->y)));
}

Vector2 scale_v2(Vector2 *v, float k){
	Vector2 v1 = {(v->x)*k, (v->y)*k};
	return v1;
}

float cross_v2(Vector2 *v1, Vector2 *v2){
	return (((v1->x) * (v2->y)) - ((v1->y) * (v2->x)));
}

float size_v2(Vector2 *v){
	return sqrt(pow(v->x, 2) + pow(v->y, 2));
}

Vector2 normalize_v2(Vector2 *v){
	float size = size_v2(v);
	Vector2 v1 = {(v->x)/size, (v->y)/size};
	return v1;
}



Vector3 add_v3(Vector3 *v1, Vector3 *v2){
	Vector3 v3;
	v3.x = v1->x + v2->x;
	v3.y = v1->y + v2->y;
	v3.z = v1->z + v2->z;
	return v3;
}

Vector3 sub_v3(Vector3 *v1, Vector3 *v2){
	Vector3 v3;
	v3.x = v1->x - v2->x;
	v3.y = v1->y - v2->y;
	v3.z = v1->z - v2->z;
	return v3;
}

float dot_v3(Vector3 *v1, Vector3 *v2){
	return (((v1->x) * (v2->x)) + ((v1->y) * (v2->y)) + ((v1->z) * (v2->z)));
}

Vector3 scale_v3(Vector3 *v, float k){
	Vector3 v1 = {(v->x)*k, (v->y)*k, (v->z)*k};
	return v1;
}


Vector3 cross_v3(Vector3 *v1, Vector3 *v2){
	Vector3 v3;
	v3.x = ((v1->y) * (v2->z)) - ((v1->z) * (v2->y));
	v3.y = ((v1->z) * (v2->x)) - ((v1->x) * (v2->z));
	v3.z = ((v1->x) * (v2->y)) - ((v1->y) * (v2->x));
	return v3;
}

float size_v3(Vector3 *v){
	return sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
}

Vector3 normalize_v3(Vector3 *v){
	float size = size_v3(v);
	Vector3 v1 = {(v->x)/size, (v->y)/size, (v->z)/size};
	return v1;
}



Vector4 add_v4(Vector4 *v1, Vector4 *v2){
	Vector4 v3;
	v3.x = v1->x + v2->x;
	v3.y = v1->y + v2->y;
	v3.z = v1->z + v2->z;
	v3.w = v1->w + v2->w;
	return v3;
}

Vector4 sub_v4(Vector4 *v1, Vector4 *v2){
	Vector4 v3;
	v3.x = v1->x - v2->x;
	v3.y = v1->y - v2->y;
	v3.z = v1->z - v2->z;
	v3.w = v1->w - v2->w;
	return v3;
}

float dot_v4(Vector4 *v1, Vector4 *v2){
	return ((v1->x) * (v2->x)) + ((v1->y) * (v2->y)) + ((v1->z) * (v2->z)) + ((v1->w) * (v2->w));
}

Vector4 scale_v4(Vector4 *v, float k){
	Vector4 v1 = {(v->x)*k, (v->y)*k, (v->z)*k, (v->w)*k};
	return v1;
}

float size_v4(Vector4 *v){
	return sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2) + pow(v->w, 2));
}

Vector4 normalize_v4(Vector4 *v){
	float size = size_v4(v);
	Vector4 v1 = {(v->x)/size, (v->y)/size, (v->z)/size, (v->w)/size};
	return v1;
}



Vector3 multM3V3(Matrix3 *matrix, Vector3 *vector){
	Vector3 a = matrix->a;
	Vector3 b = matrix->b;
	Vector3 c = matrix->c;
	
	Vector3 v = {dot_v3(&a, vector), dot_v3(&b, vector), dot_v3(&c, vector)};

	return v;
}

Vector4 multM4V4(Matrix4 *matrix, Vector4 *vector){
	Vector4 a = matrix->a;
	Vector4 b = matrix->b;
	Vector4 c = matrix->c;
	Vector4 d = matrix->d;

	Vector4 v = {dot_v4(&a, vector), dot_v4(&b, vector), dot_v4(&c, vector), dot_v4(&d, vector)};

	return v;
}
