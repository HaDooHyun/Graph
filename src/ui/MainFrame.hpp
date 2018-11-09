//
// Created by hadoo on 18. 11. 8.
//

#ifndef WXGRAPH_MAINFRAME_HPP
#define WXGRAPH_MAINFRAME_HPP

#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
    MainFrame(wxWindow *parent,
              wxWindowID id,
              const wxString& title,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              long style = wxDEFAULT_FRAME_STYLE,
              const wxString& name = wxFrameNameStr);
    virtual ~MainFrame();
};


#endif //WXGRAPH_MAINFRAME_HPP
