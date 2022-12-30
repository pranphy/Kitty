
#include <iostream>
#include <vector>

#include "Base/Taas.h"
#include "Base/Game.h"
#include "Base/KittyEngine.h"

#include "TUI/TUI.h"

void display_all_players(Game kitty_game)
{
    std::cout<<"Displaying all cards"<<std::endl;
    std::vector<std::vector<Taas>> player_hand = kitty_game.get_player_hand();
    int k = 0;
    for(auto hand: player_hand)
    {
        std::cout<<"Player "<<++k<<std::endl;
        for(auto t: hand)
        {
            std::cout<<" "<<t<<std::endl;
        }
    }
}

void solve_all_players(Game kitty_game)
{
    std::cout<<"Displaying all cards"<<std::endl;
    std::vector<std::vector<Taas>> player_hand = kitty_game.get_player_hand();
    int k = 0;
    for(auto hand: player_hand)
    {
        KittyEngine brain(hand);
        auto solved = brain.modern_solve();
        std::cout<<"Player "<<++k<<std::endl;
        for(auto t: solved)
        {
            std::cout<<" "<<t<<std::endl;
        }
    }
}

