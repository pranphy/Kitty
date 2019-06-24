// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-22 17:17

#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<string>

class Player
{
private:
    std::string Name;

public:
    Player();
    ~Player();
    void set_name(std::string& );
    std::string get_name();

};

#endif

