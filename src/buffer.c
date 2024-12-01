
#include <stdlib.h>
#include <stdio.h>

#include "buffer.h"
#include "vector.h"
#include "vertex.h"

VertexBufferObj newVertexBuffer(int size){
	Vertex *vBufferPtr = calloc(size, sizeof(Vertex));
	
	if (vBufferPtr == NULL){
		printf("Failed to create vertex buffer\n");
		exit(EXIT_FAILURE);
	}

	VertexBufferObj vBuffer = {vBufferPtr, size};
	
	return vBuffer;
}

void addVertices(VertexBufferObj *buffer, Vertex *vertexList, int size){
	Vertex *newPtr = realloc(buffer->vertices, (buffer->size + size) * sizeof(Vertex));
	if (newPtr == NULL){
		printf("Error occurred: Vertices not added\n");
		return;
	}

	for (int i = 0; i < size; i++){
		newPtr[buffer->size + i] = vertexList[i];
	}

	buffer->vertices = newPtr;
	buffer->size += size;

	return;
}

IndexBufferObj newIndexBuffer(int size){
	int *iBufferPtr = calloc(size, sizeof(int));
	
	if (iBufferPtr == NULL){
		printf("Failed to create index buffer\n");
		exit(EXIT_FAILURE);
	}

	IndexBufferObj iBuffer = {iBufferPtr, size};
	
	return iBuffer;
}

void addIndices(IndexBufferObj *buffer, int *indexList, int size, int vBufferSize){
	int *newPtr = realloc(buffer->indices, (buffer->size + size) * sizeof(int));
	if (newPtr == NULL){
		printf("Error occurred: Indices not added\n");
		return;
	}
	
	for (int i = 0; i < size; i++){
		newPtr[buffer->size + i] = indexList[i] + vBufferSize;
	}

	buffer->indices = newPtr;
	buffer->size += size;

	return;
}

frameBuffer newFrameBuffer(int width, int height){
	Vec3 **row = calloc(height, sizeof(Vec3*));
	if (row == NULL){
		printf("Failed to create row buffer\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < width; i++){
		Vec3 *col = calloc(width, sizeof(Vec3));
		if (col == NULL){
			printf("Failed to create col buffer\n");
			exit(EXIT_FAILURE);
		}
		row[i] = col;
	}

	frameBuffer f = {row};

	return f;
}

void appendFrameBuffer(frameBuffer *buffer, Vec3 *v, int row, int col){
	buffer->pixels[row][col] = *v;
}
