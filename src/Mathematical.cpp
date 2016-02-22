
#include "Mathematical.h"


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


 // creates an array of random numbers

// the random numbers from lb to ub (inclusive) are put into an array  of name adrs
// of length lng, if rpt=TRUE==1 the numbers are repeated and if rpt=FALSE==0 the random numbers arenot repeated
void RandIntArray(int lb,int ub, int lng, int **adrs , int rpt)
{
    initrand();
    int cnt=0,num;
    int *ary = new int[lng];
    for(;cnt<lng;cnt++)
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
        //cout<<cnt<<" I am here "<<num<<endl;
    }
    //cout<<" Finished "<<endl;
    *adrs=ary;
}


int ChkNumInAry(int num,int lng, int *ary) // check whether num exists in the array of length lng with array base address ary
{
    int cnt=0,flag=0;
    for(;cnt<lng;cnt++)
    {
        if(*(ary+cnt)==num)
        {
            flag=1;
            break;
        }
    }
    return flag;
}

void ArrangeKitty(int*Array,int Number)
{
       FILE*fp, *fp2;
       int a[9], rankd;
       fp=fopen("all_combi.txt","r");
       for(int j=0;j<1680;j++)
       {

           for(int i=0;i<9;i++)
           {
               fscanf(fp,"%d",a+i);
           }
           for(int p=0;p<3;p++)
           {
               //Sum+=GenerateRank(*(Array+*(a+3*p)),*(Array+*(a+3*p+1)),*(Array+*(3*p+2)));
            }

       }
}

int GenerateRank(int x,int y,int z)
{
    if(istrial(x,y,z))
        return x*10000;
    else if(IsDoubleRun(x,y,z))
        return grtofthree(x,y,z)*1000;
    else if(isrun(x,y,z))
        return grtofthree(x,y,z)*100;
    else if(chkdouble(x,y,z))
        return findcommon(x,y,z)*10;
    else
        return grtofthree(x,y,z);


}


void RotateObjects(void)
{
    glRotatef(-45,1,0,0);
}



template <class t>
void Swap(t&a,t&b)
{
    t c;
    c=a;
    a=b;
    b=c;
}
