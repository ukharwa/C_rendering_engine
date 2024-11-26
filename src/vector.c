#include "vector.h"
#include <math.h>

Vec2 new_vec2(float x, float y){
	Vec2 v = {x, y};
	return v;
}

Vec2 add_v2(Vec2 *v1, Vec2 *v2){
	Vec2 v3 = {v1->x + v2->x, v1->y + v2->y};
	return v3;
}

Vec2 sub_v2(Vec2 *v1, Vec2 *v2){
	Vec2 v3 = {v1->x - v2->x, v1->y - v2->y};
	return v3;
}

float dot_v2(Vec2 *v1, Vec2 *v2){
	return (((v1->x) * (v2->x)) + ((v1->y) * (v2->y)));
}

Vec2 scale_v2(Vec2 *v, float k){
	Vec2 v1 = {(v->x)*k, (v->y)*k};
	return v1;
}

float cross_v2(Vec2 *v1, Vec2 *v2){
	return (((v1->x) * (v2->y)) - ((v1->y) * (v2->x)));
}

float size_v2(Vec2 *v){
	return sqrt(pow(v->x, 2) + pow(v->y, 2));
}

Vec2 normalize_v2(Vec2 *v){
	float size = size_v2(v);
	Vec2 v1 = {(v->x)/size, (v->y)/size};
	return v1;
}

Vec2 min(Vec2 *v1, Vec2 *v2){
	Vec2 v = {(v1->x < v2->x ?  v1->x : v2 ->x), (v1->y < v2->y ?  v1->y : v2 ->y)};
	return v;
}

Vec2 max(Vec2 *v1, Vec2 *v2){
	Vec2 v = {(v1->x > v2->x ?  v1->x : v2 ->x), (v1->y > v2->y ?  v1->y : v2 ->y)};
	return v;
}



Vec3 new_vec3(float x, float y, float z){
	Vec3 v = {x, y, z};
	return v;
}

Vec3 add_v3(Vec3 *v1, Vec3 *v2){
	Vec3 v3 = {v1->x + v2->x, v1->y + v2->y, v1->z + v2->z};
	return v3;
}

Vec3 sub_v3(Vec3 *v1, Vec3 *v2){
	Vec3 v3 = {v1->x - v2->x, v1->y - v2->y, v1->z - v2->z};
	return v3;
}

float dot_v3(Vec3 *v1, Vec3 *v2){
	return (((v1->x) * (v2->x)) + ((v1->y) * (v2->y)) + ((v1->z) * (v2->z)));
}

Vec3 scale_v3(Vec3 *v, float k){
	Vec3 v1 = {(v->x)*k, (v->y)*k, (v->z)*k};
	return v1;
}


Vec3 cross_v3(Vec3 *v1, Vec3 *v2){
	Vec3 v3;
	v3.x = ((v1->y) * (v2->z)) - ((v1->z) * (v2->y));
	v3.y = -(((v1->x) * (v2->z)) - ((v1->z) * (v2->x)));
	v3.z = ((v1->x) * (v2->y)) - ((v1->y) * (v2->x));
	return v3;
}

float size_v3(Vec3 *v){
	return sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
}

Vec3 normalize_v3(Vec3 *v){
	float size = size_v3(v);
	Vec3 v1 = {(v->x)/size, (v->y)/size, (v->z)/size};
	return v1;
}



Vec4 new_vec4(float x, float y, float z, float w){
	Vec4 v = {x, y, z, w};
	return v;
}

Vec4 add_v4(Vec4 *v1, Vec4 *v2){
	Vec4 v3 = {v1->x + v2->x, v1->y + v2->y, v1->z + v2->z, v1->w + v2->w};
	return v3;
}


Vec4 sub_v4(Vec4 *v1, Vec4 *v2){
	Vec4 v3;
	v3.x = v1->x - v2->x;
	v3.y = v1->y - v2->y;
	v3.z = v1->z - v2->z;
	v3.w = v1->w - v2->w;
	return v3;
}

float dot_v4(Vec4 *v1, Vec4 *v2){
	return ((v1->x) * (v2->x)) + ((v1->y) * (v2->y)) + ((v1->z) * (v2->z)) + ((v1->w) * (v2->w));
}

Vec4 scale_v4(Vec4 *v, float k){
	Vec4 v1 = {(v->x)*k, (v->y)*k, (v->z)*k, (v->w)*k};
	return v1;
}

float size_v4(Vec4 *v){
	return sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2) + pow(v->w, 2));
}

Vec4 normalize_v4(Vec4 *v){
	float size = size_v4(v);
	Vec4 v1 = {(v->x)/size, (v->y)/size, (v->z)/size, (v->w)/size};
	return v1;
}


Vec3 multM3V3(Matrix3 *matrix, Vec3 *vector){
	Vec3 v = {dot_v3(&matrix->arr[0], vector), dot_v3(&matrix->arr[1], vector), dot_v3(&matrix->arr[2], vector)};
	return v;
}

Vec4 multM4V4(Matrix4 *matrix, Vec4 *vector){
	Vec4 v = {dot_v4(&matrix->arr[0], vector), dot_v4(&matrix->arr[1], vector), dot_v4(&matrix->arr[2], vector), dot_v4(&matrix->arr[3], vector)};
	return v;
}

