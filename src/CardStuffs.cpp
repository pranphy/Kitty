
#include "CardStuffs.h"


Taas::Taas(int num):CardNumber(num)
{
    PositionX=0, PositionY=0;
    CardTexture=0;
    GetCard(CardNumber, Value, Type);
}

void Taas::SetValue(int value)
{
    CardNumber=Value;
    GetCard(CardNumber,Value,Type);
}

void Taas::GetIt(int&val,int&Typ)
{
    val=Value;
    Typ=Type;
}

int Taas::GetNumber()
{
    return CardNumber;
}

void Taas::SetTexture(GLuint text)
{
    CardTexture=text;

}

bool Taas::SetImage(char* imagnam)
{
    CardTexture=LoadPhoto(imagnam);
    if(CardTexture)
        return true;
    else
        return false;
}

void Taas::SetPostition(float x,float y)
{
    PositionX=x;
    PositionY=y;
}
void Taas::DrawIt(float angle)
{
    glLoadIdentity();
    //glTranslatef(0,0,-5);
    glTranslatef(PositionX,PositionY,-5);
    glRotatef(angle,0,0,1);
    glBindTexture(GL_TEXTURE_2D,CardTexture);
    glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glTexCoord3f(1.0f,0.0f,0.0f);           glVertex3f(factor*factorcard*CARD_WIDTH/2,-factor*factorcard*CARD_HEIGHT/2,0);
        glTexCoord3f(1.0f,1.0f,0.0f);           glVertex3f(factor*factorcard*CARD_WIDTH/2,factor*factorcard*CARD_HEIGHT/2,0);
        glTexCoord3f(0.0f,1.0f,0.0f);           glVertex3f(-factor*factorcard*CARD_WIDTH/2,factor*factorcard*CARD_HEIGHT/2,0);
        glTexCoord3f(0.0f,0.0f,0.0f);           glVertex3f(-factor*factorcard*CARD_WIDTH/2,-factor*factorcard*CARD_HEIGHT/2,0);
    glEnd();


}


