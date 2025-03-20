#include <iostream>

#include "Base/Game.h"
#include "Base/KittyEngine.h"
#include "TUI/TUI.h"

void play_game(void)
{
    Game kitty_game = Game(2,1); // Two player and 1 deque
    kitty_game.distribute_cards();
    display_all_players(kitty_game.get_players());
    KittyEngine brain = KittyEngine::Instance();
    auto solved = brain.modern_solve(kitty_game.get_players()[0].get_hand());
    for(auto& card: solved)
    {
        std::cout<<card<<std::endl;
    }
    
}

int main(int argc, char** argv)
{
    std::cout<<"Hello World"<<std::endl;
    play_game();
    return 0;
}

