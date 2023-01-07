#pragma once

#include <wx/wxprec.h>
#include "wxGUI/DisplayCanvas.h"

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class KittyFrame : public wxFrame
{
public:
    KittyFrame();
    KittyFrame(wxWindow* a){KittyFrame();};

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};
