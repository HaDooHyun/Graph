//
// Created by hadoo on 18. 11. 8.
//

#ifndef WXGRAPH_WXGRAPHAPP_HPP
#define WXGRAPH_WXGRAPHAPP_HPP


#include <wx/wx.h>
class wxGraphApp : public wxApp
{
private:
    wxSize const DEFAULT_SIZE      = wxSize(600, 600);
    wxPoint const DEFAULT_POSITION = wxPoint(0, 0);
    wxString const DEFAULT_TITLE   = wxT("wxGraph - hadoo");

public:
    wxGraphApp();
    virtual ~wxGraphApp();

public:
    virtual bool OnInit();
};

#endif //WXGRAPH_WXGRAPHAPP_HPP
