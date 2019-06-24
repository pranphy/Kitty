#ifndef SCORESANDDISPLAYS_H_INCLUDED
#define SCORESANDDISPLAYS_H_INCLUDED

#include <GL/glut.h>
#include<cstring>

void Cout(char*,float=0,float=0,float=-5);
class Players
{
    private:
        char *Name;
        int Lives, Scores;
    public:
        Players(char*,int=3,int=0);

};



#endif // SCORESANDDISPLAYS_H_INCLUDED
