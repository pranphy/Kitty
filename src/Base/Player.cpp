// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-22 17:24

#include "Base/Player.h"

Player::Player(std::string first_name, std::string last_name)
{
    this->first_name = first_name;
    this->last_name = last_name;
}

Player::Player(std::vector<Taas> phand):hand(phand)
{
    first_name = "Hamro";
    last_name = "Manchhe";
}

Player::~Player() {}


void Player::set_name(std::string& pName)
{
    first_name = pName;
}

void Player::set_hand(std::vector<Taas> hand)
{
    this->hand = hand;
}

std::string Player::get_name()
{
    return first_name + " " + last_name;
}
