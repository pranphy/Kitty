/***************************************************************
 * Name:      KittyWxMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Prakash Gautam (pranphy@gmail.com)
 * Created:   2015-05-03
 * Copyright: Prakash Gautam (http://pranphy.com/)
 * License:
 **************************************************************/

#include "wxGUI/KittyWxMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(KittyWxFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)


//(*IdInit(KittyWxFrame)
const long KittyWxFrame::ID_KittyPanel = wxNewId();
//*)

BEGIN_EVENT_TABLE(KittyWxFrame,wxFrame)
    //(*EventTable(KittyWxFrame)
    //*)
END_EVENT_TABLE()

KittyWxFrame::KittyWxFrame(wxWindow* parent,wxWindowID id)
{

    //(*Initialize(KittyWxFrame)
    wxGridBagSizer* OnlyGBS;
    wxStaticBoxSizer* KittySBSizer;

    Create(parent, id, _("Welcome Kitty 15.04.0.2"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(400,439));
    SetMinSize(wxSize(400,300));
    OnlyAUI = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
    KittyPanel = new wxPanel(this, ID_KittyPanel, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_KittyPanel"));
    OnlyGBS = new wxGridBagSizer(0, 0);
    KittySBSizer = new wxStaticBoxSizer(wxHORIZONTAL, KittyPanel, _("Move Cards"));
    OnlyGBS->Add(KittySBSizer, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxEXPAND, 5);
    OnlyGBS->AddGrowableCol(0);
    OnlyGBS->AddGrowableCol(1);
    OnlyGBS->AddGrowableRow(0);
    OnlyGBS->AddGrowableRow(1);
    KittyPanel->SetSizer(OnlyGBS);
    OnlyGBS->Fit(KittyPanel);
    OnlyGBS->SetSizeHints(KittyPanel);
    OnlyAUI->AddPane(KittyPanel, wxAuiPaneInfo().Name(_T("PaneName")).CenterPane().Caption(_("Kitty Play Area")).CaptionVisible().Row(1));
    OnlyAUI->Update();
    //*)
    wxGLAttributes dispAttrs;
    dispAttrs.PlatformDefaults().DoubleBuffer().EndList();
    KittyCanvas = new DisplayCanvas(KittyPanel,dispAttrs);



    KittySBSizer->Add(KittyCanvas,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL,5);
    KittyCanvas->Show();
    //KittyCanvas->SetCurrent();
    KittyCanvas->Initialize();
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
