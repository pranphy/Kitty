#include "DisplayCanvas.h"

const long DisplayCanvas::ID_DisplayCanvas = wxNewId();
int DisplayCanvas::ActiveCard = -1;



BEGIN_EVENT_TABLE(DisplayCanvas,wxGLCanvas)
    EVT_PAINT(DisplayCanvas::OnPaint)
    EVT_KEY_DOWN(DisplayCanvas::OnKeyPress)
END_EVENT_TABLE()


DisplayCanvas::DisplayCanvas(wxFrame*Parent):
    wxGLCanvas(Parent, ID_DisplayCanvas,  wxDefaultPosition, wxSize(150,100), 0, wxT("GLCanvas"))
{
    int argc = 1;
    char* argv[1] = { wxString((wxTheApp->argv)[0]).char_str() };
    glutInit(&argc,argv);
    //LoadAllImages();
    ShuffleCards();

}

void DisplayCanvas::OnPaint(wxPaintEvent& WXUNUSED(event))
{
    SetCurrent();

    glClearColor(0.0f,0.5f,0.4f,0);
    glClear(GL_COLOR_BUFFER_BIT);
    DrawTriangle();
    Render();
    //DrawCube();
    glFlush();
    SwapBuffers();
}

void DisplayCanvas::OnKeyPress(wxKeyEvent& event)
{
    //wxMessageBox(wxT(" You pressed a key "),wxT("Bravoo "));

    int Key = event.GetUnicodeKey();
    if(Key == 13)
    {
        wxMessageBox(wxT(" You pressed enter "),wxT(" Ain't that great ??"));
    }
    else if (Key >= '1' and Key <= '9')
    {
        ActiveCard = Key - '1';
        //wxMessageBox(wxT("And yo pressed one "),wxT(" that's great "));
    }

    switch(event.GetKeyCode())
    {
    case WXK_LEFT:
        if(ActiveCard<8 && ActiveCard>=0)
        {
            tmp=Card[ActiveCard];
            Card[ActiveCard]=Card[ActiveCard+1];
            Card[ActiveCard+1]=tmp;
            ActiveCard++;
        }
        break;
    case WXK_RIGHT:
        if(ActiveCard>0)
        {
            tmp=Card[ActiveCard];
            Card[ActiveCard]=Card[ActiveCard-1];
            Card[ActiveCard-1]=tmp;
            ActiveCard--;
        }

        break;
    case WXK_UP:
        ActiveCard = 8;
        break;
    case WXK_DOWN:
        ActiveCard = -1;
    default:
        break;

    }

    //SetCurrent();
    //glutPostRedisplay();
    wxPaintEvent Dummy = wxPaintEvent();
    OnPaint(Dummy);
}

void DisplayCanvas::Initialize()
{
}

void DisplayCanvas::DrawTriangle()
{
    glPushMatrix();
    //glClearColor(0.0, 0.0, 0.0, 0.0);
    //
    glViewport(0, 0, (GLint)GetSize().x, (GLint)GetSize().y);
    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
        glColor3ub((GLubyte)255,(GLubyte)0,(GLubyte)0);
        glVertex3f(0.0f,0.5f,0.0f);
        // Green on the right bottom corner
        glColor3ub((GLubyte)0,(GLubyte)255,(GLubyte)0);
        glVertex3f(0.50f,-0.90f,0.0f);
        // Blue on the left bottom corner
        glColor3ub((GLubyte)0,(GLubyte)0,(GLubyte)255);
        glVertex3f(-0.50f, -0.9000f, -0.0f);
    glEnd();
    glPopMatrix();
}


void DisplayCanvas::ShuffleCards()
{
    int *Number=RandIntArray(1,52,52,0);
    for(int i=0; i<52; i++)
    {
        Card[i].SetValue(Number[i]);
        Card[i].SetTexture(Image[Number[i]-1]);
    }
    Card[52].SetTexture(Image[52]);
    Card[53].SetTexture(Image[53]);
}

void DisplayCanvas::DisplayCards()
{

    glViewport(0, 0, (GLint)GetSize().x, (GLint)GetSize().y);

    for(int i=0; i<9; i++)
    {
        glColor3f(1.0,1.0,1.0);
        float x=0,y=0,angle=0;
        x=0.9-i*.22;
        y=0.5;
        if(i==ActiveCard)
        {
            glColor3f(0.5,0.6,0.7);
            y+=0.02;
            angle-=5;
        }
        Card[i].SetPostition(x,y);
        Card[i].DrawIt(angle);
    }

    for(int i=9; i<18; i++)
    {
        int cst;
        float Group=0.0,SaperationIndex=.22;
        if(BackId)
            cst=REDBACK;
        else
            cst=BLUEBACK;
        int index=cst*(1-Flipped)+i*Flipped;
        float x=0.0,y=0.0,angle=0.0;
        x=0.9-(i-9)*SaperationIndex+Group;
        y=-0.5;
        Card[index].SetPostition(x,y);
        Card[index].DrawIt(angle);
    }

}

