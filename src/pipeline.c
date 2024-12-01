#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

void draw_triangle(frameBuffer *buffer, Vec2 *p0, Vec2 *p1, Vec2 *p2){

	Vec2 e0 = sub_v2(p1, p0);
	Vec2 e1 = sub_v2(p2, p1);
	Vec2 e2 = sub_v2(p0, p2);

	float y_max = max_3(p0, p1, p2).y;
	float x_max = max_3(p0, p1, p2).x;
	float y_min = min_3(p0, p1, p2).y;
	float x_min = min_3(p0, p1, p2).x;
	
	int bufferPos = 0;
	for (int i = y_min; i < y_max; i++){
		for (int j = x_min; j < x_max; j++){
			Vec2 c0 = sub_v2(&(Vec2){j, i}, p0);
			Vec2 c1 = sub_v2(&(Vec2){j, i}, p1);
			Vec2 c2 = sub_v2(&(Vec2){j, i}, p2);
			int w0 = cross_v2(&e0, &c0);
			int w1 = cross_v2(&e1, &c1);
			int w2 = cross_v2(&e2, &c2);
			
			if (w0 >= 0 && w1 >= 0 && w2 >= 0){
				buffer->pixels[i][j] = (Vec3){255, 255, 255};
			}
		}
	}
}

void draw_scene(SDL_Renderer *renderer ,int width, int height, float fov, float znear, float zfar, Matrix3 *camera, VertexBufferObj vBuffer, IndexBufferObj iBuffer){
	Matrix4 view_mat = get_view_matrix(camera);
	Matrix4 proj_mat = get_projection_matrix(width, height, fov, znear, zfar);
	Vec2 vecBuffer[vBuffer.size]; 

	for (int i = 0; i < vBuffer.size; i++){
		Vec4 ndc = get_NDC(&view_mat, &proj_mat, &vBuffer.vertices[i]);
		Vec2 screen_v = image_space_to_screen_space(width, height, &ndc);
		vecBuffer[i] = screen_v;
	}
	
	frameBuffer fBuffer = newFrameBuffer(width, height);

	for (int i = 0; i < iBuffer.size; i += 3){
		draw_triangle(&fBuffer, &vecBuffer[iBuffer.indices[i]], &vecBuffer[iBuffer.indices[i+1]], &vecBuffer[iBuffer.indices[i+2]]);
	}
	
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			SDL_SetRenderDrawColor(renderer, fBuffer.pixels[i][j].x, fBuffer.pixels[i][j].y, fBuffer.pixels[i][j].y, 255);
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
}

//void show_axes(SDL_Renderer *renderer, int width, int height, float fov, float znear, float zfar, Matrix3 *camera, float length){
//
//	Vec2 x1 = world_space_to_screen_space(width, height, fov, znear, zfar, camera, &(Vec3){-length, 0, 0});
//	Vec2 x2 = world_space_to_screen_space(width, height, fov, znear, zfar, camera, &(Vec3){length, 0, 0});
//
//	Vec2 y1 = world_space_to_screen_space(width, height, fov, znear, zfar, camera, &(Vec3){0, -length, 0});
//	Vec2 y2 = world_space_to_screen_space(width, height, fov, znear, zfar, camera, &(Vec3){0, length, 0});
//	
//	Vec2 z1 = world_space_to_screen_space(width, height, fov, znear, zfar, camera, &(Vec3){0, 0, -length});
//	Vec2 z2 = world_space_to_screen_space(width, height, fov, znear, zfar, camera, &(Vec3){0, 0, length});
//
//	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//	SDL_RenderDrawLine(renderer, x1.x, x1.y, x2.x, x2.y);
//	
//	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
//	SDL_RenderDrawLine(renderer, y1.x, y1.y, y2.x, y2.y);
//	
//	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
//	SDL_RenderDrawLine(renderer, z1.x, z1.y, z2.x, z2.y);
//	
//	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//	SDL_RenderDrawPoint(renderer, x2.x, x2.y);
//	SDL_RenderDrawPoint(renderer, y2.x, y2.y);
//	SDL_RenderDrawPoint(renderer, z2.x, z2.y);
//}

