#ifndef _image_loader
#define _image_loader

#include <string>
#include <GL/gl.h>
	
GLuint* loadImage(std::string path, int* imageWidth, int* imageHeight, int* textureWidth, int* textureHeight);

#endif
