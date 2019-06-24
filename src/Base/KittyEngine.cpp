// -*- coding: utf-8 -*-
// vim: ai ts=4 sts=4 et sw=4 ft=cpp

// author : Prakash [प्रकाश]
// date   : 2019-03-09 22:23
//
//

#include "Base/KittyEngine.h"


#include <random>
#include <algorithm>


std::string KittyEngine::combo_file = "./res/Files/Input/Combination.dat";

KittyEngine::KittyEngine():Hand(9)
{

    unsigned total_cards = 9;
    //std::vector<int> Positions = RandIntArray(0,52,52);
    for (unsigned i=0; i< total_cards; ++i)
        Hand.push_back(Taas(i));
    shuffle_vec(Hand);

}

KittyEngine::KittyEngine(std::vector<Taas> & hand)
{ 
    Hand = hand;
}

void KittyEngine::shuffle_vec(std::vector<Taas>& hand)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::shuffle(hand.begin(),hand.end(),mt);
}

KittyEngine::~KittyEngine() {}


// returns an integer array of random numbers
// the address of array random numbers(consecutive integers)  of length lng from
// lb  to ub (inclusive) is returned. if rpt=TRUE==1 the numbers may be repeated
// and if rpt=FALSE==0 the random numbers are not repeated

std::vector<int> KittyEngine::RandIntArray(int lb,int ub, unsigned lng, bool rpt)
{
    std::vector<int> Array(lng);
    std::random_device rd;
    std::mt19937 mt(rd());
    if(!rpt){
        for (unsigned i = 0; i<lng; ++i)
            Array[i] = i + lb;
            
        std::shuffle(Array.begin(),Array.end(),mt);
    }
    else
    {
        std::uniform_int_distribution<int> dist(lb,ub);
        for (unsigned i = 0; i<lng; ++i)
            Array[i] = dist(mt);
    }
    return Array; 
}


void KittyEngine::solve()
{
    //int Array[9];
    //std::vector<int> Array(Cards.begin()+9,Cards.end());
    //std::vector<int> Array;
    
    //std::vector<int> Array = {1,2,3,4,5,6,7,8,9};
    //Card = Card + 9; // To arrange latter nine cards. Leaving behind first nine cards
    int  i = 0;
    //for(auto it=hand.begin()+9; it<hand.end(); it++)
    //    Array[i++] = it->get_id();

    //std::for_each(auto it=Cards.begin()+9,it <Cards.end(),Array.push_back(it->CardNumber));

    //std::vector<int> DoneArray=ArrangeKittyEngine(Array);
    //for(int i=0; i<9; i++)
    //    Cards[9+i].set_value(Array[DoneArray[i]]);
}

std::vector<int> KittyEngine::ArrangeKitty(std::vector<Taas>& hand)
{
    //cout<<" Calling Rank Make Rank File "<<endl;
    RankAndArray RankStruct = MakeRankFile(hand);
    //cout<<" Made Rank File "<<endl;
    std::vector<int> RankArray=AnalyzeStruct(RankStruct);
    //GenerateTopTen();
    //DisplayTopTen(); //yo chai console ma dekhauna lai ho ouput analyze garna. no use for graphics

    // yaha kaam garnu parchha aba
    // tyo top ten ma 3tai ko rank halnu parchha generate function le // yo kaam gariyo
    // ani euta analyze rankfile bhanera euta module le tyo rank haru //aba yabha bata suru garnu parne bho
    // kitty ko order ma arrange garnu parchha ani tesko corresponding
    // array return gare pachi kitty ko logical part sakiyo
    /**Lau kaam ta yaha samma sakiyo ni ta. Choto tarika le. @TopTen select nagarera*/

    // tespachi chai interfacing ra winner channe kaam suru hunchha
    // still a Hell of a ride remaining
    // last tauko rankyo aba chai computer banda garnu parchha
    // next entry point yo hunu parchha as soon as possible.
    // hey dear I miss you even in this situation. Do you know. I
    // cant think anyone besides you. I lvoe you very much.
    return RankArray;
}

