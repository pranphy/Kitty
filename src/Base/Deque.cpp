// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-22 18:03
//
#include "Base/Deque.h"
#include "Utility/Mathematical.h"

const unsigned Deque::CARDS_PER_DEQUE = 52;

Deque::Deque(unsigned n_books)
{
    for(unsigned i = 0; i<n_books; ++i)
        for(unsigned j = 0; j<CARDS_PER_DEQUE; ++j)
            cards.push_back(Taas(j));
    shuffle_deq(cards);
}

Deque::~Deque() { }

std::deque<Taas> Deque::create_deque()
{
    std::deque<Taas> one_deque;
    for(unsigned i = 0; i<52; ++i)
        one_deque.push_back(Taas(i));
    return one_deque;
}

Taas Deque::deal()
{
    Taas t = cards.front();
    cards.pop_front();
    return t;
}

void Deque::mix(Haat olds)
{
    for(auto taas: olds) cards.push_back(taas);
}

void Deque::shuffle()
{
    shuffle_deq(cards);
}


Haat Deque::deal(int n)
{
    Haat hand;
    for(int i = 0; i < n ; ++i)
    {
        hand.push_back(deal());
    }
    return hand;
}

