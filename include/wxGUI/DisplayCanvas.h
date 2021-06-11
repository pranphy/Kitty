#ifndef DISPLAYCANVAS_H
#define DISPLAYCANVAS_H

#include <wx/glcanvas.h>
#include <wx/wx.h>
#include <wx/msgdlg.h>
#include <GL/glut.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#include "Utility/Mathematical.h"
#include "Base/ScoresAndDisplays.h"
#include "Base/Game.h"


#define REDBACK    0x34
#define BLUEBACK   0x35
#define MENUMODE   0x36
#define PLAYMODE   0x37



class DisplayCanvas : public wxGLCanvas
{
public:
	DisplayCanvas(wxWindow*,wxGLAttributes&);

	void OnPaint       (wxPaintEvent&);
	void DrawTriangle  ();
	void DrawCube      ();


	void   WhenKeyIsPressed           (unsigned char,int,int);
	void   WhenSpecialKeysPressed     (int,int,int);
	void   TimerFunc                  (int);
	void   ControlWithMouse           (int,int,int,int);
	void   StartDrawing               ();
	void   ChangeSize                 (int,int);
	void   Render                     ();

	void   Initialize                 ();
    GLuint exampletex;


protected:
	DECLARE_EVENT_TABLE()
private:


	//int WindowWidth=800, WindowHeight=600;
	wxGLContext* MyContext;
    Game KittyGame;
    wxGLContextAttrs cxtAttrs;


	static const long ID_DisplayCanvas;
	void OnKeyPress(wxKeyEvent&);
	GLuint LoadImageFile(string);
};

#endif // DISPLAYCANVAS_H