std::vector<int> KittyEngine::AnalyzeStruct(RankAndArray& RankStruct)
{
    std::vector<int> CombinationArray=RankStruct.IndexArray;
    std::vector<float> RankArray=RankStruct.RankArray;
    /* I don't know whether this is the best way to find the order of numbers in a array without actually sorting them
    *  but anyway i've used this way here. I don't seem to be interested right now to thinking other ways around
    */
    float a=RankArray[0],b=RankArray[1],c=RankArray[2];
    std::vector<int> p={0,1,2};
    if(a>=b&&b>=c)
    {
        p[0]=1;
        p[1]=2;
        p[2]=3;
    }
    else if(a>=c&&c>=b)
    {
        p[0]=1;
        p[1]=3;
        p[2]=2;
    }
    else if(b>=a&&a>=c)
    {
        p[0]=2;
        p[1]=1;
        p[2]=3;
    }
    else if(b>=c&&c>=a)
    {
        p[0]=2;
        p[1]=3;
        p[2]=1;
    }
    else if(c>=a&&a>=b)
    {
        p[0]=3;
        p[1]=1;
        p[2]=2;
    }
    else if(c>=b&&b>=a)
    {
        p[0]=3;
        p[1]=2;
        p[2]=1;
    }
    std::vector<int> RetArray={0,1,2,3,4,5,6,7,8};

    for(int i=0; i<9; i++)
        RetArray[i]=CombinationArray[3*(p[static_cast<int>(i/3)]-1)+i%3];
    return RetArray;
}


std::vector<std::vector<unsigned>> KittyEngine::read_combo(std::string combo_file)
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
std::vector<std::vector<unsigned>> KittyEngine::get_combo(std::string combo_file)
{
    return read_combo(combo_file);
}


std::vector<Taas> KittyEngine::modern_solve(std::vector<Taas>& hand)
{
    std::vector<std::vector<unsigned>> combo_vec = get_combo();
    std::vector<float> scores;
    for(std::vector<unsigned> cur_hand_ary : combo_vec)
    { 
        float score = get_score(hand,cur_hand_ary);
        

    }
}


float KittyEngine::get_score(std::vector<Taas>& hand, std::vector<unsigned> arrange_alt)
{
    
}

RankAndArray KittyEngine::MakeRankFile(std::vector<Taas>& Array)
{

    std::ofstream TestFile("TestFileForHere.dat");
    /*if(TestFile){
        cout<<" New Test file created"<<endl;
    } else {
        cout<<"Couldn't write test file "<<endl;
        exit(1);
    }
    */
    std::string CombinationFile = "./res/Files/Input/Combination.dat";
    std::string RankFile = "./res/Files/Output/GroupRank.dat";

    std::ifstream Combination(CombinationFile);
    /*if(!Combination){
        cout<<"Couldn't OpenCombination File "<<endl;
    } else {
        cout<<" Combination Opened Successfully"<<endl;
    }*/
    std::ofstream GroupRank(RankFile,std::ios::out|std::ios::binary);
//    if(GroupRank){
//        cout<<" GroupRank OutputFile Written"<<endl;
//    } else {
//        cout<<" Couldn't write groupRank ouptup file "<<endl;
//    }
    /*Writing the card values to the rank file*/

    for(int i=0; i<9; i++)
        GroupRank.write(reinterpret_cast<char*>(&Array[i]),sizeof(Array[i]));
    /*C(9,3)=84 and C(6,3)=20 ie 84*20 is the number of possibel kitty combinations*/
    int Nos=84*20;
    short int a;
    int RtTas[9], Taas[9];
    std::vector<int> RetTas={0,1,2,3,4,5,6,7,8};
    float RtRankArray[3];
    std::vector<float> RetRankArray = {0,1,2};
    float HRank=0.0,AvRank=0.0;
    RankAndArray RetStruct;

    //cout<<" Making rank file now "<<endl;

    for(int i=0; i<Nos ; i++)
    {
        for(int j=0; j<9; j++)
        {
            Combination.read(reinterpret_cast<char*>(&a),sizeof(a));
            RtTas[j] = a;
            //Taas[j] = Array[a];
        }
        float Rank=0.0;
        for(int i=0; i<9 ; i+=3)
        {
            float MiniRank = GetMiniRank(Taas[i],Taas[i+1],Taas[i+2]);
            Rank += MiniRank;
            short int a1,a2,a3;
            a1 = RtTas[i], a2 = RtTas[i+1], a3 = RtTas[i+2];

            RtRankArray[i/3]=MiniRank;

            GroupRank.write(reinterpret_cast<char*>(&a1),sizeof(a1));
            GroupRank.write(reinterpret_cast<char*>(&a2),sizeof(a2));
            GroupRank.write(reinterpret_cast<char*>(&a3),sizeof(a3));
            GroupRank.write(reinterpret_cast<char*>(&MiniRank),sizeof(MiniRank));
        }
        AvRank += Rank; //for statical purposes to find out the average ranks of all cards.
        if (Rank > HRank)
        {
            HRank = Rank;
            for(int i = 0; i<9; i++)
                RetTas[i] = RtTas[i];
            for(int i=0; i<3; i++)
                RetRankArray[i] = RtRankArray[i];
        }
    }
    GroupRank.close();
    Combination.close();
    RetStruct.IndexArray=RetTas;
    RetStruct.RankArray=RetRankArray;
    //cout<<" Hig=  "<<HRank<<" Av = "<<AvRank/1680.<<endl;
    return RetStruct;
}



