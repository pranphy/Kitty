/*************************************************/
/** Author        : @PrakashGautam               */
/** First Written : Dec 30, 2012                 */
/** Last Updated  : Oct 20, 2013                 */
/** fb.com/pranphy<>http://pranphy.wordpress.com */
/*************************************************/

#include <fstream>
#include <random>
#include <algorithm>

#include "Utility/Mathematical.h"

std::vector<int> random_sample(std::vector<int> source,unsigned sample_size)
{
    std::vector<int> sampled;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::sample(source.begin(), source.end(), std::back_inserter(sampled), sample_size, mt);
    return sampled;
}

/**
   My old function that was supposed to make a random integer array.
   @param lb Lower bound of the random integers
   @param ub upper bound of the random integers
   @param lng the length of resulting array
   @param rtp whether to repeat the random numbers. `rpt=false` will cause
   all the number in resulting array be unique. This means the parameter lng
   must be smaller thatn the difference lb and ub $ ub - lb < lng $
   */
std::vector<int> rand_int_array(int lb,int ub, unsigned lng, bool rpt)
{
    std::cout<<"Generating ints from "<<lb<<" to "<<ub<<" of length "<<lng<<" "<<std::endl;
    std::vector<int> full;
    while(ub > lb) full.push_back(--ub);

    std::vector<int> Array = random_sample(full,lng);
    return Array;
    std::cout<< " Now showing them "<<std::endl;
    for(unsigned k: Array)
        std::cout<<k<<", ";
    std::cout<<std::endl;
    return Array;
}

std::vector<std::vector<unsigned>> read_combo(std::string combo_file)
{
    std::vector<std::vector<unsigned>> vec;
    std::ifstream Combination(combo_file,std::ios::binary);
    unsigned Nos = 84*20;
    short a;
    for(unsigned i=0; i<Nos ; i++)
    {
        std::vector<unsigned> cur_line;
        for(unsigned j=0; j<9; j++)
        {
            Combination.read(reinterpret_cast<char*>(&a),sizeof(a));
            unsigned val = unsigned(a);
            cur_line.push_back(val);
        }
        vec.push_back(cur_line);
    }
    return vec;
}

std::vector<std::vector<unsigned>> get_combo(std::string combo_file)
{
    return read_combo(combo_file);
}

