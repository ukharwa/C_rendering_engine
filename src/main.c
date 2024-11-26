#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vector.h"
#include "pipeline.h"
#include "shapes.h"
#include "buffer.h"

SDL_Renderer * initialize_window_and_renderer(int width, int height, int scale){
	
	SDL_Renderer *renderer = malloc(sizeof(SDL_Renderer *));
	SDL_Window *window;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(width*scale, height*scale, 0, &window, &renderer);
	SDL_RenderSetScale(renderer, scale, scale);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	return renderer;
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

int main(){
	
	int width = 640;
	int height = 640;
	SDL_Renderer* renderer = initialize_window_and_renderer(width, height, 1);
	
	Matrix3 camera = {new_vec3(5, 3, 7), new_vec3(0, 0, 0), new_vec3(0, 1, 0)};
	
	VertexBufferObj vertexBuffer = newVertexBuffer(0);
	IndexBufferObj indexBuffer = newIndexBuffer(0);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	
	Cube c1 = new_cube(1, (Vec3){1, 0, -1});
	Cube c2 = new_cube(1, (Vec3){2, 1, -2});

	addIndices(&indexBuffer, c1.edges, 36, vertexBuffer.size);
	addVertices(&vertexBuffer, c1.vertices, 8);
	
	addIndices(&indexBuffer, c2.edges, 36, vertexBuffer.size);
	addVertices(&vertexBuffer, c2.vertices, 8);
	
	
	draw_scene(renderer, width, height, 1, 0.5, 10, &camera, vertexBuffer, indexBuffer);

	SDL_RenderPresent(renderer);
	SDL_Delay(10000);
	
	return 0;
}


