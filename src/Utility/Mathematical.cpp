/*************************************************/
/** Author        : @PrakashGautam               */
/** First Written : Dec 30, 2012                 */
/** Last Updated  : Oct 20, 2013                 */
/** fb.com/pranphy<>http://pranphy.wordpress.com */
/*************************************************/

#include "Utility/Mathematical.h"


int Random(int range)
{
    return (rand()%range+1);
}

void initrand(void)
{
    srand((unsigned)time(0));
}

void ConvertDimension(int Height, int Width, float& OldX, float& OldY)
{
    float ScaleX=60;
    float ScaleY=40;
    OldX=(OldX-Height/2)/ScaleX;
    OldY=(Width/2-OldY)/ScaleY;
}


// returns an integer array of random numbers
// the address of array random numbers(consecutive integers)  of length lng from
// lb  to ub (inclusive) is returned. if rpt=TRUE==1 the numbers may be repeated
// and if rpt=FALSE==0 the random numbers are not repeated

int* RandIntArray(int lb,int ub, int lng, int rpt)
{
    initrand();
    int cnt=0,num;
    int *ary = new int[lng];
    for(; cnt<lng; cnt++)
    {
        if(!rpt)
        {
            do
            {
                num=Random(ub-lb+1)-1+lb;
            }
            while(ChkNumInAry(num,lng,ary));
        }
        else
        {
            num=Random(ub-lb+1)-1+lb;
        }
        *(ary+cnt)=num;
    }
    return ary;
}


int ChkNumInAry(int num,int lng, int *ary)   // check whether num exists in the array of length lng with array base address ary
{
    int cnt=0,flag=0;
    for(; cnt<lng; cnt++)
    {
        if(*(ary+cnt)==num)
        {
            flag=1;
            break;
        }
    }
    return flag;
}




template <class t>
void Swap(t&a,t&b)
{
    t c;
    c=a;
    a=b;
    b=c;
}
