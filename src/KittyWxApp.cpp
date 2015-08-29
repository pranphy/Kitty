/***************************************************************
 * Name:      KittyWxApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Prakash Gautam (pranphy@gmail.com)
 * Created:   2015-05-03
 * Copyright: Prakash Gautam (http://pranphy.com/)
 * License:
 **************************************************************/

#include "KittyWxApp.h"
#include "DisplayCanvas.h"
//(*AppHeaders
#include "KittyWxMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(KittyWxApp);

bool KittyWxApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        KittyWxFrame* Frame = new KittyWxFrame(0);
        //new DisplayCanvas(Frame);
        Frame->Show();
        SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
