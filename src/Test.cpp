// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-09 22:59
//
// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-09 23:00

#include<bits/stdc++.h>
#include "Base/KittyEngine.h"

void TestKittyEngine();
void TestComboRead();
void TestRandInt();

int main()
{
    std::cout<<"Hello World"<<std::endl;
    TestKittyEngine();
    return 0;
}


void TestKittyEngine()
{
    TestComboRead();
}

void TestRandInt()
{
    KittyEngine KE;
    std::vector<int> randoms = KE.RandIntArray(2,15,13);
    std::for_each(randoms.begin(),randoms.end(),[&](int it){std::cout<<it<<std::endl;});
}

void TestComboRead(){
    KittyEngine KE;
    std::vector<std::vector<unsigned>> cv = KE.get_combo();
    for(auto line : cv)
    {
        for(auto num : line)
        {
            std::cout<<num<< " ";
        }
        std::cout<<std::endl;
    }
}


