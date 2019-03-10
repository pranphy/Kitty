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




template <class t>
void Swap(t&a,t&b)
{
    t c;
    c=a;
    a=b;
    b=c;
}
