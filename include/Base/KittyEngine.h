// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-09 21:11

#pragma once

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
    KittyEngine();
    KittyEngine(std::vector<Taas>&);
    static const std::string combo_file;

    std::vector<std::vector<unsigned>> all_combination;


    bool                   is_trial          (Taas,Taas,Taas);
    bool                   is_run            (Taas,Taas,Taas);
    bool                   is_double_run     (Taas,Taas,Taas);
    bool                   is_colour         (Taas,Taas,Taas);
    bool                   is_joute          (Taas,Taas,Taas);
    int                    compare           (Taas,Taas,Taas,Taas,Taas,Taas);
    int                    rndm              (int);
    std::vector<Taas>      arrange_seq(std::vector<Taas>&,std::vector<unsigned>&) const;
    float                  get_mini_rank(Taas, Taas, Taas);
    std::vector<float> get_mini_ranks(std::vector<Taas>&, std::vector<unsigned>);
    std::vector<unsigned> select_best(std::vector<std::vector<unsigned>>combo_vec,std::vector<std::vector<float>> scores);

public:
    ~KittyEngine();
    static KittyEngine& Instance();

    float get_score(std::vector<Taas>& hand, std::vector<unsigned> arrange_alt);

    std::vector<Taas> modern_solve(std::vector<Taas>);
};


