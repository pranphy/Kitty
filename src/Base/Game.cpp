// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-21 11:04

#include <map>
#include "Base/Game.h"
#include "Base/Deque.h"
#include "Utility/Mathematical.h"


Game::Game(int n_player, int n_deque)
    :n_players(n_player),players(n_player),cards(n_deque) // was a bug here
{
    for (auto& player : players) player.set_hand( cards.deal(9) );
    if(n_player > 0) created = true; else created = false;
}

Game::Game(std::vector<Player> players, int n_deque): players(players),cards(n_deque) 
{
    for (auto& player : players) player.set_hand( cards.deal(9) );
    created = true;
};

Game::~Game() {}

Game& Game::Instance(){
    static Game game;
    return game;
}

int Game::add_player(Player player){
    players.push_back(player);
    return players.size() - 1;
}

void Game::deal_player(int id, int n_card){
    players.at(id).set_hand(cards.deal(9));
}


void Game::set_control(GameControls ct)
{
}

void Game::solve_player(int pos, KittyEngine& brain){
    if (! ((size_t)pos > players.size()) )
    {
        Player& player = players[pos];
        auto solved = brain.modern_solve(player.get_hand());
        player.set_hand(solved);
    }

}

void Game::distribute_cards(int i){
    fold_all();
    if (i >= 0 ){
        if(size_t(i) < players.size()) {
            auto& player = players[i];
            player.set_hand(cards.deal(9));
        }
    } else {
        for(auto& player: players){
            player.set_hand( cards.deal(9) );
        }
    }
}





void Game::shuffle_player(int pos){
    if (! ((size_t)pos > players.size()) )  players[pos].shuffle();
}

void Game::flip_all(){
    for(auto& player: players) player.shown ^= true;
}

void Game::flip_player(int pos){
    if (! ((size_t)pos > players.size()) ) players[pos].shown ^= true;
}

void Game::fold_all()
{
    for(auto& player: players)
    {
        cards.mix(player.get_hand());
        player.clear_hand();
    }
    // Also may be shuffle??
}

