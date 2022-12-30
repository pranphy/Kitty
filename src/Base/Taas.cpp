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
    card_number = ID;
    val_face = get_card(ID);
    value = val_face.value;
    type = val_face.face;
}

unsigned Taas::get_value()
{
    return val_face.value;
}

std::string Taas::get_face()
{
    std::string face = "Error";
    switch(val_face.face)
    {
        case CardFace::DIAMOND:
            face = "♦"; break;

        case CardFace::HEART:
            face = "♥"; break;

        case CardFace::CLUB:
            face = "♣"; break;

        case CardFace::SPADE:
            face = "♠"; break;
    }
    return face;
}

std::string Taas::get_symbol()
{
    std::string face = "Error";
    unsigned value = get_value();
    if(value == 13) face = "A";
    else if(value >0 && value <10) face = std::to_string(value + 1 );
    else if(value  == 10) face = "J";
    else if(value  == 11) face = "Q";
    else if(value  == 12) face = "K";
    return face;
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
    int cdegn = deg%13;
    if(cdegn==0)
        fcrd=13;
    else
        fcrd=cdegn;
    if(deg>=0 && deg < 13)
        ftyp=CardFace::HEART;
    else if(deg>=13 && deg<26)
        ftyp=CardFace::DIAMOND;
    else if(deg>=26 && deg<39)
        ftyp=CardFace::CLUB;
    else if(deg>=39 && deg<52)
        ftyp=CardFace::SPADE;

    return ValnFace{fcrd,ftyp};

}

unsigned Taas::get_id()
{
    return ID;
}

void Taas::set_postition(float x,float y)
{
    PositionX=x;
    PositionY=y;
}

std::ostream& operator<<(std::ostream& os,Taas& ts)
{
    os<<ts.get_face()<<" "<<ts.get_symbol()<<"  ";
    return os;
}

