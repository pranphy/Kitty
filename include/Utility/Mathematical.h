#ifndef MATHEMATICAL_H_INCLUDED
#define MATHEMATICAL_H_INCLUDED


#include<iostream>
#include <vector>
#include <string>

#include <random>
#include <algorithm>

template <class T>
void Swap(T&a,T&b)
{
    T c; c=a;
    a=b;
    b=c;
}


template<class T>
std::vector<T> arange(T a, T b, T inc=1)
{
    std::vector<T> rvec;
    while(a <= b)
    {
        rvec.push_back(a);
        a += inc;
    }
    return rvec;
}


template<class  T>
void shuffle_deq(T& hand)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::shuffle(hand.begin(),hand.end(),mt);
}

std::vector<int> rand_int_array(int lb,int ub, unsigned lng, bool rpt=false);


/*Generates random number in the range. Look definion on .cpp for more information on this function*/
/*checks whether the given number is already among teh array contents*/
std::vector<std::vector<unsigned>> get_combo(std::string);

std::vector<std::vector<unsigned>> read_combo(std::string);

#endif // MATHEMATICAL_H_INCLUDED
