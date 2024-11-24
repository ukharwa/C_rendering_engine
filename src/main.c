#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vector.h"
#include "pipeline.h"
#include "shapes.h"

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

void show_axes(SDL_Renderer *renderer, int width, int height, float fov, float znear, float zfar, Matrix3 *camera, float length){

	Vec2 x1 = world_space_to_screen_space(width, height, fov, znear, zfar, camera, &(Vec3){-length, 0, 0});
	Vec2 x2 = world_space_to_screen_space(width, height, fov, znear, zfar, camera, &(Vec3){length, 0, 0});

	Vec2 y1 = world_space_to_screen_space(width, height, fov, znear, zfar, camera, &(Vec3){0, -length, 0});
	Vec2 y2 = world_space_to_screen_space(width, height, fov, znear, zfar, camera, &(Vec3){0, length, 0});
	
	Vec2 z1 = world_space_to_screen_space(width, height, fov, znear, zfar, camera, &(Vec3){0, 0, -length});
	Vec2 z2 = world_space_to_screen_space(width, height, fov, znear, zfar, camera, &(Vec3){0, 0, length});

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(renderer, x1.vec.x, x1.vec.y, x2.vec.x, x2.vec.y);
	
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(renderer, y1.vec.x, y1.vec.y, y2.vec.x, y2.vec.y);
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderDrawLine(renderer, z1.vec.x, z1.vec.y, z2.vec.x, z2.vec.y);
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawPoint(renderer, x2.vec.x, x2.vec.y);
	SDL_RenderDrawPoint(renderer, y2.vec.x, y2.vec.y);
	SDL_RenderDrawPoint(renderer, z2.vec.x, z2.vec.y);
}

int main(){
	
	int width = 640;
	int height = 640;
	SDL_Renderer* renderer = initialize_window_and_renderer(width, height, 1);
	
	Matrix3 camera = {new_vec3(5, 3, 7), new_vec3(0, 0, 0), new_vec3(0, 1, 0)};
	float znear = camera.arr[0].vec.z - 1;

	show_axes(renderer, width, height, 1, -0.5, -10, &camera, 5);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	Vec3 v1 = {1, 0, -1};
	Cube c1 = new_cube(1, v1);

	for (int i = 0; i < 12; i++){
		Vec2 p1 = world_space_to_screen_space(width, height, 1, znear, -10, &camera, &c1.mesh[i].vertex[0]);
		Vec2 p2 = world_space_to_screen_space(width, height, 1, znear, -10, &camera, &c1.mesh[i].vertex[1]);
		Vec2 p3 = world_space_to_screen_space(width, height, 1, znear, -10, &camera, &c1.mesh[i].vertex[2]);
		SDL_RenderDrawLine(renderer, p1.vec.x, p1.vec.y, p2.vec.x, p2.vec.y);
		SDL_RenderDrawLine(renderer, p2.vec.x, p2.vec.y, p3.vec.x, p3.vec.y);
		SDL_RenderDrawLine(renderer, p3.vec.x, p3.vec.y, p1.vec.x, p1.vec.y);
	}
	
	Vec3 v2 = {2, 1, -2};
	Cube c2 = new_cube(1, v2);
	
	for (int i = 0; i < 12; i++){
		Vec2 p1 = world_space_to_screen_space(width, height, 1, znear, -10, &camera, &c2.mesh[i].vertex[0]);
		Vec2 p2 = world_space_to_screen_space(width, height, 1, znear, -10, &camera, &c2.mesh[i].vertex[1]);
		Vec2 p3 = world_space_to_screen_space(width, height, 1, znear, -10, &camera, &c2.mesh[i].vertex[2]);
		SDL_RenderDrawLine(renderer, p1.vec.x, p1.vec.y, p2.vec.x, p2.vec.y);
		SDL_RenderDrawLine(renderer, p2.vec.x, p2.vec.y, p3.vec.x, p3.vec.y);
		SDL_RenderDrawLine(renderer, p3.vec.x, p3.vec.y, p1.vec.x, p1.vec.y);
	}
	

	SDL_RenderPresent(renderer);
	SDL_Delay(10000);
	
	return 0;
}


