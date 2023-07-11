#include "wxGUI/KittyFrame.h"

enum
{
    ID_Hello = 1
};

wxMenuBar* create_menubar()
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item lalala");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    return menuBar;
}

DisplayCanvas* get_canvas(wxWindow* parent)
{
    wxGLAttributes dispAttrs;
    dispAttrs.PlatformDefaults().DoubleBuffer().EndList();
    return new DisplayCanvas(parent,dispAttrs);

}

KittyFrame::KittyFrame()
    : wxFrame(nullptr, wxID_ANY, "Hello World")
{

    SetMenuBar( create_menubar());
    wxPanel* main_panel = new wxPanel(this,wxID_ANY);
    //wxStaticBoxSizer *topsizer = new wxStaticBoxSizer( wxVERTICAL,this,"Test Bhaiho" );
    wxBoxSizer *topsizer = new wxBoxSizer(wxVERTICAL);

    topsizer->Add(
        get_canvas(main_panel),
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        10 );         // set border width to 10
    wxBoxSizer *two_btn = new wxBoxSizer(wxHORIZONTAL);
    two_btn->Add(new wxButton(main_panel,wxID_ANY,"OK"),0,wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    two_btn->Add(new wxButton(main_panel,wxID_ANY,"Cancel"),0,wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    //two_btn->Add( new wxButton(main_panel,wxID_ANY,"OKED"), wxSizerFlags().Border(wxALL,2));

    //two_btn->Add( new wxButton(main_panel,wxID_ANY,"Cancel"), wxSizerFlags().Border(wxALL,2));

    topsizer->Add(two_btn,wxSizerFlags().Center());
    main_panel->SetSizer(topsizer);
    topsizer->SetSizeHints(this);

    //SetSizerAndFit(topsizer); // use the sizer for layout and size window accordingly and prevent it from being resized to smaller size
    //main_panel->SetSizer(topsizer);


    //CreateStatusBar();
    //SetStatusText("Welcome to Kitty!");

    Bind(wxEVT_MENU, &KittyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &KittyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &KittyFrame::OnExit, this, wxID_EXIT);
}

void KittyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void KittyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void KittyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}
