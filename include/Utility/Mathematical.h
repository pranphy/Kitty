#ifndef MATHEMATICAL_H_INCLUDED
#define MATHEMATICAL_H_INCLUDED


#include<iostream>
#include<vector>
#include<string>

#include "Base/Taas.h"


template <class T>
void Swap(T&,T&);

std::vector<int> rand_int_array(int lb,int ub, unsigned lng, bool rpt=false);

//template<class T>
//void shuffle_vec(std::vector<Taas>& hand);

/*Generates random number in the range. Look definion on .cpp for more information on this function*/
/*checks whether the given number is already among teh array contents*/
std::vector<std::vector<unsigned>> get_combo(std::string);

std::vector<std::vector<unsigned>> read_combo(std::string);

#endif // MATHEMATICAL_H_INCLUDED
