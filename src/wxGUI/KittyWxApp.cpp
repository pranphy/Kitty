/***************************************************************
 * Name:      KittyWxApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Prakash Gautam (pranphy@gmail.com)
 * Created:   2015-05-03
 * Copyright: Prakash Gautam (http://pranphy.com/)
 * License:
 **************************************************************/

#include "wxGUI/KittyWxApp.h"
#include "wxGUI/KittyFrame.h"

IMPLEMENT_APP(KittyWxApp);

bool KittyWxApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        KittyFrame* Frame = new KittyFrame();
        Frame->Show();
        SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
