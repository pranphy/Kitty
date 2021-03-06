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
//#include <wx/msgdlg.h>

#include "SOIL/SOIL.h"


using namespace std;
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


class SOILTexture
{
public:
	unsigned char* Image;
	int width,height;
};


void    GetCard        (int,int&,int&);
float   GetRank        (int*);
float   GetMiniRank    (int,int,int);
/*Generates random number in the range. Look definion on .cpp for more information on this function*/
int*    RandIntArray   (int,int,int,int);
/*checks whether the given number is already among teh array contents*/
int     ChkNumInAry    (int,int, int*);
/*seeds the standard rand function with the current time(in seconds)*/
void    initrand       ();
/*Generates a random integer in the range 0 to (paramater passed)*/
int     Random         (int);
/*Finds teh greatest of three given numbers.*/
int     GreatOfThree   (int,int,int);
/*Function takes 3 integers of which at least two (or possibly all) are equal as arguments and returns one of the equal numbers*/
int     FindCommon     (int,int,int);
int     sec_grtthree   (int,int,int);
int     leastofthree   (int,int,int);
bool    IsTrial        (int,int,int);
bool    IsRun          (int,int,int);
bool    IsDoubleRun    (int,int,int);
bool    IsColour       (int,int,int);
bool    IsJoute        (int,int,int);
int     compare        (int,int,int,int,int,int);
int     rndm           (int);

GLuint  LoadPhoto      (string ImageName);



class Taas
{
public:
	Taas(int=52);
	void SetPostition(float,float);
	void SetTexture(GLuint);
	void SetValue(int);
	void DrawIt(float);
	int CardNumber, Value, Type;

	//pahila yaha private: rakhya thyo ahile hataideko.. naramro programming .. tuk tuk
private:
	float PositionX,PositionY;
	GLuint CardTexture;

	int ConvertToCard(void);
	bool SetImage(char*);
	void GetIt(int&,int&);
	int GetNumber();


};

struct  RankAndArray
{
	int*    IndexArray;
	float*  RankArray;
};


void            Arrange        (Taas*,GLuint*);
int*            ArrangeKitty   (int*);
RankAndArray    MakeRankFile   (int*);
int*            AnalyzeStruct  (RankAndArray*);
void            UpdateTopTen   (short int*,float*);
void            GenerateTopTen (void);
void            DisplayTopTen  (void);


#endif // CARDSTUFFS_H_INCLUDED
