#pragma once

#include <vector>
#include <GL/glut.h>

#include <wx/wx.h>
#include <wx/glcanvas.h>


#include "Base/Game.h"


class DisplayCanvas : public wxGLCanvas
{
public:
	DisplayCanvas(wxWindow*,wxGLAttributes&);


	void   Render                     ();
	void   Initialize                 ();

    GLuint exampletex;

private:

    std::vector<GLuint> all_textures;

	wxGLContext* MyContext;
    wxGLContextAttrs cxtAttrs;


	static const long ID_DisplayCanvas;
    Game KittyGame;

	void OnPaint   (wxPaintEvent&);
	void ChangeSize(wxSizeEvent&);
	void OnKeyPress(wxKeyEvent&);
};

