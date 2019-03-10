/**************************************************
 ** Author        : @PrakashGautam               **
 ** First Written : Dec 30, 2012                 **
 ** Last Updated  : Oct 28, 2013, May 3, 2015    **
 ** fb.com/pranphy<>http://pranphy.wordpress.com **
 **************************************************/

#include "Base/Taas.h"
#include <algorithm>


Taas::Taas(int num):CardNumber(num)
{
    PositionX=0, PositionY=0;
    //CardTexture=0;
    GetCard(CardNumber, Value, Type);
}

int Taas::GetValue()
{
    return CardNumber;
}

void Taas::SetValue(int value)
{
    CardNumber=value;
    GetCard(CardNumber,Value,Type);
}

void Taas::GetIt(int&val,int&Typ)
{
    val=Value;
    Typ=Type;
}

void Taas::GetCard(int deg,int&fcrd,int&ftyp)
{
    int cdegn;
    cdegn=deg%13+1;
    if(cdegn==1)
        fcrd=13;
    else
        fcrd=cdegn-1;
    if(deg>=1 && deg <=13)
        ftyp=HEART;
    else if(deg>=14 && deg<=26)
        ftyp=DIAMOND;
    else if(deg>=27 && deg<=39)
        ftyp=CLUB;
    else if(deg>=40 && deg<=52)
        ftyp=SPADE;
}

int Taas::GetNumber()
{
    return CardNumber;
}

void Taas::SetTexture(GLuint texture)
{
    CardTexture=texture;
}

bool Taas::SetImage(std::string imagnam)
{

    return LoadPhoto(imagnam);

}

void Taas::SetPostition(float x,float y)
{
    PositionX=x;
    PositionY=y;
}


