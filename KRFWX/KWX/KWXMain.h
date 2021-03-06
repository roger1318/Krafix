////////////////////////////////////////////////////////////////////////////////
// 
//  Filename: KwxMain.h
// 
//  Contents: Main Graphics window
// 
////////////////////////////////////////////////////////////////////////////////
//  DATE        DESCRIPTION
//  2018-03-30  Initial implementation
////////////////////////////////////////////////////////////////////////////////

#ifndef KWX_MAIN_H
#define KWX_MAIN_H

#if !defined(WXWIN)
#error No Environment Variable 'WXWIN' found for WxWidgets Library!!!
#endif

#include <wx/wx.h>
#include <KxOGLLoader/oglstuff.h>
#include <wx/glcanvas.h>

#pragma warning( disable: 4251 4275 4355 )

// #############################################################################
// Main application
// #############################################################################

class MyApp : public wxApp
{
public:
    bool OnInit() wxOVERRIDE;
};

// #############################################################################
// Main Frame
// #############################################################################

class MyGLCanvas;

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title);

    void OnAbout(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
#if wxUSE_LOGWINDOW
    void OnLogWindow(wxCommandEvent& event);
#endif // wxUSE_LOGWINDOW
    void SetOGLString(const wxString& ogls)
    {
        m_OGLString = ogls;
    }
    bool OGLAvailable();

private:
#if wxUSE_LOGWINDOW
    wxLogWindow* m_LogWin;
#endif // wxUSE_LOGWINDOW
    wxString     m_OGLString;
    MyGLCanvas*  m_mycanvas;

    wxDECLARE_EVENT_TABLE();
};

// #############################################################################
// OpenGL Canvas
// #############################################################################

class MyGLCanvas : public wxGLCanvas
{
public:
    MyGLCanvas(MyFrame* parent, const wxGLAttributes& canvasAttrs);
    ~MyGLCanvas();

    //Used just to know if we must end now because OGL 3.2 isn't available
    bool OglCtxAvailable()
    {
        return m_oglContext != NULL;
    }

    //Init the OpenGL stuff
    bool oglInit();

    void OnPaint(wxPaintEvent& event);
    void OnSize(wxSizeEvent& event);
    void OnMouse(wxMouseEvent& event);

private:
    // Members
    MyFrame*      m_parent;
    wxGLContext*  m_oglContext;
    myOGLManager* m_oglManager;
    int           m_winHeight; // We use this var to know if we have been sized

    wxDECLARE_EVENT_TABLE();
};

// IDs for the controls and the menu commands
enum
{
    Pyramid_Quit = wxID_EXIT,
    Pyramid_About = wxID_ABOUT,
    Pyramid_LogW = wxID_HIGHEST + 10
};

#endif // KWX_MAIN_H