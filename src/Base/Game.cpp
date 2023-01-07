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
    :players(n_player),cards(n_deque) // was a bug here
{
    for(int i = 0; i < n_player; ++i)
    {
        std::vector<Taas> pl_hand = cards.deal(9);
        player_hand.push_back(pl_hand);
    }
}

Game::~Game() {}

void Game::set_control(GameControls ct)
{
}

std::vector<std::vector<Taas>> Game::get_player_hand() {
    return player_hand;
}

void Game::set_player_hand(std::vector<Taas> hand,int id ) {
    player_hand[id] = std::move(hand);
}

void Game::distribute_cards()
{
    std::cout<<"Distributed"<<std::endl;
}

