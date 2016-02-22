#ifndef CARDSTUFFS_H_INCLUDED
#define CARDSTUFFS_H_INCLUDED
#include<GL/glut.h>
#include<cstdlib>
#include"common.h"
#include"src/SOIL.h"
#include<iostream>
using namespace std;


#define SPADE          0x1f
#define CLUB           0x2f
#define DIAMOND        0x3f
#define HEART          0x4f

#define CARD_WIDTH     0257
#define CARD_HEIGHT    0353
#define factor         0.01
#define factorcard     0.54

int whichgreat(int,int,int,int,int,int); // compares two suit of cards
int istrial(int, int, int);
int isrun(int,int,int); // given three card number ;; are they run yes returns 1 no returns 0
void GetCard(int,int&,int&); // convert the number into a card
// getcard definition

int grtofthree(int,int,int); // greatest of three numbers
int sec_grtthree(int,int,int);
int chkdouble(int,int,int);
bool IsColour(int,int,int);
bool IsDoubleRun(int,int,int);
int leastofthree(int,int,int);
int findgrtofcom(int,int,int,int,int,int);

int findcommon(int,int,int);
int finduncommon(int,int,int);
int compare(int,int,int,int,int,int);

int winner(int, int, int, int, int, int, int, int, int, int, int, int); // find the winner of four sets of cards

int rndm(int);

GLuint LoadPhoto(char* imagename);


class Taas
{
    private:
        int CardNumber, Value, Type;
        float PositionX,PositionY;
        GLuint CardTexture;
    public:
        Taas(int=52);
        int ConvertToCard(void);
        void SetPostition(float,float);
        void SetTexture(GLuint);
        void SetValue(int);
        bool SetImage(char*);
        void GetIt(int&,int&);
        void DrawIt(float);
        int GetNumber();

};
#endif // CARDSTUFFS_H_INCLUDED
