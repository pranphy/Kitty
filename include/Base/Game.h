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
    std::vector<Player> players;

    std::vector<std::vector<Taas>> player_hand;

	static unsigned active_card;
    Deque cards;

	bool Flipped, Scrambled;
	int BackId=1;

public:
    Game(int n_player=2, int n_deque=1);
    ~Game();

    //GLDrawable table;
    std::vector<std::vector<Taas>> get_player_hand();
    void distribute_cards();
    void set_player_hand(std::vector<Taas> hand,int id );
    void set_control(GameControls);
};

