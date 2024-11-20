#pragma once
#include "vector.h"

Matrix4 get_view_matrix(Vector3 *c, Vector3 *t, Vector3 *u);
Matrix4 get_projection_matrix(int width, int height, float theta, float zfar, float znear);
Vector4 perspective_divide(Vector4 *v);
Vector2 image_space_to_screen_space(int width, int height, Vector4 *v);
Vector2 world_space_to_screen_space(int width, int height, float fov, float znear, float zfar, Matrix3 *camera, Vector3 *v);
