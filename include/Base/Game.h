// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-21 11:03

#ifndef GAME_H
#define GAME_H

// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-21 11:03

#include<iostream>
#include<map>

#include "Base/KittyEngine.h"
#include "Base/Player.h"
#include "Base/Deque.h"

#include "Base/Drawable.h"

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
    // Player player;
    KittyEngine kitty;
    GLDrawable Table;

    std::map<Player,std::vector<Taas>> player_hand;

	static int ActiveCard;
    std::vector<Taas> cards;

	bool Flipped, Scrambled;
	int BackId=1;
    
public:
    Game();
    ~Game();

    void set_control(GameControls);
};

#endif

