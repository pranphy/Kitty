// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-22 18:02

#include<iostream>
#include<deque>

#include "Base/Taas.h"


class Deque
{
private:
    std::deque<Taas> cards;
    std::deque<Taas> create_deque();

public:
    const static unsigned CARDS_PER_DEQUE;
    Deque(unsigned n_books=1);
    ~Deque();

};
