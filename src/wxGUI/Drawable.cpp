#include "Base/Drawable.h"
#include <iostream>

#include <GL/gl.h>
#include <GL/glut.h>

#include "wx/wx.h"

/*
 * This is a simple class built on top of OpenGL that manages
 * drawing images in a higher-level and quicker way.
 */

GLDrawable::GLDrawable() {}

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

void GLDrawable::clear_table()
{
    glClearColor(0.0f,0.5f,0.4f,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void GLDrawable::DrawIt(float angle,float PositionX,float PositionY)
{
    glPushMatrix();
    //glLoadIdentity();
    //glColor3f(1.0,1.0,1.0);
    //cout<<" Printing card "; if(CardTexture){ cout<<" Texture not null "<<endl;} else { cout<<" Texture null "<<endl;}

    glTranslatef(PositionX,PositionY,0);
    glRotatef(angle,0,0,1);
    glBindTexture(GL_TEXTURE_2D,*image.get_texture());

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
    //#assert(image!=NULL);

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

    glBindTexture(GL_TEXTURE_2D, image.getID()[0] );

    glBegin(GL_QUADS);

    glTexCoord2f(xflip? image.tex_coord_x : 0, yflip? 0 : image.tex_coord_y);
    glVertex2f( -hotspotX, -hotspotY );

    glTexCoord2f(xflip? 0 : image.tex_coord_x, yflip? 0 : image.tex_coord_y);
    glVertex2f( image.width-hotspotX, -hotspotY );

    glTexCoord2f(xflip? 0 : image.tex_coord_x, yflip? image.tex_coord_y : 0);
    glVertex2f( image.width-hotspotX, image.height-hotspotY );

    glTexCoord2f(xflip? image.tex_coord_x : 0, yflip? image.tex_coord_y : 0);
    glVertex2f( -hotspotX, image.height-hotspotY );

    glEnd();

}

void GLDrawable::DrawTriangle()
{
    glPushMatrix();

    //glViewport(0, 0, (GLint)GetSize().x, (GLint)GetSize().y);
    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
        glColor3ub((GLubyte)255,(GLubyte)0,(GLubyte)0);
        glVertex3f(0.0f,0.5f,0.0f);
        // Green on the right bottom corner
        glColor3ub((GLubyte)0,(GLubyte)255,(GLubyte)0);
        glVertex3f(0.50f,-0.90f,0.0f);
        // Blue on the left bottom corner
        glColor3ub((GLubyte)0,(GLubyte)0,(GLubyte)255);
        glVertex3f(-0.50f, -0.9000f, -0.0f);
    glEnd();
    glColor3ub((GLubyte)255,(GLubyte)255,(GLubyte)255); //reset white color.
    glPopMatrix();
}

void GLDrawable::DisplaySinglePhoto(float PositionX, float PositionY, GLuint ImageTexture)
{
	glPushMatrix();
    //glLoadIdentity();
    //glColor3f(1.0,1.0,1.0);
    //cout<<" Printing card "; if(CardTexture){ cout<<" Texture not null "<<endl;} else { cout<<" Texture null "<<endl;}

	float PictureWidth = 200;
	float PictureHeight = 300;
	float Factor = 0.002;

    glTranslatef(PositionX,PositionY,0);
    glRotatef(0,0,0,1);
    glBindTexture(GL_TEXTURE_2D,ImageTexture);

    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glTexCoord3f(1.0f,0.0f,0.0f);   glVertex3f(Factor*PictureWidth/2,-Factor*PictureHeight/2,0);
        glTexCoord3f(1.0f,1.0f,0.0f);   glVertex3f(Factor*PictureWidth/2,Factor*PictureHeight/2,0);
        glTexCoord3f(0.0f,1.0f,0.0f);   glVertex3f(-Factor*PictureWidth/2,Factor*PictureHeight/2,0);
        glTexCoord3f(0.0f,0.0f,0.0f);   glVertex3f(-Factor*PictureWidth/2,-Factor*PictureHeight/2,0);
    glEnd();
    glPopMatrix();
}

void GLDrawable::StartDrawing(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

GLuint GLDrawable::load_image_as_texture(std::string FileName)
{
	//wxImage* img = new wxImage(wxString::FromUTF8(FileName.c_str()));

	wxImage* img = new wxImage(wxString::FromUTF8(FileName.c_str()));

	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	GLubyte *bitmapData=img->GetData();
	GLubyte *alphaData=img->GetAlpha();

	int bytesPerPixel = img->HasAlpha() ?  4 : 3;
	int imageWidth = img->GetWidth();
	int imageHeight = img->GetHeight();

	int imageSize = imageWidth * imageHeight * bytesPerPixel;
	GLubyte *imageData=new GLubyte[imageSize];

	int rev_val=imageHeight-1;

	for(int y=0; y<imageHeight; y++)
	{
		for(int x=0; x<imageWidth; x++)
		{
			imageData[(x+y*imageWidth)*bytesPerPixel+0]=
					bitmapData[( x+(rev_val-y)*imageWidth)*3];

			imageData[(x+y*imageWidth)*bytesPerPixel+1]=
					bitmapData[( x+(rev_val-y)*imageWidth)*3 + 1];

			imageData[(x+y*imageWidth)*bytesPerPixel+2]=
					bitmapData[( x+(rev_val-y)*imageWidth)*3 + 2];

			if(bytesPerPixel==4) imageData[(x+y*imageWidth)*bytesPerPixel+3]=
					alphaData[ x+(rev_val-y)*imageWidth ];
		}
	}

	glTexImage2D(GL_TEXTURE_2D,
					0,
					bytesPerPixel,
					imageWidth,
					imageHeight,
					0,
					img->HasAlpha() ?  GL_RGBA : GL_RGB,
					GL_UNSIGNED_BYTE,
					imageData);

	delete[] imageData;
	wxDELETE(img);

	return texture;
}
// backup info
//     glViewport(0, 0, (GLint)GetSize().x, (GLint)GetSize().y);
//
//    for(int i=0; i<9; i++)
//    {
//        glColor3f(1.0,1.0,1.0);
//        float x=0,y=0,angle=0;
//        x=0.9-i*.22;
//        y=0.5;
//        if(i==ActiveCard)
//        {
//            //glColor3f(0.5,0.6,0.7);
//            y+=0.02;
//            angle-=1;
//        }
//        Cards[i].SetPostition(x,y);
//        Cards[i].DrawIt(angle);
//    }
//
//    for(int i=9; i<18; i++)
//    {
//        int cst;
//        float Group=0.0,SaperationIndex=.22;
//        if(BackId)
//            cst=REDBACK;
//        else
//            cst=BLUEBACK;
//        int index = (Flipped ? i:cst);
//        float x=0.0,y=0.0,angle=0.0;
//        x=0.9-(i-9)*SaperationIndex+Group;
//        y=-0.5;
//        Cards[index].SetPostition(x,y);
//        Cards[index].DrawIt(angle);
//    }
//
