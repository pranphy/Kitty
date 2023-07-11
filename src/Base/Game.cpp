// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-21 11:04
//
//

#include <map>
#include "Base/Game.h"
#include "Base/Deque.h"


Game::Game(int n_player, int n_deque)
    :n_players(n_player),players(n_player),cards(n_deque) // was a bug here
{
    distribute_cards();
    //for(int i = 0; i < n_players; ++i)
    //{
    //    std::vector<Taas> pl_hand = cards.deal(9);
    //    player_hand.push_back(pl_hand);
    //}
}

Game::~Game() {}

void Game::set_control(GameControls ct)
{
}

Khal Game::get_player_hand() {
    return player_hand;
}

void Game::set_player_hand(Khal hand) {
    player_hand = std::move(hand);
}

void Game::set_player_hand(Haat hand,int id ) {
    player_hand[id] = std::move(hand);
}

void Game::distribute_cards()
{
    player_hand.clear();
    for(int i = 0; i < n_players; ++i)
    {
        Haat pl_hand = cards.deal(9);
        player_hand.push_back(pl_hand);
    }
    std::cout<<"Distributed"<<std::endl;
}

void Game::fold_all()
{
    std::cout<<"Folding all"<<std::endl;
    for(auto hand : player_hand)
    {
        cards.mix(hand);
    }
    player_hand.clear();
    // Also may be shuffle??
}

