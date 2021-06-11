#ifndef _image_loader
#define _image_loader

#include <GL/gl.h>
#include "wx/wx.h"
	
GLuint* loadImage(std::string path, int* imageWidth, int* imageHeight, int* textureWidth, int* textureHeight);

#endif
