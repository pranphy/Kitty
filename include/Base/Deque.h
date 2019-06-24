// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-22 18:02

#include<iostream>

#include "Base/Taas.h"

class Deque
{
private:
    std::vector<Taas> cards;
    std::vector<Taas> create_deque();

public:
    Deque(unsigned n_books=1);
    ~Deque();

};
