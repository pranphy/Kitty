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



/*
*  The following constants correspond to ASCII codes of the corresponding shapes.
*/
#define SPADE          0x03
#define CLUB           0x04
#define DIAMOND        0x05
#define HEART          0x06

/*
* The follwing factors and dimensions are crude and used just by hit-and-trial
* method. No specific reasons of why exaclty the following values
*/

#define CARD_WIDTH     0.209
#define CARD_HEIGHT    0.653
#define factor         1
#define factorcard     1


class Taas
{
public:
	Taas(int=52);
	void SetPostition(float,float);
	void SetTexture(GLuint);
	void SetValue(int);
    int GetValue();
	void DrawIt(float);
    void GetCard (int,int&,int&);
	int CardNumber, Value, Type;


	//pahila yaha private: rakhya thyo ahile hataideko.. naramro programming .. tuk tuk
private:
	float PositionX,PositionY;
    Image CardImage;

	int ConvertToCard(void);
	bool SetImage(std::string);
	void GetIt(int&,int&);
	int GetNumber();
};


#endif // CARDSTUFFS_H_INCLUDED
