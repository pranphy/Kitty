
#include <iostream>
#include <vector>

#include "Base/Taas.h"
#include "Base/Game.h"
#include "Base/KittyEngine.h"

#include "TUI/TUI.h"

void display_all_players(std::vector<Player> players)
{
    std::cout<<"Displaying all cards"<<std::endl;
    //std::vector<std::vector<Taas>> player_hand = kitty_game.get_player_hand();
    int k = 0;
    for(auto player: players)
    {
        std::cout<<"Player "<<++k<<std::endl;
        for(auto t: player.get_hand())
        {
            std::cout<<" "<<t<<std::endl;
        }
    }
}

void solve_all_players(Game& kitty_game)
{
    auto players = kitty_game.get_players();
    for(auto& player : players)
    {
        auto brain = KittyEngine::Instance();
        auto hand = player.get_hand();
        auto solved = brain.modern_solve(hand);
        player.set_hand(solved);
        //solved_hand.push_back(solved);
    }
    display_all_players(players);
}