float KittyEngine::GetRank(std::vector<int> NineCards)
{
    float Rank=0.0;
    for(int i=0; i<9; i+=3)
        Rank += GetMiniRank(NineCards[i],NineCards[i+1],NineCards[i+2]);
    return Rank;
}

float KittyEngine::GetMiniRank(int a,int b,int c)
{
    //int v1,t1,v2,t2,v3,t3;
    //GetCard(a,v1,t1);
    //GetCard(b,v2,t2);
    //GetCard(c,v3,t3);
    //if(is_trial(a,b,c))
    //    return 600+v1/13.*100;
    //else if(is_double_run(a,b,c))
    //{
    //    int Grt=grt_of_three(v1,v2,v3);
    //    int sg=sec_grtthree(v1,v2,v3);
    //    return 500+Grt/13.*100+sg/13.*10;
    //}
    //else if(is_run(a,b,c))
    //{
    //    int Grt=grt_of_three(v1,v2,v3);
    //    int sg=sec_grtthree(v1,v2,v3);
    //    return 400+Grt/13.*100+sg/13.*10;
    //}
    //else if(is_colour(a,b,c))
    //{
    //    int Grt=grt_of_three(v1,v2,v3);
    //    int sg=sec_grtthree(v1,v2,v3);
    //    return 300+Grt/13.*100+sg/13.*10;
    //}
    //else if(is_joute(a,b,c))
    //{
    //    int Com=find_common(v1,v2,v3);
    //    int sg=sec_grtthree(v1,v2,v3);
    //    return 200+Com/13.*100+sg/13.*10;
    //}
    //else
    //{
    //    int Grt=grt_of_three(v1,v2,v3);
    //    int sg=sec_grtthree(v1,v2,v3);
    //    return 100+Grt/13.*100+sg/13.*10;
    //}
    return 0.0;
}


void KittyEngine::GenerateTopTen(void)
{
    std::string RankFile = "./Files/Output/GroupRank.dat";
    std::string TopTenFile = "./Files/Output/TopTen.dat";
    std::ifstream GroupRank(RankFile);
//    if(GroupRank){
//        cout<<" Opened GroupRank file successfully "<<endl;
//    } else {
//        cout<<" Failure in opening GroupRank file "<<endl;
//    }
    std::ofstream TopTen(TopTenFile,std::ios::out|std::ios::binary);
    int CardValue[9];
    /*Reading the card values from the group rank file*/
    for(int i=0; i<9; i++)
        GroupRank.read(reinterpret_cast<char*>(CardValue+i),sizeof(CardValue[i]));
    /*Re writing the same card values on the top ten as well exactly the same*/
    for(int i=0; i<9; i++)
        TopTen.write(reinterpret_cast<char*>(CardValue+i),sizeof(CardValue[i]));

    int RecordNumber=24; //No of records in the top ten file
    /*The following for loop generates a garbage file with zero rank and 1 througb nine as corresponding array*/
    for(int i=0; i<RecordNumber; i++)
    {
        float flt=0.0;
        for(int j=0; j<9; j+=3)
        {
            TopTen.write(reinterpret_cast<char*>(&j),sizeof(j));
            TopTen.write(reinterpret_cast<char*>(&j+1),sizeof(j));
            TopTen.write(reinterpret_cast<char*>(&j+2),sizeof(j));
            TopTen.write(reinterpret_cast<char*>(&flt),sizeof(flt));
        }
    }

    TopTen.close();
    /*Creating a garbabge containing file completed here*/
    int Nos=84*20;
    for(int i=0; i<Nos; i++)
    {
        std::vector<short> CurrentArray = {0,0,0,0,0,0,0,0,0};
        std::vector<float>  RankArray = {0.0,0.0,0.0};
        for(int j=0; j<9; j+=3)
        {
            short int a1,a2,a3;
            float Rank;
            GroupRank.read(reinterpret_cast<char*>(&a1),sizeof(a1));
            GroupRank.read(reinterpret_cast<char*>(&a2),sizeof(a2));
            GroupRank.read(reinterpret_cast<char*>(&a3),sizeof(a3));
            GroupRank.read(reinterpret_cast<char*>(&Rank),sizeof(Rank));
            RankArray[j/3]=Rank;
            CurrentArray[j]=a1,CurrentArray[j+1]=a2,CurrentArray[j+2]=a3;
        }
        UpdateTopTen(CurrentArray,RankArray);
    }
}


