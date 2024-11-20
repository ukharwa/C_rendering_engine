#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdlib.h>

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


int main(){
	
	int width = 320;
	int height = 320;
	SDL_Renderer* renderer = initialize_window_and_renderer(width, height, 2);
	
	Matrix3 camera = {(Vec3){10, 10, 10}, (Vec3){0, 0, 5}, (Vec3){0, 1, 0}};
	Vec3 v1 = {-5, -5, 5};
	Cube c1 = new_cube(10, v1);
	
	for (int i = 0; i < 8; i++){
		Vec2 p1 = world_space_to_screen_space(width, height, 2, 0, 50, &camera, &c1.points[i]);
		Vec2 p2;
		for (int j = i + 1; j < 8; j++){
			p2 = world_space_to_screen_space(width, height, 2, 0, 50, &camera, &c1.points[j]);
			SDL_RenderDrawLine(renderer, p1.vec.x, p1.vec.y, p2.vec.x,  p2.vec.y);
		}
	}
	
	SDL_RenderPresent(renderer);
	SDL_Delay(5000);

	return 0;
}


