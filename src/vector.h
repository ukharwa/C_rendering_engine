#pragma once

typedef struct Vector2{
	float x, y;
} Vector2;

typedef struct Vector3{
	float x, y, z;
} Vector3;

typedef struct Vector4{
	float x, y, z, w;
} Vector4;

typedef struct Matrix3{
	Vector3 a, b, c;
} Matrix3;

typedef struct Matrix4{
	Vector4 a, b, c, d;
} Matrix4;

Vector2 add_v2(Vector2* v1, Vector2* v2);
Vector2 sub_v2(Vector2* v1, Vector2* v2);
float dot_v2(Vector2* v1, Vector2* v2);
Vector2 scale_v2(Vector2* v, float k);
float cross_v2(Vector2* v1, Vector2* v2);
float size_v2(Vector2* v);
Vector2 normalize_v2(Vector2 *v);

Vector3 add_v3(Vector3* v1, Vector3* v2);
Vector3 sub_v3(Vector3* v1, Vector3* v2);
float dot_v3(Vector3* v1, Vector3* v2);
Vector3 scale_v3(Vector3* v, float k);
Vector3 cross_v3(Vector3* v1, Vector3* v2);
float size_v3(Vector3* v);
Vector3 normalize_v3(Vector3 *v);

Vector4 add_v4(Vector4* v1, Vector4* v2);
Vector4 sub_v4(Vector4* v1, Vector4* v2);
float dot_v4(Vector4* v1, Vector4* v2);
Vector4 scale_v4(Vector4* v, float k);
float size_v4(Vector4* v);
Vector4 normalize_v4(Vector4 *v);

Vector3 multM3V3(Matrix3 *matrix, Vector3 *vector);
Vector4 multM4V4(Matrix4 *matrix, Vector4 *vector);

