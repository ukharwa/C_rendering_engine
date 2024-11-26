#include <SDL2/SDL.h>
#include <math.h>

#include "pipeline.h"
#include "vector.h"
#include "buffer.h"

Matrix4 get_view_matrix(Matrix3 *camera){
	Vec3 c = camera->arr[0];
	Vec3 t = camera->arr[1];
	Vec3 u = camera->arr[2];

	Vec3 F = sub_v3(&t, &c);
	F = normalize_v3(&F);
	Vec3 nF = scale_v3(&F, -1);

	Vec3 R = cross_v3(&F, &u);
	R = normalize_v3(&R);
	Vec3 nR = scale_v3(&R, -1);
	
	Vec3 U = cross_v3(&R, &F);
	Vec3 nU = scale_v3(&U, -1);
	
	Matrix4 m; 
	m.arr[0] = new_vec4(R.x, R.y, R.z, dot_v3(&nR, &c));
	m.arr[1] = new_vec4(U.x, U.y, U.z, dot_v3(&nU, &c));
	m.arr[2] = new_vec4(nF.x, nF.y, nF.z, dot_v3(&F, &c));
	m.arr[3] = new_vec4(0, 0, 0, 1);

	return m;
}

Matrix4 get_projection_matrix(int width, int height, float fov, float znear, float zfar){
	float a = (float)width/height;
	float f = 1/(tan(fov/2));

	Vec4 v1 = {f/a, 0, 0, 0};
	Vec4 v2 = {0, f, 0, 0};
	Vec4 v3 = {0, 0, (-(zfar + znear)/(zfar - znear)), (-(2*zfar*znear)/(zfar-znear))};
	Vec4 v4 = {0, 0, -1, 0};

	Matrix4 m = {v1, v2, v3, v4};
	return m;
}

Vec4 perspective_divide(Vec4 *v){
	float w = v->w;
	Vec4 v1 = {v->x / w, v->y / w, v->z / w, w};
	return v1;
}

Vec2 image_space_to_screen_space(int width, int height, Vec4 *v){
	Vec2 v1 = {((v->x + 1)/2) * width, height - (((v->y + 1)/2) * height)};
	return v1;
}

Vec4 get_NDC(Matrix4 *view, Matrix4 *proj, Vec3 *v){
	
	Vec4 homo_v = {v->x, v->y, v->z, 1};
	Vec4 view_v = multM4V4(view, &homo_v);
	Vec4 clip_v = multM4V4(proj, &view_v);
	Vec4 ndc = perspective_divide(&clip_v);

	return ndc;
}

void draw_scene(SDL_Renderer *renderer ,int width, int height, float fov, float znear, float zfar, Matrix3 *camera, VertexBufferObj vBuffer, IndexBufferObj iBuffer){
	Matrix4 view_mat = get_view_matrix(camera);
	Matrix4 proj_mat = get_projection_matrix(width, height, fov, znear, zfar);
	Vec2 frameBuffer[vBuffer.size]; 

	for (int i = 0; i < vBuffer.size; i++){
		Vec4 ndc = get_NDC(&view_mat, &proj_mat, &vBuffer.vertices[i]);
		Vec2 screen_v = image_space_to_screen_space(width, height, &ndc);
		frameBuffer[i] = screen_v;
	}

	for (int i = 0; i < iBuffer.size; i += 3){
		Vec2 p1 = frameBuffer[iBuffer.indices[i]];
		Vec2 p2 = frameBuffer[iBuffer.indices[i+1]];
		Vec2 p3 = frameBuffer[iBuffer.indices[i+2]];
		SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
		SDL_RenderDrawLine(renderer, p2.x, p2.y, p3.x, p3.y);
		SDL_RenderDrawLine(renderer, p3.x, p3.y, p1.x, p1.y);
	}


}