void KittyEngine::UpdateTopTen(std::vector<short>& Array,std::vector<float>& ReceivedRankArray)
{
    /*
    *  For statistical purpose i wished to find out the top ranked combination
    *  for every  combination   of 9  cards  but  this  thing  worked too slow
    *  probably   because m y machine's  file I/O  is too   slow or   the disk
    *  communication  is not upto  the standards so I have avoided it actually
    *  from the analysis
    */
    std::string OldFileName = "./Files/Output/TopTen.dat";
    std::string NewFileName = "./Files/Output/TempTopTen.dat";
    std::ifstream TopTen(OldFileName);
    std::ofstream Temp(NewFileName);

    int CardValue[9];
    for(int i=0; i<9; i++)
        TopTen.read(reinterpret_cast<char*>(CardValue+i),sizeof(CardValue[i]));
    for(int i=0; i<9; i++)
        Temp.write(reinterpret_cast<char*>(CardValue+i),sizeof(CardValue[i]));

    int Count=0;
    int RecordNumber=24;
    for(int i=0; i<RecordNumber; i++)
    {
        float RankSum=0.0;
        short int CurrentArray[9]= {0,0,0,0,0,0,0,0,0};
        float RankArray[3]= {0.0,0.0,0.0};
        for(int j=0; j<9; j+=3)
        {
            TopTen.read(reinterpret_cast<char*>(CurrentArray+j),sizeof(CurrentArray[j]));
            TopTen.read(reinterpret_cast<char*>(CurrentArray+j+1),sizeof(CurrentArray[j]));
            TopTen.read(reinterpret_cast<char*>(CurrentArray+j+2),sizeof(CurrentArray[j]));
            TopTen.read(reinterpret_cast<char*>(RankArray+j/3),sizeof(RankArray[0]));
            RankSum+=RankArray[j/3];
        }
        Count++;
        float ReceivedRank=ReceivedRankArray[0]+ReceivedRankArray[1]+ReceivedRankArray[2];
        if(ReceivedRank>RankSum)
        {
            for(int j=0; j<9; j+=3)
            {
                Temp.write(reinterpret_cast<char*>(&Array[j]),sizeof(Array[0]));
                Temp.write(reinterpret_cast<char*>(&Array[j+1]),sizeof(Array[0]));
                Temp.write(reinterpret_cast<char*>(&Array[j+2]),sizeof(Array[0]));
                Temp.write(reinterpret_cast<char*>(&ReceivedRankArray[j/3]),sizeof(ReceivedRankArray[0]));
            }
            for(int k=0; k<RecordNumber-Count; k++)
            {
                for(int j=0; j<9; j+=3)
                {
                    Temp.write(reinterpret_cast<char*>(&Array[j]),sizeof(Array[0]));
                    Temp.write(reinterpret_cast<char*>(&Array[j+1]),sizeof(Array[0]));
                    Temp.write(reinterpret_cast<char*>(&Array[j+2]),sizeof(Array[0]));
                    Temp.write(reinterpret_cast<char*>(&ReceivedRankArray[j/3]),sizeof(ReceivedRankArray[0]));
                }
                for(int j=0; j<9; j+=3)
                {
                    Temp.write(reinterpret_cast<char*>(&Array[j]),sizeof(Array[0]));
                    Temp.write(reinterpret_cast<char*>(&Array[j+1]),sizeof(Array[0]));
                    Temp.write(reinterpret_cast<char*>(&Array[j+2]),sizeof(Array[0]));
                    Temp.write(reinterpret_cast<char*>(&ReceivedRankArray[j/3]),sizeof(ReceivedRankArray[0]));
                }
            }
            break;
        }
        else
        {
            for(int j=0; j<9; j+=3)
            {
                Temp.write(reinterpret_cast<char*>(&Array[j]),sizeof(Array[0]));
                Temp.write(reinterpret_cast<char*>(&Array[j+1]),sizeof(Array[0]));
                Temp.write(reinterpret_cast<char*>(&Array[j+2]),sizeof(Array[0]));
                Temp.write(reinterpret_cast<char*>(&ReceivedRankArray[j/3]),sizeof(ReceivedRankArray[0]));
            }
        }
    }
    TopTen.close();
    Temp.close();
    remove(OldFileName.data());
    rename(NewFileName.c_str(),OldFileName.c_str());
}

