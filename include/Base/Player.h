// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-22 17:17

#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<string>

#include "Base/Taas.h"
#include "Base/KittyEngine.h"

const static std::string empty = std::string("");

class Player
{
private:
    std::string first_name;
    std::string last_name;
    KittyEngine brain;
    std::vector<Taas> hand;


public:
    Player(std::string = "", std::string = "");
    Player(std::vector<Taas> hand);
    ~Player();
    void set_name(std::string& );
    void set_hand(std::vector<Taas>);
    std::string get_name();

};

#endif

