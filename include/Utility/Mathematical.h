#ifndef MATHEMATICAL_H_INCLUDED
#define MATHEMATICAL_H_INCLUDED

#include "Base/CardStuffs.h"

#include<GL/glut.h>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<iostream>
using namespace std;

#define Wh 920
#define Ww 600

int      Random            (int);
void     initrand          (void);
void     ConvertDimension  (int,int,float&,float&);
void     RotateObjects     (void);

template <class tin>
void Swap(tin&,tin&);

std::vector<int>     RandIntArray     (int,int,int,int);
bool     ChkNumInAry      (int,int,int);

void     ArrangeKitty     (int*,int);

int      GenerateRank     (int,int,int);


#endif // MATHEMATICAL_H_INCLUDED
