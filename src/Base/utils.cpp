#include "Base/utils.h"
#include "Base/KittyEngine.h"
#include "Utility/Mathematical.h"

void solve_player(Game& kitty_game,int pos)
{
    std::vector<Taas> hand = kitty_game.get_player_hand().at(pos);
    KittyEngine brain(hand);
    auto solved = brain.modern_solve();
    kitty_game.set_player_hand(solved,pos);
}

void shuffle_player(Game& kitty_game,int pos)
{
    std::cout<<"Solving player "<<pos<<std::endl;
    std::vector<Taas> hand = kitty_game.get_player_hand().at(pos);
    shuffle_deq(hand);
    kitty_game.set_player_hand(hand,pos);
}
