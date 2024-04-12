// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-22 17:24

#include "Base/Player.h"
#include "Utility/Mathematical.h"

Player::Player(std::string first_name, std::string last_name)
    : arranged(false), shown(false)
{
    this->first_name = first_name;
    this->last_name = last_name;
}

Player::Player(std::vector<Taas> phand):hand(phand), arranged(false), shown(false)
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
void Player::shuffle()
{
    shuffle_deq(hand);
}

std::string Player::get_name()
{
    return first_name + " " + last_name;
}
