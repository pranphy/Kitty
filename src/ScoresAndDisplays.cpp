#include "ScoresAndDisplays.h"


void Cout(char *String,float x,float y,float z)
{
	char *CurrentCharacter=String;
	glRasterPos3f(x,y,z);
	for (;*CurrentCharacter!= '\0'; CurrentCharacter++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *CurrentCharacter);
	}
}


Player::Player(char*name,int lives,int scores)
{
    int l=strlen(name);
    Name=new char[l];
    strcpy(Name,name);
    Lives=lives;
    Scores=scores;
}
