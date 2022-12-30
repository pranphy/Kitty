// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-09 22:23
//

#include <random>
#include <algorithm>

#include "Base/KittyEngine.h"
#include "Utility/Mathematical.h"

const std::string KittyEngine::combo_file = "./res/Files/Input/Combination.dat";

KittyEngine::KittyEngine()
{
    std::cout<<"I am constructed in engine"<<std::endl;
    unsigned total_cards = 9;
    std::vector<int> card_id = rand_int_array(0,52,total_cards);
    for (int i : card_id)
        Hand.push_back(Taas(i));

    //shuffle_vec(Hand);
}

KittyEngine::KittyEngine(std::vector<Taas> & hand)
{
    Hand = hand;
}
KittyEngine::~KittyEngine() {}

void print(std::vector<unsigned> const& v) {
    std::cout << "vec "<< " = [" << std::size(v) << "] { ";
    for (auto const& e : v) {
        std::cout << e << ' ';
    }
    std::cout << "} ";
}

// returns an integer array of random numbers
// the address of array random numbers(consecutive integers)  of length lng from
// lb  to ub (inclusive) is returned. if rpt=TRUE==1 the numbers may be repeated
// and if rpt=FALSE==0 the random numbers are not repeated
//


/*
std::vector<Taas> KittyEngine::modern_solve()
{
    std::vector<std::vector<unsigned>> combo_vec = get_combo(combo_file);
    std::vector<float> scores;
    for(std::vector<unsigned> cur_hand_ary : combo_vec)
    {
        float score = get_score(Hand,cur_hand_ary);
        //std::cout<<"Score for "; print(cur_hand_ary); std::cout<<" is "<<score<<std::endl;
        //std::cout<<std::endl<<std::endl;
        scores.push_back(score);
    }
    unsigned max_loc = std::distance(scores.begin(),std::max_element(scores.begin(),scores.end()));
    std::vector<unsigned> max_seq = combo_vec.at(max_loc);

    //std::vector<Taas> solved = arrange_seq(Hand,max_seq);
    Hand = arrange_seq(Hand,max_seq);
    return Hand;
}
*/

std::vector<unsigned> KittyEngine::select_best(std::vector<std::vector<unsigned>>combo_vec,std::vector<std::vector<float>> scores)
{
    unsigned length = combo_vec.size();
    std::vector<float> sum_scores;
    for (std::vector<float> score : scores)
    {
        float sum = std::accumulate(score.begin(),score.end(),0.0);
        sum_scores.push_back(sum);
    }
    float max_score = *std::max_element(sum_scores.begin(),sum_scores.end());
    for(unsigned j =0; j< length; ++j)
    {
        if(sum_scores.at(j) == max_score)
        {
            std::vector<float> copy = scores.at(j);
            std::sort(copy.begin(),copy.end(),std::greater<>());
            if (copy == scores.at(j))
                return combo_vec.at(j);
        }
    }
    unsigned max_loc = std::distance(scores.begin(),std::max_element(scores.begin(),scores.end()));
    std::vector<unsigned> max_seq = combo_vec.at(max_loc);
    return max_seq;
}

std::vector<Taas> KittyEngine::modern_solve()
{
    std::vector<std::vector<unsigned>> combo_vec = get_combo(combo_file);
    std::vector<std::vector<float>> scores;
    for(std::vector<unsigned> cur_hand_ary : combo_vec)
    {
        std::vector<float> score = get_mini_ranks(Hand,cur_hand_ary);
        //std::cout<<"Score for "; print(cur_hand_ary); std::cout<<" is "<<score<<std::endl;
        //std::cout<<std::endl<<std::endl;
        scores.push_back(score);
    }
    std::vector<unsigned> best_seq = select_best(combo_vec,scores);
    //std::vector<Taas> solved = arrange_seq(Hand,max_seq);
    Hand = arrange_seq(Hand,best_seq);
    return Hand;
}

std::vector<Taas> KittyEngine::arrange_seq(std::vector<Taas>& hand, std::vector<unsigned>& seq) const
{
    std::vector<Taas> arranged;

    for (unsigned i : seq)
        arranged.push_back(hand[i]);
    return arranged;

}

