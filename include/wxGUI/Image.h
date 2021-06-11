#ifndef _image_
#define _image_

#include <iostream>

#include <GL/gl.h>


class Image
{
    GLuint* ID;
    
public:

	/*
	 * it is preferable to use textures that are a power of two. this loader will automatically
	 * resize texture to be a power of two, filling the remaining areas with black.
	 * width/height are the width of the actual loaded image.
	 * textureWidth/Height are the total width of the texture, including black filling.
	 * tex_coord_x/y are the texture coord parameter you must give OpenGL when rendering
	 * to get only the image, without the black filling.
	 */
    int width, height, textureWidth, textureHeight;
    float tex_coord_x, tex_coord_y;
    
    GLuint* getID();
    Image();
    Image(std::string path);
    ~Image();
    void load(std::string path);
    GLuint* get_texture();
        
};


#endif
