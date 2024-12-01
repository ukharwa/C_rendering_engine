#pragma once
#include <SDL2/SDL.h>

#include "vector.h"
#include "buffer.h"
#include "vertex.h"

void rasterize_triangle(frameBuffer *buffer, Vertex *p0, Vertex *p1, Vertex *p2);
void draw_scene(SDL_Renderer *renderer ,int width, int height, float fov, float znear, float zfar, Matrix3 *camera, VertexBufferObj vBuffer, IndexBufferObj iBuffer);
