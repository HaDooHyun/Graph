//
// Created by hadoo on 18. 11. 8.
//

#ifndef WXGRAPH_DRAWPANEL_HPP
#define WXGRAPH_DRAWPANEL_HPP

#include <wx/wx.h>

double const DEFAULT_XMIN  =  0;
double const DEFAULT_XSTEP =  1;
//double const DEFAULT_XMAX  = 10;
double const DEFAULT_YMIN  =  0;
double const DEFAULT_YSTEP =  1;
//double const DEFAULT_YMAX  = 10;

class DrawPanel : public wxPanel
{
private:
    struct LINE {
        int min  =  0;
        int step =  1;
        int max  = 10;

        bool show = true;
    };

    struct NAME {
        wxString name = wxT("Default");
        long color = 0x000000;
        wxFont font = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
        bool show = true;
    };

    struct GUIDE {
        double xmin  = DEFAULT_XMIN;
        double xstep = DEFAULT_XSTEP;
        double xmax;
        double ymin  = DEFAULT_YMIN;
        double ystep = DEFAULT_YSTEP;
        double ymax;

        bool show = true;
        long color = 0x000000; // default black.
        wxString xstring = wxT("X name");
        wxString ystring = wxT("Y name");
    };

private:
    LINE _x_line;
    NAME _x_name;
    LINE _y_line;
    NAME _y_name;
    GUIDE _guide;
    wxRect _draw_zone;
    long   _draw_zone_color = 0x888888;
    double _x_text = 0;
    double _y_text = 0;

public:
    wxDECLARE_EVENT_TABLE();

public:
    DrawPanel(wxWindow * parent, wxWindowID id, wxPoint const & pos, wxSize const & size, long style);
    virtual ~DrawPanel();

private:
    void init();

public:
    inline void setZoneColor(long color) { _draw_zone_color = color; }

public:
    inline void setXLine(int xmin, int xstep, int xmax, bool show = true)
    { if ((xmax - xmin) % xstep != 0) { std::cout << "step Size error." << std::endl; return; } _x_line.min = xmin; _x_line.step = xstep; _x_line.max = xmax; _x_line.show = show; this->Refresh(); }
    inline void setYLine(int ymin, int ystep, int ymax, bool show = true)
    { if ((ymax - ymin) % ystep != 0) { std::cout << "step Size error." << std::endl; return; } _y_line.min = ymin; _y_line.step = ystep; _y_line.max = ymax; _y_line.show = show; this->Refresh(); }

private:
    void drawZone(wxDC & dc);
    void drawGuide(wxDC & dc);
    void drawXname(wxDC & dc);
    void drawYname(wxDC & dc);

private:
    void onPaint(wxPaintEvent & event);

};

#endif //WXGRAPH_DRAWPANEL_HPP
