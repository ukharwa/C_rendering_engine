#include "vector.h"
#include <math.h>

Vec2 add_v2(Vec2 *v1, Vec2 *v2){
	Vec2 v3 = {v1->vec.x + v2->vec.x, v1->vec.y + v2->vec.y};
	return v3;
}

Vec2 sub_v2(Vec2 *v1, Vec2 *v2){
	Vec2 v3 = {v1->vec.x - v2->vec.x, v1->vec.y - v2->vec.y};
	return v3;
}

float dot_v2(Vec2 *v1, Vec2 *v2){
	return (((v1->vec.x) * (v2->vec.x)) + ((v1->vec.y) * (v2->vec.y)));
}

Vec2 scale_v2(Vec2 *v, float k){
	Vec2 v1 = {(v->vec.x)*k, (v->vec.y)*k};
	return v1;
}

float cross_v2(Vec2 *v1, Vec2 *v2){
	return (((v1->vec.x) * (v2->vec.y)) - ((v1->vec.y) * (v2->vec.x)));
}

float size_v2(Vec2 *v){
	return sqrt(pow(v->vec.x, 2) + pow(v->vec.y, 2));
}

Vec2 normalize_v2(Vec2 *v){
	float size = size_v2(v);
	Vec2 v1 = {(v->vec.x)/size, (v->vec.y)/size};
	return v1;
}



Vec3 add_v3(Vec3 *v1, Vec3 *v2){
	Vec3 v3 = {v1->vec.x + v2->vec.x, v1->vec.y + v2->vec.y, v1->vec.z + v2->vec.z};
	return v3;
}

Vec3 sub_v3(Vec3 *v1, Vec3 *v2){
	Vec3 v3 = {v1->vec.x - v2->vec.x, v1->vec.y - v2->vec.y, v1->vec.z - v2->vec.z};
	return v3;
}

float dot_v3(Vec3 *v1, Vec3 *v2){
	return (((v1->vec.x) * (v2->vec.x)) + ((v1->vec.y) * (v2->vec.y)) + ((v1->vec.z) * (v2->vec.z)));
}

Vec3 scale_v3(Vec3 *v, float k){
	Vec3 v1 = {(v->vec.x)*k, (v->vec.y)*k, (v->vec.z)*k};
	return v1;
}


Vec3 cross_v3(Vec3 *v1, Vec3 *v2){
	Vec3 v3;
	v3.vec.x = ((v1->vec.y) * (v2->vec.z)) - ((v1->vec.z) * (v2->vec.y));
	v3.vec.y = ((v1->vec.z) * (v2->vec.x)) - ((v1->vec.x) * (v2->vec.z));
	v3.vec.z = ((v1->vec.x) * (v2->vec.y)) - ((v1->vec.y) * (v2->vec.x));
	return v3;
}

float size_v3(Vec3 *v){
	return sqrt(pow(v->vec.x, 2) + pow(v->vec.y, 2) + pow(v->vec.z, 2));
}

Vec3 normalize_v3(Vec3 *v){
	float size = size_v3(v);
	Vec3 v1 = {(v->vec.x)/size, (v->vec.y)/size, (v->vec.z)/size};
	return v1;
}



Vec4 add_v4(Vec4 *v1, Vec4 *v2){
	Vec4 v3 = {v1->vec.x + v2->vec.x, v1->vec.y + v2->vec.y, v1->vec.z + v2->vec.z, v1->vec.w + v2->vec.w};
	return v3;
}


Vec4 sub_v4(Vec4 *v1, Vec4 *v2){
	Vec4 v3;
	v3.vec.x = v1->vec.x - v2->vec.x;
	v3.vec.y = v1->vec.y - v2->vec.y;
	v3.vec.z = v1->vec.z - v2->vec.z;
	v3.vec.w = v1->vec.w - v2->vec.w;
	return v3;
}

float dot_v4(Vec4 *v1, Vec4 *v2){
	return ((v1->vec.x) * (v2->vec.x)) + ((v1->vec.y) * (v2->vec.y)) + ((v1->vec.z) * (v2->vec.z)) + ((v1->vec.w) * (v2->vec.w));
}

Vec4 scale_v4(Vec4 *v, float k){
	Vec4 v1 = {(v->vec.x)*k, (v->vec.y)*k, (v->vec.z)*k, (v->vec.w)*k};
	return v1;
}

float size_v4(Vec4 *v){
	return sqrt(pow(v->vec.x, 2) + pow(v->vec.y, 2) + pow(v->vec.z, 2) + pow(v->vec.w, 2));
}

Vec4 normalize_v4(Vec4 *v){
	float size = size_v4(v);
	Vec4 v1 = {(v->vec.x)/size, (v->vec.y)/size, (v->vec.z)/size, (v->vec.w)/size};
	return v1;
}



Vec3 multM3V3(Matrix3 *matrix, Vec3 *vector){
	Vec3 v;
	for (int i = 0; i < 3; i++){
		v.arr[i] = dot_v3(&matrix->arr[i], vector);
	}
	return v;
}

Vec4 multM4V4(Matrix4 *matrix, Vec4 *vector){
	Vec4 v;
	for (int i = 0; i < 4; i++){
		v.arr[i] = dot_v4(&matrix->arr[i], vector);
	}
	return v;
}

