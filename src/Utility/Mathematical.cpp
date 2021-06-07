/*************************************************/
/** Author        : @PrakashGautam               */
/** First Written : Dec 30, 2012                 */
/** Last Updated  : Oct 20, 2013                 */
/** fb.com/pranphy<>http://pranphy.wordpress.com */
/*************************************************/

#include<fstream>
#include<random>
#include<algorithm>

#include "Utility/Mathematical.h"

template <class T>
void Swap(T&a,T&b)
{
    T c; c=a;
    a=b;
    b=c;
}

std::vector<int> random_sample(std::vector<int> source,unsigned sample_size)
{
    std::vector<int> sampled;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::sample(source.begin(), source.end(), std::back_inserter(sampled), sample_size, mt);
    return sampled;
}

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



//template<class  T>
//void shuffle_vec(std::vector<Taas>& hand)
//{
//    std::random_device rd;
//    std::mt19937 mt(rd());
//    std::shuffle(hand.begin(),hand.end(),mt);
//}


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

