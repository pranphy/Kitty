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

class KittyEngine   
{
private:
    std::vector<Taas> Hand;
    static std::string combo_file;

    std::vector<std::vector<unsigned>> all_combination;
    std::vector<std::vector<unsigned>> read_combo(std::string combo_file);
    float get_score(std::vector<Taas>& hand, std::vector<unsigned> arrange_alt);


    int                    grt_of_three      (int,int,int);
    /*Function takes 3 integers of which at least two (or possibly all) are equal as arguments and returns one of the equal numbers*/
    int                    find_common       (int,int,int);
    int                    sec_grtthree      (int,int,int);
    int                    least_of_three    (int,int,int);
    int                    find_grt_of_com   (int a1, int a2, int a3, int b1, int b2, int b3);
    int                    find_uncommon     (int a, int b, int c);
    int                    which_great       (int a1, int a2, int a3, int b1,int b2, int b3);
    bool                   is_trial          (int,int,int);
    bool                   is_run            (int,int,int);
    bool                   is_double_run     (int,int,int);
    bool                   is_colour         (int,int,int);
    bool                   is_joute          (int,int,int);
    int                    compare           (int,int,int,int,int,int);
    int                    rndm              (int);

protected:
    int b;

public:
    KittyEngine();
    KittyEngine(std::vector<Taas>&);
    ~KittyEngine();


    void shuffle_vec(std::vector<Taas> &);

    void                   solve();
    std::vector<int>       ArrangeKitty   (std::vector<Taas> &);
    RankAndArray           MakeRankFile   (std::vector<Taas> &);
    std::vector<int>       AnalyzeStruct  (RankAndArray&);
    void                   UpdateTopTen   (std::vector<short int>&,std::vector<float>&);
    void                   GenerateTopTen (void);
    void                   DisplayTopTen  (void);

    float                  GetRank        (std::vector<int>);
    float                  GetMiniRank    (int,int,int);
    /*Generates random number in the range. Look definion on .cpp for more information on this function*/
    std::vector<int>       RandIntArray   (int,int,unsigned,bool=false);
    /*checks whether the given number is already among teh array contents*/
    int                    ChkNumInAry    (int,int, std::vector<int>);
    /*seeds the standard rand function with the current time(in seconds)*/
    void                   initrand       ();
    /*Generates a random integer in the range 0 to (paramater passed)*/
    int                    Random         (int);
    /*Finds teh greatest of three given numbers.*/

    void GetCard(int,int,int);
    std::vector<std::vector<unsigned>> get_combo(std::string=combo_file);
};
