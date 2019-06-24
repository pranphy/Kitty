// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-21 11:04
//
//

#include <map> 
#include "Base/Game.h"


Game::Game()
{
    // make game
}

Game::~Game() {}

void Game::set_control(GameControls ct)
{
    std::cout<<"ct received "<<ct<<std::endl;
}



