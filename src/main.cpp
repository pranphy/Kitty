#include <iostream>
#include <GL/glut.h>
#include <time.h>
#include <cstdlib>
#include <cstdio>

#include "Mathematical.h"
#include "ScoresAndDisplays.h"
#include "CardStuffs.h"
#include "common.h"


#define REDBACK    53
#define BLUEBACK   52

using namespace std;

void DrawBoundary();
void WhenKeyIsPressed(unsigned char,int,int );
void WhenSpecialKeysPressed(int,int,int);
void TimerFunc(int);
void ControlWithMouse(int,int,int,int);
void StartDrawing();
void ChangeSize(int,int);
void Render();
void Initialize();
void LoadAllImages();
void ShuffleCards();
void DisplayCards();



namespace
{
    int WindowWidth=1320, WindowHeight=650;
    float Dummy=0.0;
}

namespace
{
    GLuint OnePhoto;
    static int ActiveCard=-1;
    Taas Card[54],tmp;
    GLuint Image[54];
    int Flipped=0, BackId=1;
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WindowWidth, WindowHeight);
    glutCreateWindow("Kitty v1.00");
    glutReshapeFunc(ChangeSize);
    Initialize(); /*For some activities that should be carried only once in each program execution*/

    glutKeyboardFunc(WhenKeyIsPressed);
    glutMouseFunc(ControlWithMouse);
    glutDisplayFunc(Render);
    glutSpecialFunc(WhenSpecialKeysPressed);

    glutTimerFunc(10, TimerFunc, 0);

    glClearColor(1.0f,1.0f,1.0f,2);
    glutMainLoop();
}



void Initialize()
{
    glEnable(GL_DEPTH_TEST);
    LoadAllImages();
    ShuffleCards()   ;

    initrand();
}

void ShuffleCards()
{
    int *Number;
    RandIntArray(1,52,52,&Number,0);
    for(int i=0;i<52;i++)
    {
        Card[i].SetValue(*(Number+i));
        Card[i].SetTexture(Image[*(Number+i)-1]);
    }
    Card[52].SetTexture(Image[52]);
    Card[53].SetTexture(Image[53]);
}
void DisplayCards()
{

    for(int i=0;i<9;i++)
    {
        float x=0,y=0,angle=0;
        x=2.9-i*.7; y=1.1;
        if(i==ActiveCard)
        {
           y+=0.2;
           angle-=5;
        }
        Card[i].SetPostition(x,y);
        Card[i].DrawIt(angle);
    }
    for(int i=9;i<18;i++)
    {
        int cst;
        if(BackId)
            cst=REDBACK;
        else
            cst=BLUEBACK;
        int index= cst*(1-Flipped)+i*(Flipped-0);
        float x=0,y=0,angle=0;
        x=2.9-(i-9)*.7; y=-1.1;
        Card[index].SetPostition(x,y);
        Card[index].DrawIt(angle);
    }
}

void LoadAllImages()
{

    for(int i=0;i<52;i++)
    {
        char imgnm[70];
        sprintf(imgnm,"/home/pranphy/Files/AllCards/Ascending/C%d.bmp",i+1);
        Image[i]=LoadPhoto(imgnm);
    }

    Image[53]=LoadPhoto("./Files/AllCards/Back/RedBack.bmp");
    Image[52]=LoadPhoto("./Files/AllCards/Back/BlueBack.bmp");
}


void Render()
{

    StartDrawing();
    DisplayCards();
    char num[80]; //cout<<"Got here successfully ";cin>>Dummy;
    if(ActiveCard>-1)
        sprintf(num," Selected Card :- %d",ActiveCard+1);
    else
        sprintf(num," No Card Selected Press 1 through  9 to select corresponding card ");

    glColor3f(0.0,0.8,1.0);

    Cout(num,0,.8,-5);
    glColor3f(1.0,1.0,1.0);
    glutSwapBuffers();

}



void StartDrawing(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}



void ChangeSize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 0.2, 200.0);
}



void WhenKeyIsPressed(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            exit(0);
            break;
        case 13:
            ShuffleCards();
            break;
        case '0':
            ActiveCard=-1;
            break;
        case '1':
            ActiveCard=0;
            break;
        case '2':
            ActiveCard=1;
            break;
        case '3':
            ActiveCard=2;
            break;
        case '4':
            ActiveCard=3;
            break;
        case '5':
            ActiveCard=4;
            break;
        case '6':
            ActiveCard=5;
            break;
        case '7':
            ActiveCard=6;
            break;
        case '8':
            ActiveCard=7;
            break;
        case '9':
            ActiveCard=8;
            break;
        case 'r':
            if(!BackId)
                BackId=1;
            else
                BackId=0;
            break;
        case 'f':
        case'F':
            if(!Flipped)
                Flipped=1;
            else
                Flipped=0;

        default:
            break;
    }
    glutPostRedisplay();
}
void WhenSpecialKeysPressed(int key,int x,int y)
{
    switch (key)
    {
        case GLUT_KEY_DOWN:
            ActiveCard=-1;
            break;
        case GLUT_KEY_LEFT:
            if(ActiveCard<8 && ActiveCard>=0)
            {
                tmp=Card[ActiveCard];
                Card[ActiveCard]=Card[ActiveCard+1];
                Card[ActiveCard+1]=tmp;
                ActiveCard++;
            }

            break;
        case GLUT_KEY_RIGHT:
             if(ActiveCard>0)
             {
                 tmp=Card[ActiveCard];
                Card[ActiveCard]=Card[ActiveCard-1];
                Card[ActiveCard-1]=tmp;
                ActiveCard--;
             }
                //Taas tmp(0);

            break;
        case GLUT_KEY_UP:
            ActiveCard=8;
            break;
        default:
            break;
    }
}

/*Mouse handling Skeleton function supplied by GLUT */

void ControlWithMouse(int button, int state, int x, int y)
{
    float xi=static_cast<float>(x),
          yi=static_cast<float>(y);
    ConvertDimension(WindowHeight,WindowWidth,xi,yi);
//    cout<<" xi = "<<xi<< "  i = "<<yi<<endl;
//    cout<<" x   "<<x<<" y   "<<y<<endl;
    switch (button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)

                break;
        case GLUT_MIDDLE_BUTTON:

            if (state == GLUT_DOWN)

                break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)

                break;
        default:
            break;

    }
    glutPostRedisplay();
}


/*The following function is to test the converted coordinates in teh output window  */

void DrawBoundary()
{
    glLoadIdentity();
    glTranslatef(0.0,0.0,-5);
    glColor3f(1.0,0.0,0.0);
    glRectf(-3.19,1.9,3.19,-1.90);//     Base of the wall lying along x axis

}





void TimerFunc(int value)
{
    glutPostRedisplay();
    glutTimerFunc(10, TimerFunc, 0);
}
