#pragma once

#include "vector.h"

typedef struct{
	Vec3 *vertices;
	int size;
} VertexBufferObj ;

typedef struct{
	int *indices;
	int size;
} IndexBufferObj ;

VertexBufferObj newVertexBuffer(int size);
void addVertices(VertexBufferObj *buffer, Vec3 *vertexList, int size);

IndexBufferObj newIndexBuffer(int size);
void addIndices(IndexBufferObj *buffer, int *indexList, int size, int vBufferSize);
