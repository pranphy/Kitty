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
    Khal player_hand;
	static unsigned active_card;
    Deque cards;

	bool flipped, scrambled;
	int backid=1;

public:
    Game(int n_player=2, int n_deque=1);
    ~Game();

    //GLDrawable table;
    Khal get_player_hand();
    void distribute_cards();
    void fold_all();
    void set_player_hand(Khal);
    void set_player_hand(Haat hand,int id );
    void set_control(GameControls);
};

