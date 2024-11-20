
#include "pipeline.h"
#include <math.h>

Matrix4 get_view_matrix(Vector3 *c, Vector3 *t, Vector3 *u){
	Vector3 F = sub_v3(t, c);
	F = normalize_v3(&F);
	Vector3 nF = scale_v3(&F, -1);

	Vector3 R = cross_v3(&F, u);
	R = normalize_v3(&R);
	Vector3 nR = scale_v3(&R, -1);
	
	Vector3 U = cross_v3(&R, &F);
	Vector3 nU = scale_v3(&U, -1);

	Vector4 v1 = {R.x, R.y, R.z, dot_v3(&nR, c)};
	Vector4 v2 = {U.x, U.y, U.z, dot_v3(&nU, c)};
	Vector4 v3 = {nF.x, nF.y, nF.z, dot_v3(&F, c)};
	Vector4 v4 = {0, 0, 0, 1};

	Matrix4 m = {v1, v2, v3, v4};
	return m;
}

Matrix4 get_projection_matrix(int width, int height, float theta, float zfar, float znear){
	float a = (float)height/width;
	float f = 1/tan(theta/2);
	float lambda = zfar/(zfar - znear);

	Vector4 v1 = {a*f, 0, 0, 0};
	Vector4 v2 = {0, f, 0, 0};
	Vector4 v3 = {0, 0, lambda, -(lambda * znear)};
	Vector4 v4 = {0, 0, 1, 0};

	Matrix4 m = {v1, v2, v3, v4};
	return m;
}

Vector4 perspective_divide(Vector4 *v){
	float w = v->w;
	Vector4 v1;
	v1.x = v->x / w;
	v1.y = v->y / w;
	v1.z = v->z / w;
	v1.w =  w;
	return v1;
}

Vector2 image_space_to_screen_space(int width, int height, Vector4 *v){
	Vector2 v1 = {((v->x + 1)/2) * width, ((v->y + 1)/2) * height};
	return v1;
}

Vector2 world_space_to_screen_space(int width, int height, float fov, float znear, float zfar, Matrix3 *camera, Vector3 *v){
	Matrix4 view_matrix = get_view_matrix(&camera->a, &camera->b, &camera->c);
	Matrix4 projection_matrix = get_projection_matrix(width, height, fov, zfar, znear);
	
	Vector4 homo_v = {v->x, v->y, v->z, 1};
	Vector4 view_v = multM4V4(&view_matrix, &homo_v);
	Vector4 clip_v = multM4V4(&projection_matrix, &view_v);
	Vector4 perspective_v = perspective_divide(&clip_v);
	Vector2 screen_v = image_space_to_screen_space(width, height, &perspective_v);

	return screen_v;
}
