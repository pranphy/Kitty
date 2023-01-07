#include <format>

#include "wx/image.h"

#include "OGL/utils.h"

GLuint load_image_file(std::string FileName)
{
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

void DrawTriangle()
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

void display_image(float PositionX, float PositionY, GLuint image_texture)
{
	glPushMatrix();
    //glLoadIdentity();
    //glColor3f(1.0,1.0,1.0);
    //cout<<" Printing card "; if(CardTexture){ cout<<" Texture not null "<<endl;} else { cout<<" Texture null "<<endl;}

    float aspect_ratio = 1.0/2.0;
    float height = 0.4, width = height*aspect_ratio ;

    glTranslatef(PositionX,PositionY,0);
    glRotatef(0,0,0,1);
    glBindTexture(GL_TEXTURE_2D,image_texture);

    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glTexCoord3f(1.0f,0.0f,0.0f);   glVertex3f(width/2,-height/2,0);
        glTexCoord3f(1.0f,1.0f,0.0f);   glVertex3f(width/2,height/2,0);
        glTexCoord3f(0.0f,1.0f,0.0f);   glVertex3f(-width/2,height/2,0);
        glTexCoord3f(0.0f,0.0f,0.0f);   glVertex3f(-width/2,-height/2,0);
    glEnd();
    glPopMatrix();
}


GLuint display_image(float PositionX, float PositionY, std::string imagepath)
{
    GLuint texture = load_image_file(imagepath);
    display_image(PositionX,PositionY,texture);
    return texture;
}

std::vector<GLuint> load_all_images()
{
    std::vector<GLuint> all_textures;
    std::string basepath = "./res/Files/AllCards/Ascending";
    for(int i = 0; i < 52; ++i)
    {
        std::string imagepath = std::format("{}/C{:02d}.png",basepath,i+1);
        std::cout<<"Loading : "<<imagepath;
        all_textures.push_back(load_image_file(imagepath));
        std::cout<<" Done"<<std::endl;
    }
    std::string redback = std::format("{}/../Back/RedBack.png",basepath);
    all_textures.push_back(load_image_file(redback));
    return all_textures;
}

void display_player_cards(Game game,std::vector<GLuint> textures,int playerid,float x, float y)
{
    auto player_hands = game.get_player_hand();
    auto fp_cards = player_hands.at(playerid);
    int cn = 0;
    for(auto card: fp_cards)
    {
        std::cout<<"Card:"<<card<<std::endl;
        display_image(x+0.15*cn++,y,textures.at(card.get_id()));
    }
}



void StartDrawing(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

