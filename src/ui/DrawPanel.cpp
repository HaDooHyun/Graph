//
// Created by hadoo on 18. 11. 8.
//

#include <wx/dcbuffer.h>
#include <src/ui/DrawPanel.hpp>

wxBEGIN_EVENT_TABLE(DrawPanel, wxPanel)
    EVT_PAINT(DrawPanel::onPaint)
wxEND_EVENT_TABLE()

DrawPanel::DrawPanel(wxWindow *parent, wxWindowID id, wxPoint const &pos, wxSize const &size, long style)
         : wxPanel(parent, id, pos, size, style)
{
    init();
}

DrawPanel::~DrawPanel()
{

}

void DrawPanel::init()
{

}

void DrawPanel::drawZone(wxDC & dc)
{
    _draw_zone.x = this->GetSize().GetWidth() / 8;
    _draw_zone.y = this->GetSize().GetHeight() / 8;
    _draw_zone.width  = _draw_zone.x * 6;
    _draw_zone.height = _draw_zone.y * 6;
    dc.SetPen(wxPen(_draw_zone_color, 1));
    dc.SetBrush(wxBrush(_draw_zone_color));
    dc.DrawRectangle(_draw_zone);

    _guide.ymin = (double)_draw_zone.height + _draw_zone.y;
    _guide.ymax = _draw_zone.y;
    _guide.xmin = _draw_zone.x;
    _guide.xmax = (double)_draw_zone.width + _draw_zone.x;
    _guide.xstep = (_guide.xmax - _guide.xmin) / (double)((_x_line.max - _x_line.min) / _x_line.step);
    _guide.ystep = (_guide.ymin - _guide.ymax) / (double)((_y_line.max - _y_line.min) / _y_line.step);
    std::cout << "g.x : " << _guide.xstep << " g.y : " << _guide.ystep << std::endl;
}

void DrawPanel::drawGuide(wxDC & dc)
{
    if (!_guide.show) {
        return;
    }
    dc.SetPen(wxPen(_guide.color, 1));
    dc.SetBrush(*wxTRANSPARENT_BRUSH);

    wxRealPoint y_point_1(_guide.xmin, _guide.ymax);
    wxRealPoint y_point_2(_guide.xmin, _guide.ymin);
    wxRealPoint y_move_point = y_point_2;
    wxRealPoint x_point_1(_guide.xmin, _guide.ymin);
    wxRealPoint x_point_2(_guide.xmax, _guide.ymin);
    wxRealPoint x_move_point = x_point_1;
    dc.DrawLine(y_point_1, y_point_2);
    dc.DrawLine(x_point_1, x_point_2);

    int x_lines = std::abs(x_point_2.x - x_point_1.x) / _guide.xstep;
    int y_lines = std::abs(y_point_2.y - y_point_1.y) / _guide.ystep;
    std::cout << " x : " << x_lines << " y : " << y_lines << std::endl;
    for (int i = 0; i < x_lines; ++i) {
        x_move_point.x += _guide.xstep;
        dc.DrawLine(x_move_point, wxRealPoint(x_move_point.x, _guide.ymax));
        wxSize text_size = dc.GetTextExtent(wxString::Format("%g", _x_text));
    }
    for (int i = 0; i < y_lines; ++i) {
        y_move_point.y -= _guide.ystep;
        dc.DrawLine(y_move_point, wxRealPoint(_guide.xmax, y_move_point.y));
    }

}

void DrawPanel::drawXname(wxDC & dc)
{
    if (!_x_name.show) {
        return;
    }
    wxSize text_size = dc.GetTextExtent(_x_name.name);
    dc.SetTextForeground(_x_name.color);
    dc.DrawText(_x_name.name, wxPoint((_guide.xmax - _guide.xmin) / 2 + _guide.xmin - text_size.GetWidth()/2, _guide.ymin + 20));
}

void DrawPanel::drawYname(wxDC & dc)
{
    if (!_y_name.show) {
        return;
    }
    wxSize text_size = dc.GetTextExtent(_y_name.name);
    dc.SetTextForeground(_y_name.color);
    dc.DrawRotatedText(_y_name.name, wxPoint(_guide.xmin - 40, (_guide.ymax - _guide.ymin) / 2 + _guide.ymin + text_size.GetWidth()/2), 90.0);
}

void DrawPanel::onPaint(wxPaintEvent &event)
{
    wxAutoBufferedPaintDC dc(this);
    drawZone(dc);
    drawGuide(dc);
    drawXname(dc);
    drawYname(dc);
}
