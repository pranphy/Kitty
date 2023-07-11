#include <iostream>
#include "wxGUI/KittyWxApp.h"
#include "wxGUI/KittyFrame.h"

typedef KittyFrame MainFrame;

IMPLEMENT_APP(KittyWxApp);

namespace gui {

void make_frame()
{
    MainFrame main_frame = MainFrame(0);
    main_frame.Show();
}
}

bool KittyWxApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        MainFrame* Frame = new MainFrame();
        Frame->Show();
        SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