void KittyEngine::DisplayTopTen()
{

    /*
    string TopTenFile = "./Files/Output/TopTen.dat";
    ifstream TopTen(TopTenFile);
    int CardValue[9];
    for(int i=0;i<9;i++)
        TopTen.read(reinterpret_cast<char*>(CardValue+i),sizeof(CardValue[i]));
    for(int i=0;i<9;i++)
    {
        int val,typ;
        GetCard(CardValue[i],val,typ);
        cout<<val<<static_cast<char>(typ)<<" ";
    }
    cout<<endl;
    cout<<"Group1  Rank       Group2  Rank       Group3  Rank         Total"<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    int RecordNumber=24;
    for(int i=0;i<RecordNumber;i++)
    {
        float RankSum=0.0;
        short int CurrentArray[9]={0,0,0,0,0,0,0,0,0};
        float RankArray[3]={0.0,0.0,0.0};
        for(int j=0;j<9;j+=3)
        {
            TopTen.read(reinterpret_cast<char*>(CurrentArray+j),sizeof(CurrentArray[0]));
            TopTen.read(reinterpret_cast<char*>(CurrentArray+j+1),sizeof(CurrentArray[0]));
            TopTen.read(reinterpret_cast<char*>(CurrentArray+j+2),sizeof(CurrentArray[0]));
            TopTen.read(reinterpret_cast<char*>(RankArray+j/3),sizeof(RankArray[0]));
        }
        for(int j=0;j<9;j+=3)
        {
            cout.precision(1);cout.width(1);
            cout<<CurrentArray[j]<<" "<<CurrentArray[j+1]<<" "<<CurrentArray[j+2]<<" ";
            cout.precision(6);cout.width(9);
            cout<<RankArray[j/3]<<"    ";
            RankSum+=RankArray[j/3];
        }
        cout<<"   "<<RankSum<<endl;
    }
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<" Top "<<RecordNumber<<" rank combinations "<<endl;
    */
}
/*
*  The following function was initially written in C (not c++)
*  so my standard variable naming conventions are hafazard down here.
*/



bool KittyEngine::is_trial(int a, int b, int c)
{
    int v1,t1,v2,t2,v3,t3;
    GetCard(a,v1,t1);
    GetCard(b,v2,t2);
    GetCard(c,v3,t3);
    return((v1==v2)&&(v2==v3));
}

bool KittyEngine::is_run(int p1, int q, int r)
{
    int a,t1,b,t2,c,t3;
    GetCard(p1,a,t1);
    GetCard(q,b,t2);
    GetCard(r,c,t3);
    int m,n,p;
    m=a>b?a-b:b-a;
    n=b>c?b-c:c-b;
    p=a>c?a-c:c-a;

    int gt=grt_of_three(a,b,c);
    int sg=sec_grtthree(a,b,c);
    int lt=least_of_three(a,b,c);

    if(((m==1&&n==1)||(m==1&&p==1)||(n==1&&p==1))&&(a!=b&&b!=c&&c!=a))
        return 1;
    else if(gt==13&&sg==2&&lt==1)
        return 1;
    else
        return 0;
}

bool KittyEngine::is_joute(int p,int q,int r)

{
    int a,t1,b,t2,c,t3;
    GetCard(p,a,t1);
    GetCard(q,b,t2);
    GetCard(r,c,t3);

    if(a==b||b==c||a==c)
        return 1;
    else
        return 0;
}

bool KittyEngine::is_colour(int p,int q,int r)
{
    int a,t1,b,t2,c,t3;
    GetCard(p,a,t1);
    GetCard(q,b,t2);
    GetCard(r,c,t3);

    return( is_trial(t1,t2,t3));
}

bool KittyEngine::is_double_run(int p,int q,int r)
{
    int a,t1,b,t2,c,t3;
    GetCard(p,a,t1);
    GetCard(q,b,t2);
    GetCard(r,c,t3);
    return((is_trial(t1,t2,t3))&&(is_run(a,b,c)));
}

