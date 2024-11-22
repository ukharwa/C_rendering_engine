
#include "pipeline.h"
#include "vector.h"
#include <math.h>
#include <stdio.h>

Matrix4 get_view_matrix(Matrix3 *camera){
	Vec3 c = camera->arr[0];
	Vec3 t = camera->arr[1];
	Vec3 u = camera->arr[2];

	Vec3 F = sub_v3(&t, &c);
	F = normalize_v3(&F);
	Vec3 nF = scale_v3(&F, -1);

	Vec3 R = cross_v3(&u, &F);
	R = normalize_v3(&R);
	Vec3 nR = scale_v3(&R, -1);
	
	Vec3 U = cross_v3(&F, &R);
	Vec3 nU = scale_v3(&U, -1);
	
	Matrix4 m; 
	m.arr[0] = new_vec4(R.vec.x, R.vec.y, R.vec.z, dot_v3(&nR, &c));
	m.arr[1] = new_vec4(U.vec.x, U.vec.y, U.vec.z, dot_v3(&nU, &c));
	m.arr[2] = new_vec4(nF.vec.x, nF.vec.y, nF.vec.z, dot_v3(&F, &c));
	m.arr[3] = new_vec4(0, 0, 0, 1);

	return m;
}

Matrix4 get_projection_matrix(int width, int height, float theta, float znear, float zfar){
	float a = (float)height/width;
	float f = 1/(tan(theta/2));
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
	Matrix4 view = get_view_matrix(camera);
	Matrix4 projection_matrix = get_projection_matrix(width, height, fov, znear, zfar);
	
	printf("View Matrix: {%f, %f, %f, %f}\n", view.arr[0].vec.x, view.arr[0].vec.y, view.arr[0].vec.z, view.arr[0].vec.w);
	printf("             {%f, %f, %f, %f}\n", view.arr[1].vec.x, view.arr[1].vec.y, view.arr[1].vec.z, view.arr[1].vec.w);
	printf("             {%f, %f, %f, %f}\n", view.arr[2].vec.x, view.arr[2].vec.y, view.arr[2].vec.z, view.arr[2].vec.w);
	printf("             {%f, %f, %f, %f}\n", view.arr[3].vec.x, view.arr[3].vec.y, view.arr[3].vec.z, view.arr[3].vec.w);
	
	Vec4 homo_v = {v->vec.x, v->vec.y, v->vec.z, 1};
	Vec4 view_v = multM4V4(&view, &homo_v);
	printf("View: {%f, %f, %f, %f}\n", view_v.vec.x, view_v.vec.y, view_v.vec.z, view_v.vec.w);
	Vec4 clip_v = multM4V4(&projection_matrix, &view_v);
	printf("Clip: {%f, %f, %f, %f}\n", clip_v.vec.x, clip_v.vec.y, clip_v.vec.z, clip_v.vec.w);
	Vec4 perspective_v = perspective_divide(&clip_v);
	printf("pers: {%f, %f, %f, %f}\n", perspective_v.vec.x, perspective_v.vec.y, perspective_v.vec.z, perspective_v.vec.w);
	Vec2 screen_v = image_space_to_screen_space(width, height, &perspective_v);
	printf("image: {%f, %f}\n", screen_v.vec.x, screen_v.vec.y);
	printf("\n");

	return screen_v;
}