void DisplayCanvas::LoadAllImages()
{
    //wxMessageBox(wxT("Loading Images"),wxT("Bravo !!"));
    /*
	for(int i=0; i<52; i++)
    {
        ostringstream ImageName;
        ImageName << "./Files/AllCards/Ascending/";
        ImageName<<"C"<<i+1<<".png";
        Image[i]=LoadImage(const_cast<char*>(ImageName.str().c_str()));
        //system("cls");
        //cout<<"Loading ..."<< static_cast<int>(i/52.*100)<<"% completed "<<endl;
    }
	*/
    //Image[REDBACK]=LoadPhoto(const_cast<char*>("/home/pranphy/Files/AllCards/Back/RedBack.bmp"));
    //system("clear");
    //cout<<"Loading ..."<<99<<"% completed "<<endl;
    //Image[BLUEBACK]=LoadPhoto(const_cast<char*>("/home/pranphy/Files/AllCards/Back/BlueBack.bmp"));
    //system("cls");
    //cout<<"Loading ..."<<100<<"% completed "<<endl;
    //wxMessageBox(wxT("Loaded images all "),wxT("Bravooo !! "));
}
/*
SOILTexture DisplayCanvas::LoadSOILImage(string ImageName)
{
	wxMessageBox(wxT(" I am safe until here "),wxT(" Bravoo "));
	SOILTexture Texture;
	Texture.Image = SOIL_load_image(ImageName.c_str(),&Texture.width,&Texture.height,0,SOIL_LOAD_RGB);
	wxMessageBox(wxT(" But alas not here "),wxT(" Bravoo "));
	return Texture;
}
*/

void DisplayCanvas::Render()
{

    DisplayCards();

    glPushMatrix();
    ostringstream Info;
    if(ActiveCard>-1)
        Info<<" Selected Card :- "<<ActiveCard+1;
    else
        Info<<"Press 1 through  9 to select corresponding card ";
    glColor3f(0.0,0.8,1.0);
    Cout(const_cast<char*>(Info.str().c_str()),-.8,0,0); //Printing function
    glPopMatrix();

}

void DisplayCanvas::StartDrawing(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void DisplayCanvas::ChangeSize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 0.2, 200.0);
}

void DisplayCanvas::WhenKeyIsPressed(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 27:
        exit(0);
        break;
    case 13:
        ShuffleCards();
        Scrambled=1;
        //Flipped=0;
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
        break;
    case 'u':
        if(Scrambled)
        {
            Scrambled=0;
            Arrange(Card,Image);
        }
        break;

    default:
        break;
    }
    glutPostRedisplay();
}

void DisplayCanvas::WhenSpecialKeysPressed(int key,int x,int y)
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

        break;
    case GLUT_KEY_UP:
        ActiveCard=8;
        break;
    default:
        break;
    }
}


void DisplayCanvas::TimerFunc(int value)
{
    glutPostRedisplay();
    //glutTimerFunc(10, TimerFunc, 0);
}


void DisplayCanvas::DrawCube()
{
    glBegin(GL_QUADS);
    glNormal3f( 0.0f, 0.0f, 1.0f);
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f,-0.5f, 0.5f);
    glVertex3f( 0.5f,-0.5f, 0.5f);
    glNormal3f( 0.0f, 0.0f,-1.0f);
    glVertex3f(-0.5f,-0.5f,-0.5f);
    glVertex3f(-0.5f, 0.5f,-0.5f);
    glVertex3f( 0.5f, 0.5f,-0.5f);
    glVertex3f( 0.5f,-0.5f,-0.5f);
    glNormal3f( 0.0f, 1.0f, 0.0f);
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glVertex3f( 0.5f, 0.5f,-0.5f);
    glVertex3f(-0.5f, 0.5f,-0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glNormal3f( 0.0f,-1.0f, 0.0f);
    glVertex3f(-0.5f,-0.5f,-0.5f);
    glVertex3f( 0.5f,-0.5f,-0.5f);
    glVertex3f( 0.5f,-0.5f, 0.5f);
    glVertex3f(-0.5f,-0.5f, 0.5f);
    glNormal3f( 1.0f, 0.0f, 0.0f);
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glVertex3f( 0.5f,-0.5f, 0.5f);
    glVertex3f( 0.5f,-0.5f,-0.5f);
    glVertex3f( 0.5f, 0.5f,-0.5f);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f,-0.5f,-0.5f);
    glVertex3f(-0.5f,-0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f,-0.5f);
    glEnd();
}
