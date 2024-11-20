
#include "pipeline.h"
#include "vector.h"
#include <math.h>

Matrix4 get_view_matrix(Vec3 *c, Vec3 *t, Vec3 *u){
	Vec3 F = sub_v3(t, c);
	F = normalize_v3(&F);
	Vec3 nF = scale_v3(&F, -1);

	Vec3 R = cross_v3(&F, u);
	R = normalize_v3(&R);
	Vec3 nR = scale_v3(&R, -1);
	
	Vec3 U = cross_v3(&R, &F);
	Vec3 nU = scale_v3(&U, -1);
	
	Matrix4 m; 
	m.arr[0] = (Vec4){R.vec.x, R.vec.y, R.vec.z, dot_v3(&nR, c)};
	m.arr[1] = (Vec4){U.vec.x, U.vec.y, U.vec.z, dot_v3(&nU, c)};
	m.arr[2] = (Vec4){nF.vec.x, nF.vec.y, nF.vec.z, dot_v3(&F, c)};
	m.arr[3] = (Vec4){0, 0, 0, 1};

	return m;
}

Matrix4 get_projection_matrix(int width, int height, float theta, float zfar, float znear){
	float a = (float)height/width;
	float f = 1/tan(theta/2);
	float lambda = zfar/(zfar - znear);

	Vec4 v1 = {a*f, 0, 0, 0};
	Vec4 v2 = {0, f, 0, 0};
	Vec4 v3 = {0, 0, lambda, -(lambda * znear)};
	Vec4 v4 = {0, 0, 1, 0};

	Matrix4 m = {v1, v2, v3, v4};
	return m;
}

Vec4 perspective_divide(Vec4 *v){
	float w = v->vec.w;
	Vec4 v1 = {v->vec.x / w, v->vec.y / w, v->vec.z / w, w};
	return v1;
}

Vec2 image_space_to_screen_space(int width, int height, Vec4 *v){
	Vec2 v1 = {((v->vec.x + 1)/2) * width, ((v->vec.y + 1)/2) * height};
	return v1;
}

Vec2 world_space_to_screen_space(int width, int height, float fov, float znear, float zfar, Matrix3 *camera, Vec3 *v){
	Matrix4 view_matrix = get_view_matrix(&camera->arr[0], &camera->arr[1], &camera->arr[3]);
	Matrix4 projection_matrix = get_projection_matrix(width, height, fov, zfar, znear);
	
	Vec4 homo_v = {v->vec.x, v->vec.y, v->vec.z, 1};
	Vec4 view_v = multM4V4(&view_matrix, &homo_v);
	Vec4 clip_v = multM4V4(&projection_matrix, &view_v);
	Vec4 perspective_v = perspective_divide(&clip_v);
	Vec2 screen_v = image_space_to_screen_space(width, height, &perspective_v);

	return screen_v;
}
