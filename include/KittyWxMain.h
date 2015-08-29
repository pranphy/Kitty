/***************************************************************
 * Name:      KittyWxMain.h
 * Purpose:   Defines Application Frame
 * Author:    Prakash Gautam (pranphy@gmail.com)
 * Created:   2015-05-03
 * Copyright: Prakash Gautam (http://pranphy.com/)
 * License:
 **************************************************************/

#ifndef KITTYWXMAIN_H
#define KITTYWXMAIN_H

#include "DisplayCanvas.h"

//(*Headers(KittyWxFrame)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/gbsizer.h>
//*)

class KittyWxFrame: public wxFrame
{
public:

	KittyWxFrame(wxWindow* parent,wxWindowID id = -1);
	virtual ~KittyWxFrame();

private:

	//(*Handlers(KittyWxFrame)
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	//*)

	//(*Identifiers(KittyWxFrame)
	static const long ID_AboutHelpSubItem;
	//*)

	//(*Declarations(KittyWxFrame)
	wxMenuItem* MenuItem1;
	wxMenu* Menu1;
	wxMenuBar* MenuBar1;
	//*)
	DisplayCanvas* KittyCanvas;

	DECLARE_EVENT_TABLE()
};

#endif // KITTYWXMAIN_H
