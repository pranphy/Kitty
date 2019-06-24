#include "wxGUI/DisplayCanvas.h"

const long DisplayCanvas::ID_DisplayCanvas = wxNewId();

BEGIN_EVENT_TABLE(DisplayCanvas,wxGLCanvas)
    EVT_PAINT(DisplayCanvas::OnPaint)
    EVT_KEY_DOWN(DisplayCanvas::OnKeyPress)
END_EVENT_TABLE()


DisplayCanvas::DisplayCanvas(wxWindow*Parent,wxGLAttributes& dispAttrs):
    wxGLCanvas(Parent,dispAttrs, ID_DisplayCanvas,  wxDefaultPosition, wxSize(150,100), 0, wxT("GLCanvas"))
{
    int argc = 1;
    char* argv[1] = { wxString((wxTheApp->argv)[0]).char_str() };
    glutInit(&argc,argv);
    MyContext = new wxGLContext(this);
}

void DisplayCanvas::Initialize()
{
	//LoadAllImages();
	//ShuffleCards();
}


void DisplayCanvas::OnPaint(wxPaintEvent& WXUNUSED(event))
{
	SetCurrent(*MyContext);
	static bool OneTime = false;
	if(OneTime == false)
	{
		//LoadAllImages();
		//ShuffleCards();
		OneTime = true;
	}
}

void DisplayCanvas::OnKeyPress(wxKeyEvent& event)
{
    //wxMessageBox(wxT(" You pressed a key "),wxT("Bravoo "));
    GameControls control;

    int Key = event.GetUnicodeKey();
    if(Key == 13)
    {
        control = GameControls::ENTER;
    }
    else if (Key >= '1' and Key <= '9')
    {
        control = GameControls::ONE;
    }
    else if(Key == 'f' or Key == 'F')
	{
        control = GameControls::FLIP;
	}
	else if(Key == 'u' or Key == 'U')
	{
        control = GameControls::SOLVE;
	}
	else if(Key == 'r' or Key == 'R')
	{
        control = GameControls::FLIP;
	}
    switch(event.GetKeyCode())
    {
    case WXK_LEFT:
        control = GameControls::LEFT;
        break;
    case WXK_RIGHT:
        control = GameControls::RIGHT;

        break;
    case WXK_UP:
        control = GameControls::UP;
        break;
    case WXK_DOWN:
        control = GameControls::DOWN;
    default:
        break;
    }
    KittyGame.set_control(control);

    wxPaintEvent Dummy = wxPaintEvent();
    OnPaint(Dummy);
}


void DisplayCanvas::Render()
{
    //Probably start game here
}


void DisplayCanvas::ChangeSize(int w, int h)
{
    // Tell Game that size changed 
    //
}


void DisplayCanvas::TimerFunc(int value)
{
    glutPostRedisplay();
    value++;
    //glutTimerFunc(10, TimerFunc, 0);
}


void DisplayCanvas::DrawCube()
{
	//
}

GLuint DisplayCanvas::LoadImageFile(string FileName)
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