GLuint LoadPhoto(char* imagename)
{
    cout<< " Searching for >>  "<<imagename;
    GLuint tex_2d = SOIL_load_OGL_texture
    (
        imagename,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    if(!tex_2d)
        cout<< " NotFound "<<endl;
    else
        cout<<" Found. Load Success"<<endl;
    //cls();
    return tex_2d;

}





void GetCard(int deg,int&fcrd,int&ftyp)
{

    int cdegn;
    cdegn=deg%13+1;
    if(cdegn==1)
        fcrd=13;
    else
        fcrd=cdegn-1;
    if(deg>=1 && deg <=13)
        ftyp=SPADE;
    else if(deg>=14 && deg<=26)
        ftyp=CLUB;
    else if(deg>=27 && deg<=39)
        ftyp=HEART;
    else if(deg>=40 && deg<=52)
        ftyp=DIAMOND;

}


 // moves the coursor to the desired position in the console


 //

 int istrial(int a, int b, int c)
{
    return((a==b)&&(b==c));
}


 int isrun(int a, int b, int c)
{
    int m,n,p;
    m=a>b?a-b:b-a;
    n=b>c?b-c:c-b;
    p=a>c?a-c:c-a;
    if(((m==1&&n==1)||(m==1&&p==1)||(n==1&&p==1))&&(a!=b&&b!=c&&c!=a))
        return 1;
    else
        return 0;
}

int whichgreat(int a1, int a2, int a3, int b1,int b2, int b3)
{
    int c;
    c=grtofthree(a1,a2,a3)- grtofthree(b1,b2,b3);
    if (c>0)
        return 1;
    else if (c<0)
        return 2;
    else
    {
        c=sec_grtthree(a1,a2,a3)-sec_grtthree(b1,b2,b3);
        if(c>0)
            return 1;
        else if (c<0)
            return 2;
        else
        {
            c=leastofthree(a1,a2,a3)-leastofthree(b1,b2,b3);
            if(c>0)
                return 1;
            else if(c<0)
                return 2;
            else
                return 0;
        }
    }
}



int grtofthree(int a, int b , int c)
{
    return (a>b? a:b)> c? (a>b?a:b):c;
}


int sec_grtthree(int a, int b, int c)
{
    if(((b-a)>0&&(b-c)<0)||((b-a)<0&&(b-c)>0))
        return b;
    else if (((c-b)>0&&(c-a)<0)||((c-b)<0&&(c-a)>0))
        return c;
    else
        return a;
}



int leastofthree(int a,int b, int c)
{
    return ((a<b?a:b)<c?(a<b?a:b):c);
}


int chkdouble(int a, int b, int c)
{
    if(a==b||b==c||a==c)
        return 1;
    else
        return 0;
}


bool IsColour(int p,int q,int r)
{
    int x,y,z,a,b,c;
    GetCard(p,x,a);
    GetCard(q,y,b);
    GetCard(r,z,c);
    if(isrun(a,b,c))
        return true;
    else
        return false;

}

bool IsDoubleRun(int a,int b,int c)
{
    if(isrun(a,b,c)&&IsColour(a,b,c))
        return true;
    else
        return false;
}
int findcommon(int a, int b, int c)
{
    if(a==b||a==c)
        return a;
    if (b==a||b==c)
        return b;
    else
        return c;
}


int findgrtofcom(int a1, int a2, int a3, int b1, int b2, int b3)
{
    int c;
    c=findcommon(a1,a2,a3)-findcommon(b1,b2,b3);
    if(c>0)
        return 1;
    else if (c<0)
        return 2;
    else
        return 0;
}


int finduncommon(int a, int b, int c)
{
    if(a!=b&&a!=c)
        return a;
    else if (b!=a && b!=c)
        return b;
    else
        return c;
}



int compare(int a1, int a2, int a3, int b1, int b2, int b3)
{
    int a,b,c,d,e,p,q;
    p=istrial(a1,a2,a3);
    q=istrial(b1,b2,b3);
    if (p==1&&q==1)
        {
            if (a1>b1)
                return 1;
            else
                return 2;
        }
    else if (p==1&&q==0)
        return 1;
    else if (p==0&&q==1)
        return 2;
    else
    {
        a=isrun(a1,a2,a3);
        b=isrun(b1,b2,b3);
        if(a==1&&b==1)
        {
            if(grtofthree(a1,a2,a3)>grtofthree(b1,b2,b3))
                return 1;
            else if(grtofthree(a1,a2,a3)<grtofthree(b1,b2,b3))
                return 2;
            else
                return 0;
        }
        else if(a==1&&b==0)
            return 1;
        else if(a==0&&b==1)
            return 2;

        else if (a==0&&b==0)
        {
            c=chkdouble(a1,a2,a3);
            d=chkdouble(b1,b2,b3);
            if(c==1&&d==1)
            {
                e=findgrtofcom(a1,a2,a3,b1,b2,b3);
                if (e==1)
                    return 1;
                else if (e==2)
                    return 2;
                else if (e==0)
                {
                    if (finduncommon(a1,a2,a3)>finduncommon(b1,b2,b3))
                        return 1;
                    else if (finduncommon(a1,a2,a3)<finduncommon(b1,b2,b3))
                        return 2;
                    else if (finduncommon(a1,a2,a3)==finduncommon(b1,b2,b3))
                        return 0;
                }
            }
            else if (c==1&&d==0)
                return 1;
            else if (c==0&&d==1)
                return 2;
            else
                return whichgreat(a1,a2,a3,b1,b2,b3);

        }
    }

}


int winner(int a1, int a2,int a3,int b1,int b2,int b3,int c1,int c2,int c3,int d1,int d2,int d3)
{
    int a,b;
    a=compare(a1,a2,a3,b1,b2,b3);
    b=compare(c1,c2,c3,d1,d2,d3)+2;
    if(a==1&&b==3)
    {
        if (compare(a1,a2,a3,c1,c2,c3)==2)
            return 3;
        else
            return compare(a1,a2,a3,c1,c2,c3);

    }
    else if(a==2&&b==3)
    {
        if (compare(b1,b2,b3,c1,c2,c3)==2)
            return 3;
        else if (compare(b1,b2,b3,c1,c2,c3)==0)
            return 0;
        else
            return 2;
    }
    else if(a==1&&b==4)
    {
        if (compare(a1,a2,a3,d1,d2,d3)==2)
            return 4;
        else
            return (compare(a1,a2,a3,d1,d2,d3));

    }
    else if(a==2&&b==4)
    {
        if (compare(b1,b2,b3,d1,d2,d3)==2)
            return 4;
        else if (compare(b1,b2,b3,d1,d2,d3)==0)
            return 0;
        else
            return 2;
    }
    else if (a==0&&b==3)
    {
        if (compare(a1,a2,a3,c1,c2,c3)==2)
            return 3;
        else
            return 0;
    }
    else if (a==0&&b==4)
    {
        if (compare(a1,a2,a3,d1,d2,d3)==2)
            return 4;
        else
            return 0;
    }
    else if (a==1&&b==0)
    {
        if (compare(a1,a2,a3,c1,c2,c3)==1)
            return 1;
        else
            return 0;
    }
    else if (a==2&&b==0)
    {
        if (compare(b1,b2,b3,c1,c2,c3)==1)
            return 2;
        else
            return 0;
    }
    else if(a==0&&b==0)
        return 0;

    return 0;
}




int rndm(int range) // generate a random integer between 1 and range [inclusive]
{
    return (rand()%range+1);
}
