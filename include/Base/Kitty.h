// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-09 21:11

#include<iostream>
#include<vector>

#include "Base/Taas.h"

struct  RankAndArray
{
    std::vector<int>    IndexArray;
    std::vector<float>  RankArray;
};

class Kitty   
{
private:
    int a;

protected:
    int b;

public:
    Kitty();
    ~Kitty();


    void                   Arrange        (std::vector<Taas>&,GLuint*);
    std::vector<int>       ArrangeKitty   (std::vector<int>);
    RankAndArray           MakeRankFile   (std::vector<int>);
    std::vector<int>       AnalyzeStruct  (RankAndArray&);
    void                   UpdateTopTen   (std::vector<short int>&,std::vector<float>&);
    void                   GenerateTopTen (void);
    void                   DisplayTopTen  (void);

    float                  GetRank        (std::vector<int>);
    float                  GetMiniRank    (int,int,int);
    /*Generates random number in the range. Look definion on .cpp for more information on this function*/
    std::vector<int>       RandIntArray   (int,int,unsigned,bool);
    /*checks whether the given number is already among teh array contents*/
    int                    ChkNumInAry    (int,int, std::vector<int>);
    /*seeds the standard rand function with the current time(in seconds)*/
    void                   initrand       ();
    /*Generates a random integer in the range 0 to (paramater passed)*/
    int                    Random         (int);
    /*Finds teh greatest of three given numbers.*/
    int                    GreatOfThree   (int,int,int);
    /*Function takes 3 integers of which at least two (or possibly all) are equal as arguments and returns one of the equal numbers*/
    int                    FindCommon     (int,int,int);
    int                    sec_grtthree   (int,int,int);
    int                    leastofthree   (int,int,int);
    bool                   IsTrial        (int,int,int);
    bool                   IsRun          (int,int,int);
    bool                   IsDoubleRun    (int,int,int);
    bool                   IsColour       (int,int,int);
    bool                   IsJoute        (int,int,int);
    int                    compare        (int,int,int,int,int,int);
    int                    rndm           (int);
};