void KittyEngine::display()
{
    for(auto card : Hand)
        std::cout<<card<<" ";

    std::cout<<std::endl;
}

std::vector<float> KittyEngine::get_mini_ranks(std::vector<Taas>& hand, std::vector<unsigned> arrange_alt)
{

    std::vector<Taas> arranged = arrange_seq(hand,arrange_alt);
    std::vector<float> mranks;
    for(unsigned i = 0; i < 9; i+=3)
        mranks.push_back( get_mini_rank(arranged[i],arranged[i+1], arranged[i+2]) );
    return mranks;
}

float KittyEngine::get_score(std::vector<Taas>& hand, std::vector<unsigned> arrange_alt)
{

    std::vector<Taas> arranged = arrange_seq(hand,arrange_alt);
    float rank = 0.0;
    for(unsigned i = 0; i < 9; i+=3)
        rank += get_mini_rank(arranged[i],arranged[i+1], arranged[i+2]);
    return rank;
}

float KittyEngine::get_mini_rank(Taas a,Taas b,Taas c)
{
    unsigned p[] = {a.get_value(),b.get_value(),c.get_value()};
    std::sort(p,p+3);

    if(is_trial(a,b,c))
    {
        return 600 + p[0]/13.*100;
    }
    else if(is_double_run(a,b,c))
    {
        return 500+p[2]/13.*100+p[1]/13.*10;
    }
    else if(is_run(a,b,c))
    {
        return 400+p[2]/13.*100+p[1]/13.*10;
    }
    else if(is_colour(a,b,c))
    {
        return 300 + p[2]/13.*100 + p[1]/13.*10;
    }
    else if(is_joute(a,b,c))
    {
        unsigned common = p[0] == p[1] ? p[0] : p[2];
        unsigned uncommon = p[0] == p[1] ? p[2] : p[0];
        return 200 + common/13.*100 + uncommon/13.*10;
    }
    else
    {
        return 100 + p[2]/13.*100 + p[1]/13.*10;
    }
    return 0.0;
}

bool KittyEngine::is_trial(Taas a, Taas b, Taas c)
{
    return  (a.get_value() == b.get_value()) && (b.get_value() == c.get_value());
}

bool KittyEngine::is_run(Taas p, Taas q, Taas r)
{
    unsigned a[] = {p.get_value(),q.get_value(),r.get_value()};
    std::sort(a,a+3);
    return  ( (a[0]+1==a[1]) && (a[1]+1 == a[2]) ) || (a[0] == 1 && a[1] == 2 && a[2] == 13);
}

bool KittyEngine::is_joute(Taas p,Taas q,Taas r)
{
    unsigned a[] = {p.get_value(),q.get_value(),r.get_value()};
    std::sort(a,a+3);
    return  ( a[0] == a[1] || a[1] == a[2]) ;
}

bool KittyEngine::is_colour(Taas p,Taas q,Taas r)
{
  return  (p.type == q.type) && (q.type == r.type);
}

bool KittyEngine::is_double_run(Taas p,Taas q,Taas r)
{
    return is_trial(p,q,r) && is_colour(p,q,r);
}


int KittyEngine::compare(Taas a1, Taas a2, Taas a3, Taas b1, Taas b2, Taas b3)
{
    float ra = get_mini_rank(a1,a2,a3);
    float rb = get_mini_rank(b1,b2,b3);
    return (ra == rb ) ? 0 : (ra > rb) ? 1 : 2;
}


//GLuint LoadPhoto(std::string ImageName)
//{
//      GLuint tex_2d = SOIL_load_OGL_texture
//                    (
//                        ImageName.c_str(),
//                        SOIL_LOAD_AUTO,
//                        SOIL_CREATE_NEW_ID,
//                        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
//                    );
//    if(!tex_2d)
//    {
//        //wxMessageBox(St,wxT("Alas "));
//    }
//    else
//    {
//        //wxMessageBox(St,wxT(" Bravoo "));
//    }
//    GLuint text = 0;
//    return tex_2d;
//    return text;
//}

