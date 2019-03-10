#include "Base/Drawable.h"
#include <iostream>

#include <GL/gl.h>

#include "wx/wx.h"

/*
 * This is a simple class built on top of OpenGL that manages 
 * drawing images in a higher-level and quicker way.
 */

GLDrawable::GLDrawable(Image image_arg)
{

    x=0;
    y=0;
    hotspotX=0;
    hotspotY=0;
    angle=0;
    
    xscale=1;
    yscale=1;

    xflip=false;
    yflip=false;
    
    setImage(image_arg);
    //else image=NULL;
}

void GLDrawable::setFlip(bool x, bool y)
{
    xflip=x;
    yflip=y;
}

void GLDrawable::setHotspot(int x, int y)
{
    hotspotX=x;
    hotspotY=y;
}

void GLDrawable::move(int x, int y)
{
    GLDrawable::x=x;
    GLDrawable::y=y;
}

void GLDrawable::scale(float x, float y)
{
    GLDrawable::xscale=x;
    GLDrawable::yscale=y;
}

void GLDrawable::scale(float k)
{
    GLDrawable::xscale=k;
    GLDrawable::yscale=k;
}

void GLDrawable::setImage(Image image)
{
    GLDrawable::image=image;
}

void GLDrawable::rotate(int angle)
{
    GLDrawable::angle=angle;
}

void GLDrawable::DrawIt(float angle)
{
    glPushMatrix();
    //glLoadIdentity();
    //glColor3f(1.0,1.0,1.0);
    //cout<<" Printing card "; if(CardTexture){ cout<<" Texture not null "<<endl;} else { cout<<" Texture null "<<endl;}

    glTranslatef(PositionX,PositionY,0);
    glRotatef(angle,0,0,1);
    glBindTexture(GL_TEXTURE_2D,CardTexture);

    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glTexCoord3f(1.0f,0.0f,0.0f);   glVertex3f(factor*factorcard*CARD_WIDTH/2,-factor*factorcard*CARD_HEIGHT/2,0);
        glTexCoord3f(1.0f,1.0f,0.0f);   glVertex3f(factor*factorcard*CARD_WIDTH/2,factor*factorcard*CARD_HEIGHT/2,0);
        glTexCoord3f(0.0f,1.0f,0.0f);   glVertex3f(-factor*factorcard*CARD_WIDTH/2,factor*factorcard*CARD_HEIGHT/2,0);
        glTexCoord3f(0.0f,0.0f,0.0f);   glVertex3f(-factor*factorcard*CARD_WIDTH/2,-factor*factorcard*CARD_HEIGHT/2,0);
    glEnd();
    glPopMatrix();
}

void GLDrawable::render()
{
    assert(image!=NULL);
    
    glLoadIdentity();

    glTranslatef(x,y,0);
    
    if(xscale!=1 || yscale!=1)
	{
        glScalef(xscale, yscale, 1);
    }
    
    if(angle!=0)
	{
        glRotatef(angle, 0,0,1);   
    }
    
    glBindTexture(GL_TEXTURE_2D, image->getID()[0] );
    
    glBegin(GL_QUADS);
    
    glTexCoord2f(xflip? image->tex_coord_x : 0, yflip? 0 : image->tex_coord_y);
    glVertex2f( -hotspotX, -hotspotY );
    
    glTexCoord2f(xflip? 0 : image->tex_coord_x, yflip? 0 : image->tex_coord_y);
    glVertex2f( image->width-hotspotX, -hotspotY );
    
    glTexCoord2f(xflip? 0 : image->tex_coord_x, yflip? image->tex_coord_y : 0);
    glVertex2f( image->width-hotspotX, image->height-hotspotY );
    
    glTexCoord2f(xflip? image->tex_coord_x : 0, yflip? image->tex_coord_y : 0);
    glVertex2f( -hotspotX, image->height-hotspotY );
    
    glEnd();
    
}

