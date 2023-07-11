#include "wxGUI/DisplayCanvas.h"
#include "OGL/utils.h"
#include "Base/utils.h"

const long DisplayCanvas::ID_DisplayCanvas = wxNewId();

DisplayCanvas::DisplayCanvas(wxWindow*Parent,wxGLAttributes& dispAttrs):
    wxGLCanvas(Parent,dispAttrs, ID_DisplayCanvas,  wxDefaultPosition, wxSize(1200,800), 0, "GLCanvas")
{
    int argc = 1;
    char* argv[1] = { wxString((wxTheApp->argv)[0]).char_str() };
    glutInit(&argc,argv);
    MyContext = new wxGLContext(this);

    Bind(wxEVT_PAINT, &DisplayCanvas::OnPaint,this);
    Bind(wxEVT_KEY_DOWN, &DisplayCanvas::OnKeyPress,this);
    Bind(wxEVT_SIZE, &DisplayCanvas::ChangeSize,this);

    Initialize();
}

void DisplayCanvas::Initialize()
{
	SetCurrent(*MyContext);

    std::string imagepath = "./res/Files/AllCards/Ascending/C22.png";
    exampletex = load_image_file(imagepath);
    std::cout<<imagepath<<" successfully read "<<std::endl;
    all_textures = load_all_images();
}


void DisplayCanvas::OnPaint(wxPaintEvent& WXUNUSED(event))
{
    SetCurrent(*MyContext);
    Render();
}


void DisplayCanvas::Render()
{
    glClearColor(0.2,0.3,1.0,0.2);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_full_box();
    display_player_cards(KittyGame,all_textures,0,-0.5,-0.31);
    display_player_cards(KittyGame,all_textures,1,-0.5,0.31);
    glFlush();
    SwapBuffers();
    Refresh();
}


void DisplayCanvas::ChangeSize( wxSizeEvent& evt)
{
    float w = evt.GetSize().GetX();
    float h = evt.GetSize().GetY();
    //std::cout<<"Size Changed to "<<w<<" and h= "<<h<<std::endl;
    Render();
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
        shuffle_player(KittyGame,1);
	}
	else if(Key == 'u' or Key == 'U')
	{
        control = GameControls::SOLVE;
        solve_player(KittyGame,0);
        solve_player(KittyGame,1);
	}
	else if(Key == 'r' or Key == 'R')
	{
        control = GameControls::FLIP;
        KittyGame.fold_all();
        //KittyGame.distribute_cards();
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

