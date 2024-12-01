#pragma once

typedef struct Vector2{
	float x, y;
} Vec2;

typedef struct Vector3{
	float x, y, z;
} Vec3;

typedef struct Vector4{
	float x, y, z, w;
} Vec4;

typedef struct Matrix3{
	Vec3 arr[3];
} Matrix3;

typedef struct Matrix4{
	Vec4 arr[4];
} Matrix4;

Vec2 add_v2(Vec2* v1, Vec2* v2);
Vec2 sub_v2(Vec2* v1, Vec2* v2);
float dot_v2(Vec2* v1, Vec2* v2);
Vec2 scale_v2(Vec2* v, float k);
float cross_v2(Vec2* v1, Vec2* v2);
float size_v2(Vec2* v);
Vec2 normalize_v2(Vec2 *v);
Vec2 new_vec2(float x, float y);
Vec2 min(Vec2* v1, Vec2* v2);
Vec2 max(Vec2* v1, Vec2* v2);
Vec2 max_3(Vec2* v1, Vec2* v2, Vec2 *v3);
Vec2 min_3(Vec2* v1, Vec2* v2, Vec2 *v3);

Vec3 add_v3(Vec3* v1, Vec3* v2);
Vec3 sub_v3(Vec3* v1, Vec3* v2);
float dot_v3(Vec3* v1, Vec3* v2);
Vec3 scale_v3(Vec3* v, float k);
Vec3 cross_v3(Vec3* v1, Vec3* v2);
float size_v3(Vec3* v);
Vec3 normalize_v3(Vec3 *v);
Vec3 new_vec3(float x, float y, float z);

Vec4 add_v4(Vec4* v1, Vec4* v2);
Vec4 sub_v4(Vec4* v1, Vec4* v2);
float dot_v4(Vec4* v1, Vec4* v2);
Vec4 scale_v4(Vec4* v, float k);
float size_v4(Vec4* v);
Vec4 normalize_v4(Vec4 *v);
Vec4 new_vec4(float x, float y, float z, float w);

Vec3 multM3V3(Matrix3 *matrix, Vec3 *vector);
Vec4 multM4V4(Matrix4 *matrix, Vec4 *vector);

