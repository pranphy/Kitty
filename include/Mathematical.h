#ifndef MATHEMATICAL_H_INCLUDED
#define MATHEMATICAL_H_INCLUDED

#include "CardStuffs.h"

#include<GL/glut.h>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<iostream>
using namespace std;

#define Wh 920
#define Ww 600

int Random(int);
void initrand(void);
void ConvertDimension(int,int,float&,float&);
void RotateObjects(void);
template <class tin>
void Swap(tin&,tin&);

void RandIntArray(int lb,int ub, int lng, int **adrs , int rpt);
int ChkNumInAry(int num,int lng, int *ary); // check whether num exists in the array of length lng with array base address ary

void ArrangeKitty(int*,int);

int GenerateRank(int,int,int);


#endif // MATHEMATICAL_H_INCLUDED
