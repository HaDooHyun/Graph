//
// Created by hadoo on 18. 11. 8.
//

#include <src/ui/MainFrame.hpp>
#include <src/ui/DrawPanel.hpp>

MainFrame::MainFrame(wxWindow *parent, wxWindowID id, const wxString &title,
        const wxPoint &pos, const wxSize &size, long style, const wxString &name)
        : wxFrame(parent, id, title, pos, size, style, name)

{
    DrawPanel * draw_panel = new DrawPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
    draw_panel->setZoneColor(0xFFFFFF);
    draw_panel->setXLine(0, 3, 21);
    wxBoxSizer * vsizer = new wxBoxSizer(wxVERTICAL);
    vsizer->Add(draw_panel, 1, wxEXPAND);
    this->SetSizer(vsizer);
}

MainFrame::~MainFrame()
{

}
