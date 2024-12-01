#pragma once

#include "vector.h"
#include "vertex.h"

typedef struct{
	Vertex *vertices;
	int size;
} VertexBufferObj ;

typedef struct{
	int *indices;
	int size;
} IndexBufferObj ;

typedef struct{
	Vec3 **pixels;
} frameBuffer;

VertexBufferObj newVertexBuffer(int size);
void addVertices(VertexBufferObj *buffer, Vertex *vertexList, int size);

IndexBufferObj newIndexBuffer(int size);
void addIndices(IndexBufferObj *buffer, int *indexList, int size, int vBufferSize);

frameBuffer newFrameBuffer(int width, int height);
void appendFrameBuffer(frameBuffer *buffer, Vec3 *v, int row, int col);