/*
//  Bachha function haru tala chhan haha ramailo chha jindagi
//  yesto bachha function pani kati kam lagne hunchha  kahile
//  kahi program ma. Kati  sajilo banauchha kamlai yesto sano
//  function  haru le. Jindagi sarhai ramailo chha .. Tuk tuk
*/

int KittyEngine::which_great(int a1, int a2, int a3, int b1,int b2, int b3)   // check great in case of a top
{
    int c;
    c=grt_of_three(a1,a2,a3)- grt_of_three(b1,b2,b3);
    if (c>0)
        return 1;
    else if (c<0)
        return 2;
    else
    {
        c=sec_grtthree(a1,a2,a3)-sec_grtthree(b1,b2,b3);
        if(c>0)
            return 1;
        else if (c<0)
            return 2;
        else
        {
            c=least_of_three(a1,a2,a3)-least_of_three(b1,b2,b3);
            if(c>0)
                return 1;
            else if(c<0)
                return 2;
            else
                return 0;
        }
    }
}


int KittyEngine::sec_grtthree(int a, int b, int c)
{
    if(((b-a)>0&&(b-c)<0)||((b-a)<0&&(b-c)>0))
        return b;
    else if (((c-b)>0&&(c-a)<0)||((c-b)<0&&(c-a)>0))
        return c;
    else
        return a;
}


int KittyEngine::least_of_three(int a,int b, int c)
{
    return ((a<b?a:b)<c?(a<b?a:b):c);
}



int KittyEngine::find_common(int a, int b, int c)
{
    if(a==b||a==c)
        return a;
    else if (b==a||b==c)
        return b;
    else if(c==a||c==b)
        return c;
    else
        return 0;
}


int KittyEngine::grt_of_three(int a, int b , int c)
{
    return (a>b? a:b)> c? (a>b?a:b):c;
}

int KittyEngine::find_grt_of_com(int a1, int a2, int a3, int b1, int b2, int b3)   //find winnder of joute
{
    int c;
    c=find_common(a1,a2,a3)-find_common(b1,b2,b3);
    if(c>0)
        return 1;
    else if (c<0)
        return 2;
    else
        return 0;
}


int KittyEngine::find_uncommon(int a, int b, int c)
{
    if(a!=b&&a!=c)
        return a;
    else if (b!=a && b!=c)
        return b;
    else
        return c;
}


int KittyEngine::compare(int a1, int a2, int a3, int b1, int b2, int b3)
{
    int a,b,c,d,e,p,q;
    p=is_trial(a1,a2,a3);
    q=is_trial(b1,b2,b3);
    if (p==1&&q==1)
    {
        if (a1>b1)
            return 1;
        else
            return 2;
    }
    else if (p==1&&q==0)
        return 1;
    else if (p==0&&q==1)
        return 2;
    else
    {
        a=is_run(a1,a2,a3);
        b=is_run(b1,b2,b3);
        if(a==1&&b==1)
        {
            if(grt_of_three(a1,a2,a3)>grt_of_three(b1,b2,b3))
                return 1;
            else if(grt_of_three(a1,a2,a3)<grt_of_three(b1,b2,b3))
                return 2;
            else
                return 0;
        }
        else if(a==1&&b==0)
            return 1;
        else if(a==0&&b==1)
            return 2;

        else if (a==0&&b==0)
        {
            c=is_joute(a1,a2,a3);
            d=is_joute(b1,b2,b3);
            if(c==1&&d==1)
            {
                e=find_grt_of_com(a1,a2,a3,b1,b2,b3);
                if (e==1)
                    return 1;
                else if (e==2)
                    return 2;
                else if (e==0)
                {
                    if (find_uncommon(a1,a2,a3)>find_uncommon(b1,b2,b3))
                        return 1;
                    else if (find_uncommon(a1,a2,a3)<find_uncommon(b1,b2,b3))
                        return 2;
                    else if (find_uncommon(a1,a2,a3)==find_uncommon(b1,b2,b3))
                        return 0;
                }
            }
            else if (c==1&&d==0)
                return 1;
            else if (c==0&&d==1)
                return 2;
            else
                return which_great(a1,a2,a3,b1,b2,b3);
        }
    }
    return 0;
}


GLuint LoadPhoto(std::string ImageName)
{
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
    GLuint text = 0;
//    return tex_2d;
    return text; 

}


void KittyEngine::GetCard(int a, int b, int c )
{
    
}
