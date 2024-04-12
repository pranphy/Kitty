// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-21 11:03
//

#pragma once

#include <iostream>
#include <map>

#include "Base/Player.h"
#include "Base/Deque.h"
#include "Base/KittyEngine.h"


enum GameControls
{
    ENTER,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    FLIP,
    SOLVE,
    CLEAR
};

class Game
{
private:
    int n_players;

    std::vector<Player> players;
    Deque cards;


public:
    Game(int n_player=0, int n_deque=1);
    Game(std::vector<Player>, int n_deque=1);
    ~Game();

    bool created;
    static Game& Instance();

    int add_player(Player);

    void deal_player(int,int=9);
    void distribute_cards(int i=-1);
    void fold_all();
    void solve_player(int,KittyEngine&);
    void shuffle_player(int);
    void flip_player(int);
    void flip_all();
    void set_control(GameControls);
    std::vector<Player> get_players(){ return players; }
};

