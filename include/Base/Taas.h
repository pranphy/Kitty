/*************************************************/
/** Author        : @PrakashGautam               */
/** First Written : Dec 30, 2012                 */
/** Last Updated  : Oct 28, 2013                 */
/** fb.com/pranphy<>http://pranphy.wordpress.com */
/*************************************************/


#ifndef CARDSTUFFS_H_INCLUDED
#define CARDSTUFFS_H_INCLUDED

#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <wx/msgdlg.h>
#include "wxGUI/Image.h"


enum CardFace{
	SPADE   = 0x03,
	CLUB    = 0x04,
	DIAMOND = 0x05,
	HEART   = 0x06
};

struct ValnFace {
    	unsigned value;
    	CardFace face;
};

/*
*  The following constants correspond to ASCII codes of the corresponding shapes.
*/

//#define SPADE          0x03
//#define CLUB           0x04
//#define DIAMOND        0x05
//#define HEART          0x06

/*
* The follwing factors and dimensions are crude and used just by hit-and-trial
* method. No specific reasons of why exaclty the following values
*/

//#define CARD_WIDTH     0.209
//#define CARD_HEIGHT    0.653
//#define factor         1
//#define factorcard     1


class Taas
{
public:
	Taas(unsigned=1);
	void set_postition(float,float);
	void set_texture(GLuint);
	void set_image(Image);
	void set_value(int);
	int  get_value();
    int  set_value();
	void sraw_it(float);
    ValnFace get_card (unsigned);
	int card_number, value, type;
	unsigned get_id();

    template<typename T>
    void shuffle(std::vector<T> &);

	//pahila yaha private: rakhya thyo ahile hataideko.. naramro programming .. tuk tuk
private:
    unsigned ID;
	float PositionX,PositionY;
    Image CardImage;
    ValnFace val_face;

	int convert_to_card(void);
	bool set_image(std::string);
	void get_it(int&,int&);
};


#endif // CARDSTUFFS_H_INCLUDED
