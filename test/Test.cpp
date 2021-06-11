// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-09 22:59
//

#include <bits/stdc++.h>
#include "Base/KittyEngine.h"
#include "Base/Game.h"
#include "Base/Taas.h"
#include "Utility/Mathematical.h"

void rand_int()
{
    std::vector<int> randoms = rand_int_array(2,15,13);
    std::for_each(randoms.begin(),randoms.end(),[&](int it){std::cout<<it<<std::endl;});
}

void hand_shuffle()
{
    std::vector<Taas> Hand(9);
    std::cout<<"Now shuffling"<<std::endl;
    shuffle_vec(Hand);
    
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

    shuffle_vec(Hand);

    std::vector<unsigned> shuf = {0,1,2,3,4,5,6,7,8};
    unsigned score = KE.get_score(Hand,shuf);
    std::cout<<score<<" is teh score "<<std::endl;
}

void test_kitty_engine()
{
    //combo_read();
    //rand_int();
    std::cout<<" Displayed rand int "<<std::endl;
    engine();
    //score();
}


int main()
{
    std::cout<<"Hello World"<<std::endl;
    test_kitty_engine();
    return 0;
}

