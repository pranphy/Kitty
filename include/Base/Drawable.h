#pragma once

#include <string>
#include <wx/string.h>
#include <wx/image.h>

#include "wxGUI/Image.h"

class GLDrawable
{
private:
    float factor, factorcard,CARD_WIDTH, CARD_HEIGHT;
public:
    int x,y, angle, hotspotX, hotspotY;
    float xscale, yscale;
    Image image;
    bool xflip, yflip;
    
    GLDrawable();
    GLDrawable(Image);
    void setFlip(bool x, bool y);
    void move(int x, int y);
    void setHotspot(int x, int y);
    void scale(float x, float y);
    void scale(float k);
    void setImage(Image image);
    void render();
    void rotate(int angle);
    
    void DrawIt(float,float,float);
    void DrawTriangle();
    void DisplaySinglePhoto(float PositionX, float PositionY, GLuint ImageTexture); 
    void StartDrawing(void);
    void clear_table();
    GLuint load_image_as_texture(std::string);
};

