#include <format>

#include "wx/wx.h"
#include "wx/image.h"

#include "wxGUI/TableTop.h"


TableTop::TableTop( wxWindow *parent, wxWindowID id,
                    const wxPoint &pos, const wxSize &size )
    : wxScrolledWindow( parent, id, pos, size, wxSUNKEN_BORDER )
{

    Bind(wxEVT_PAINT, &TableTop::OnPaint,this);
    Bind(wxEVT_KEY_UP, &TableTop::OnChar,this);
    kitty = Game::Instance();

    LoadAllImages();
    my_horse_png = cards.at(11);


}

TableTop::~TableTop()
{
    //delete kitty;
}


void TableTop::OnPaint( wxPaintEvent &WXUNUSED(event) )
{
    wxPaintDC dc( this );
    PrepareDC( dc );
    ShowState(dc);
}

void TableTop::ShowState(wxDC& dc)
{
    if(true){
        auto players = kitty.get_players();
        for(size_t pn = 0; pn < players.size(); ++pn){
            auto player = players.at(pn);
            auto hand = player.get_hand();
            dc.DrawText( std::format(" Player {}",player.get_name() ),300, 170 + 400*pn);
            //std::cout<<"Here "<<std::endl;
            for(size_t cn = 0; cn < hand.size(); ++cn){
                int x = 80+cn*104;
                auto id = hand.at(cn).get_id();
                int y = 400*pn + 200;
                //std::cout<<" (x,y) = ("<<x<<","<<y<<"): "<<id<<std::endl;
                if(player.shown) {
                    dc.DrawBitmap(cards.at(id),x,y);
                } else {
                    dc.DrawBitmap(cards.at(52),x,y);
                }

            }
        }
        
    } else {
        //std::cout<<" Just hanging around"<<std::endl;
    }

}

void TableTop::LoadAllImages(){
    std::string basepath = "./res/Files/AllCards/Ascending";
    for(int i = 0; i < 52; ++i)
    {
        std::string imagepath = std::format("{}/C{:02d}.png",basepath,i+1);
        //std::cout<<"Loading : "<<imagepath;
        cards.push_back(get_bitmap(imagepath));
        //std::cout<<" Done"<<std::endl;
    }
    std::cout<<" Done"<<std::endl;
    std::string redback = std::format("{}/../Back/RedBack.png",basepath);
    cards.push_back(get_bitmap(redback));
}

void TableTop::CreateAntiAliasedBitmap()
{
    // Nothing doing
}

void TableTop::OnChar(wxKeyEvent& event)
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
    else if(Key == 's' or Key == 'S')
	{
        kitty.shuffle_player(0);
	}

    else if(Key == 'a' or Key == 'A')
	{
        Player bharat("Bharat","Bhurtel");
        int id = kitty.add_player(bharat);
        kitty.deal_player(id);
        kitty.shuffle_player(id);
	}

    else if(Key == 'd' or Key == 'D')
	{
        kitty.distribute_cards();
	}
    else if(Key == 'f' or Key == 'F')
	{
        control = GameControls::FLIP;
        kitty.flip_all();
	}
	else if(Key == 'u' or Key == 'U')
	{
        control = GameControls::SOLVE;
        auto engine = KittyEngine::Instance();
        kitty.solve_player(0,engine);
        kitty.solve_player(1,engine);
	}
	else if(Key == 'r' or Key == 'R')
	{
        kitty.fold_all();
        //kitty.distribute_cards();
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
    kitty.set_control(control);

	this->Refresh();
}

wxBitmap get_bitmap(std::string filepath){
    wxImage image;
    if(! image.LoadFile(filepath))
        std::cout<<"Cant load:"<<filepath<<std::endl;

    wxBitmap bitmap(image);
    image.Destroy();
    return bitmap;
}
