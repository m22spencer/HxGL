#ifndef GLES11_H
#define GLES11_H

#include "IGL.h"
#include <cstring> //So memcpy works on gcc 4.3
#include <iostream>

#ifndef NULL
#define NULL 0
#endif

class GLES11:public IGL
{
public:
    //Context3D Style binds
	void clear (float red, float green, float blue, float alpha, float depth, unsigned int stencil, unsigned int mask);
	void configureBackBuffer (int width, int height, int antiAlias, bool enableDepthAndStencil);
	void createCubeTexture (int size, const char *format, bool optimizeForRenderToTexture);
	unsigned int createVertexBuffer (unsigned int size);
	unsigned int createIndexBuffer (unsigned int size);
	//void dispose (); DO NOT IMPLEMENT
	//void drawToBitmapData (); DO NOT IMPLEMENT
	void drawTriangles(unsigned int iboID, int firstIndex, int numTriangles);
	//void present (); DO NOT IMPLEMENT
	void setCulling(const char *triangleFaceToCull);
	void setDepthTest (bool depthMask, const char *passCompareMode);
	void setVertexBufferAt (int index, unsigned int vboID, int bufferOffset, const char *format, const char *hint);

    //Shader stuff
	unsigned int createProgram(){ return 0; };
	void uploadProgram (unsigned int program, const char *vertexProgram, const char *fragmentProgram){};
	void setProgram (unsigned int program){};	
	void disposeProgram (unsigned int program) {};

	//Buffer3D Style binds
    void uploadFromByteArrayVertex(unsigned int vboID, const void *data, int byteArrayOffset, int startOffset, int totalBytes);
	void uploadFromByteArrayIndex(unsigned int iboID, const void *data, int byteArrayOffset, int startOffset, int totalBytes);	
};

#endif
