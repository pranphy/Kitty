#include "wxGUI/DisplayCanvas.h"
#include "OGL/utils.h"

const long DisplayCanvas::ID_DisplayCanvas = wxNewId();

DisplayCanvas::DisplayCanvas(wxWindow*Parent,wxGLAttributes& dispAttrs):
    wxGLCanvas(Parent,dispAttrs, ID_DisplayCanvas,  wxDefaultPosition, wxSize(500,500), 0, "GLCanvas")
{
    int argc = 1;
    char* argv[1] = { wxString((wxTheApp->argv)[0]).char_str() };
    glutInit(&argc,argv);
    MyContext = new wxGLContext(this);

    Bind(wxEVT_PAINT, &DisplayCanvas::OnPaint,this);         /* this did not work      */
    Bind(wxEVT_KEY_DOWN, &DisplayCanvas::OnKeyPress,this); /* both of these actually */

    Initialize();
}

void DisplayCanvas::Initialize()
{
	SetCurrent(*MyContext);

    std::string imagepath = "./res/Files/AllCards/Ascending/C22.png";
    exampletex = load_image_file(imagepath);
    std::cout<<imagepath<<" successfully read "<<std::endl;
}


void DisplayCanvas::OnPaint(wxPaintEvent& WXUNUSED(event))
{
    Render();
    SwapBuffers();
}

void DisplayCanvas::OnKeyPress(wxKeyEvent& event)
{
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

	this->Refresh();
}


void DisplayCanvas::Render()
{
    glClearColor(1.0,1.0,1.0,1.0);
    DrawTriangle();
    display_image(0.0,0.0,exampletex);
    display_image(0.2,0.0,exampletex);
    this->Refresh(); // Has no effect
}


void DisplayCanvas::ChangeSize(int w, int h)
{
    std::cout<<"Size Changed to "<<w<<" and h= "<<h<<std::endl;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 0.2, 200.0);
}


void DisplayCanvas::TimerFunc(int value)
{
    glutPostRedisplay();
    value++;
    //glutTimerFunc(10, TimerFunc, 0);
}
