#include "Base/utils.h"
#include "Base/KittyEngine.h"
#include "Utility/Mathematical.h"

void solve_player(Game& kitty_game,int pos)
{
    auto brain = KittyEngine::Instance(); 
    kitty_game.solve_player(pos,brain);
}

void shuffle_player(Game& kitty_game,int pos)
{
    kitty_game.shuffle_player(pos);
}

void mix_back(Game& kitty_game)
{
    kitty_game.fold_all();
}
