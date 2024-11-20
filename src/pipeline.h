#pragma once
#include "vector.h"

Matrix4 get_view_matrix(Vec3 *c, Vec3 *t, Vec3 *u);
Matrix4 get_projection_matrix(int width, int height, float theta, float zfar, float znear);
Vec4 perspective_divide(Vec4 *v);
Vec2 image_space_to_screen_space(int width, int height, Vec4 *v);
Vec2 world_space_to_screen_space(int width, int height, float fov, float znear, float zfar, Matrix3 *camera, Vec3 *v);
