
#include <stdlib.h>
#include <stdio.h>

#include "buffer.h"
#include "vector.h"

VertexBufferObj newVertexBuffer(int size){
	Vec3 *vBufferPtr = calloc(size, sizeof(Vec3));
	
	if (vBufferPtr == NULL){
		printf("Failed to create vertex buffer\n");
		exit(EXIT_FAILURE);
	}

	VertexBufferObj vBuffer = {vBufferPtr, size};
	
	return vBuffer;
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

void addVertices(VertexBufferObj *buffer, Vec3 *vertexList, int size){
	Vec3 *newPtr = realloc(buffer->vertices, (buffer->size + size) * sizeof(Vec3));
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
