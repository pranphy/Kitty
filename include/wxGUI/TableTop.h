#pragma once

#include "wx/scrolwin.h"
#include "wx/bitmap.h"
#include "wx/icon.h"

#include "Base/Game.h"

//-----------------------------------------------------------------------------
// TableTop
//-----------------------------------------------------------------------------

class TableTop: public wxScrolledWindow
{
public:
    TableTop( wxWindow *parent, wxWindowID, const wxPoint &pos, const wxSize &size );
    ~TableTop();

    void OnPaint( wxPaintEvent &event );
    void CreateAntiAliasedBitmap();
    void LoadAllImages();
    void ShowCard(unsigned idx, unsigned x=10, unsigned y = 10);
    void ShowState(wxDC&);
    void OnChar(wxKeyEvent&);

    std::vector<wxBitmap> cards; 
    wxBitmap my_horse_png;

    Game kitty;
};

wxBitmap get_bitmap(std::string filepath);
