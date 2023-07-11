#include "Base/utils.h"
#include "Base/KittyEngine.h"
#include "Utility/Mathematical.h"

void solve_player(Game& kitty_game,int pos)
{
    auto player_hand = kitty_game.get_player_hand();
    if(player_hand.size()-1< pos)
    {
        std::cout<<"Player "<<pos<<" has no cards"<<std::endl;
        return;
    } else {
        std::vector<Taas> hand = kitty_game.get_player_hand().at(pos);
        KittyEngine brain(hand);
        auto solved = brain.modern_solve();
        kitty_game.set_player_hand(solved,pos);
    }
}

void shuffle_player(Game& kitty_game,int pos)
{
    std::vector<Taas> hand = kitty_game.get_player_hand().at(pos);
    shuffle_deq(hand);
    kitty_game.set_player_hand(hand,pos);
}

void mix_back(Game& kitty_game)
{
    kitty_game.fold_all();
}
