/**************************************************
 ** Author        : @PrakashGautam               **
 ** First Written : Dec 30, 2012                 **
 ** Last Updated  : Oct 28, 2013, May 3, 2015    **
 ** fb.com/pranphy<>http://pranphy.wordpress.com **
 **************************************************/

#include "Base/Taas.h"
#include <algorithm>


Taas::Taas(unsigned num):ID(num)
{
    PositionX=0, PositionY=0;
    //CardTexture=0;
    val_face = get_card(ID);
}

int Taas::get_value()
{
    return card_number;
}

void Taas::set_value(int value)
{
    card_number=value;
    val_face = get_card(ID);
}

void Taas::get_it(int&val,int&Typ)
{
    val=value;
    Typ=type;
}

ValnFace Taas::get_card(unsigned deg)
{
    unsigned fcrd;
    
    CardFace ftyp; ftyp=CardFace::SPADE;
    int cdegn;
    cdegn=deg%13+1;
    if(cdegn==1)
        fcrd=13;
    else
        fcrd=cdegn-1;
    if(deg>=1 && deg <=13)
        ftyp=CardFace::HEART;
    else if(deg>=14 && deg<=26)
        ftyp=CardFace::DIAMOND;
    else if(deg>=27 && deg<=39)
        ftyp=CardFace::CLUB;
    else if(deg>=40 && deg<=52)
        ftyp=CardFace::SPADE;

    return ValnFace{fcrd,ftyp};

}

unsigned Taas::get_id()
{
    return ID;
}

void Taas::set_image(Image imagob)
{
    CardImage = imagob; 
}

void Taas::set_postition(float x,float y)
{
    PositionX=x;
    PositionY=y;
}


