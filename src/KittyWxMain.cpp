/***************************************************************
 * Name:      KittyWxMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Prakash Gautam (pranphy@gmail.com)
 * Created:   2015-05-03
 * Copyright: Prakash Gautam (http://pranphy.com/)
 * License:
 **************************************************************/

#include "KittyWxMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(KittyWxFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)


//(*IdInit(KittyWxFrame)
const long KittyWxFrame::ID_AboutHelpSubItem = wxNewId();
//*)

BEGIN_EVENT_TABLE(KittyWxFrame,wxFrame)
    //(*EventTable(KittyWxFrame)
    //*)
END_EVENT_TABLE()

KittyWxFrame::KittyWxFrame(wxWindow* parent,wxWindowID id)
{

    //(*Initialize(KittyWxFrame)
    wxStaticBoxSizer* KittySBSizer;
    wxGridBagSizer* GridBagSizer1;

    Create(parent, id, _("Welcome Kitty 15.04.0.2"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(800,450));
    SetMinSize(wxSize(400,300));
    GridBagSizer1 = new wxGridBagSizer(0, 0);
    GridBagSizer1->AddGrowableCol(0);
    GridBagSizer1->AddGrowableCol(1);
    GridBagSizer1->AddGrowableRow(0);
    GridBagSizer1->AddGrowableRow(1);
    KittySBSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Move Cards"));
    GridBagSizer1->Add(KittySBSizer, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(GridBagSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_AboutHelpSubItem, _("About\tCtrl+H"), _("Show details of this application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("Help"));
    SetMenuBar(MenuBar1);
    SetSizer(GridBagSizer1);
    Layout();
    //*)


    KittyCanvas = new DisplayCanvas(this);
    KittySBSizer->Add(KittyCanvas,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL,5);
}

KittyWxFrame::~KittyWxFrame()
{
    //(*Destroy(KittyWxFrame)
    //*)
}

void KittyWxFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void KittyWxFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxT("This is a message ");
    wxMessageBox(msg, _("Welcome to..."));
}



