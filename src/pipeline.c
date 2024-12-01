#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <stdbool.h>
#include <stdio.h>

#include "pipeline.h"
#include "vector.h"
#include "buffer.h"
#include "vertex_shader.h"

void rasterize_triangle(frameBuffer *buffer, Vertex *v0, Vertex *v1, Vertex *v2){
	Vec2 p0 = {v0->pos.x, v0->pos.y};
	Vec2 p1 = {v1->pos.x, v1->pos.y};
	Vec2 p2 = {v2->pos.x, v2->pos.y};

	Vec2 e0 = sub_v2(&p1, &p0);
	Vec2 e1 = sub_v2(&p2, &p1);
	Vec2 e2 = sub_v2(&p0, &p2);

	bool b0 = ((e0.y == 0 && e0.x > 0) || e0.y < 0) ? 0 : -1;
	bool b1 = ((e1.y == 0 && e1.x > 0) || e1.y < 0) ? 0 : -1;
	bool b2 = ((e2.y == 0 && e2.x > 0) || e2.y < 0) ? 0 : -1;

	float y_max = max_3(&p0, &p1, &p2).y;
	float x_max = max_3(&p0, &p1, &p2).x;
	float y_min = min_3(&p0, &p1, &p2).y;
	float x_min = min_3(&p0, &p1, &p2).x;
	
	int bufferPos = 0;
	for (int i = y_min; i < y_max; i++){
		for (int j = x_min; j < x_max; j++){
			Vec2 c0 = sub_v2(&(Vec2){j, i}, &p0);
			Vec2 c1 = sub_v2(&(Vec2){j, i}, &p1);
			Vec2 c2 = sub_v2(&(Vec2){j, i}, &p2);

			int w0 = cross_v2(&e0, &c0) + b0;
			int w1 = cross_v2(&e1, &c1) + b1;
			int w2 = cross_v2(&e2, &c2) + b2;
			
			if (w0 >= 0 && w1 >= 0 && w2 >= 0){
				buffer->pixels[i][j] = (Vec3){255, 255, 255};
			}
		}
	}
}

void draw_scene(SDL_Renderer *renderer ,int width, int height, float fov, float znear, float zfar, Matrix3 *camera, VertexBufferObj vBuffer, IndexBufferObj iBuffer){

	for (int i = 0; i < vBuffer.size; i++){
		vertexTransform(width, height, fov, zfar, znear, camera, &vBuffer.vertices[i]);
	}
	
	frameBuffer fBuffer = newFrameBuffer(width, height);

	for (int i = 0; i < iBuffer.size; i += 3){
		rasterize_triangle(&fBuffer, &vBuffer.vertices[iBuffer.indices[i]], &vBuffer.vertices[iBuffer.indices[i+1]], &vBuffer.vertices[iBuffer.indices[i+2]]);
	}
	
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			SDL_SetRenderDrawColor(renderer, fBuffer.pixels[i][j].x, fBuffer.pixels[i][j].y, fBuffer.pixels[i][j].y, 255);
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
}

