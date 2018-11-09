#include <wx/wx.h>
#include <src/wxGraphApp.hpp>

wxIMPLEMENT_WX_THEME_SUPPORT;
IMPLEMENT_APP_NO_MAIN(wxGraphApp)

int main(int argc, char ** argv)
{
    wxDISABLE_DEBUG_SUPPORT();
    return wxEntry(argc, argv);
}
