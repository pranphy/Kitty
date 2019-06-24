// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-22 17:24

#include "Base/Player.h"

Player::Player():Name("John Doe"){}

Player::~Player() {}

void Player::set_name(std::string& pName)
{
    Name = pName;
}


std::string Player::get_name()
{
    return "hello";
}
