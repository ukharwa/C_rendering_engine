#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
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

int main(){
	
	int width = 640;
	int height = 640;
	SDL_Renderer* renderer = initialize_window_and_renderer(width, height, 1);

	Matrix3 camera = {new_vec3(5, 3, 7), new_vec3(0, 0, 0), new_vec3(0, 1, 0)};
	
	VertexBufferObj vertexBuffer = newVertexBuffer(0);
	IndexBufferObj indexBuffer = newIndexBuffer(0);

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


