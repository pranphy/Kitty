#include <bits/stdc++.h>
#include "Base/KittyEngine.h"
#include "Base/Game.h"
#include "Base/Taas.h"
#include "TUI/TUI.h"
#include "Utility/Mathematical.h"

namespace tui{

void rand_int()
{
    std::vector<int> randoms = rand_int_array(2,15,13);
    std::for_each(randoms.begin(),randoms.end(),[&](int it){std::cout<<it<<std::endl;});
}

void hand_shuffle()
{
    std::vector<Taas> Hand(9);
    std::cout<<"Now shuffling"<<std::endl;
    //shuffle_deq(Hand);
}

void combo_read(){
    std::string combo_file = "./res/Files/Input/Combination.dat";
    std::vector<std::vector<unsigned>> cv = get_combo(combo_file);
    for(auto line : cv)
    {
        for(auto num : line)
            std::cout<<num<< " ";
        std::cout<<std::endl;
    }
}

void game()
{
    //Game juwa = Game();
}

void engine()
{
    KittyEngine KE;
    KE.display();
    std::cout<<" Now solving "<<std::endl;
    KE.modern_solve();
    KE.display();
}

void score()
{
    KittyEngine KE;
    std::vector<Taas> Hand;
    std::vector<int> card_id = {2,3,4,5,6,7,8,9,10};
    for (int i : card_id)
        Hand.push_back(Taas(i));

    //shuffle_deq(Hand);

    std::vector<unsigned> shuf = {0,1,2,3,4,5,6,7,8};
    unsigned score = KE.get_score(Hand,shuf);
    std::cout<<score<<" is the score "<<std::endl;
}

void test_kitty_engine()
{
    //combo_read();
    //rand_int();
    std::cout<<" Displayed rand int "<<std::endl;
    engine();
    //score();
}

void make_deque()
{
    Game kitty_game = Game(2,1);
    display_all_players(kitty_game.get_player_hand());
    solve_all_players(kitty_game);
}


}

int main()
{
    std::cout<<"Hello World"<<std::endl;
    tui::make_deque();
    return 0;
}
