// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-22 18:03
//
#include "Base/Deque.h"

const unsigned Deque::CARDS_PER_DEQUE = 52;

Deque::Deque(unsigned n_books):cards(CARDS_PER_DEQUE*n_books)
{
    for(unsigned i = 0; i<n_books; ++i)
    {
        std::deque<Taas> cur_deque = create_deque();
        for(unsigned j = 0; j<CARDS_PER_DEQUE; ++j)
        {
            cards[i*CARDS_PER_DEQUE + j] = cur_deque[i];
            //cards.insert(std::end(cards),std::begin(cur_deque),std::end(cur_deque)); 
        }
    } 
}

Deque::~Deque() { }

std::deque<Taas> Deque::create_deque()
{
    std::deque<Taas> one_deque;
    for(unsigned i = 0; i<52; ++i)
        one_deque.push_back(Taas(i)); 
    return one_deque; 
}
