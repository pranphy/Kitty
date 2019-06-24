// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-22 18:03
//
#include "Base/Deque.h"

Deque::Deque(unsigned n_books)
{
    for(unsigned i = 0; i<n_books; ++i)
    {
        std::vector<Taas> cur_deque = create_deque();
        cards.insert(std::end(cards),std::begin(cur_deque),std::end(cur_deque)); 
    } 
}

std::vector<Taas> Deque::create_deque()
{
    std::vector<Taas> one_deque;
    for(unsigned i = 0; i<52; ++i)
        one_deque.push_back(Taas(i)); 
    return one_deque; 
}
