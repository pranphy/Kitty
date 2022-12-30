#include <iostream>

#include "Base/Game.h"
#include "TUI/TUI.h"

void play_game(void)
{
    Game kitty_game = Game(2,1); // Two player and 1 deque
    kitty_game.distribute_cards();
    display_all_players(kitty_game);
}

int main(int argc, char** argv)
{
    std::cout<<"Hello World"<<std::endl;
    play_game();
    return 0;
}

