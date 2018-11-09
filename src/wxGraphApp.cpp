//
// Created by hadoo on 18. 11. 8.
//

#include <src/wxGraphApp.hpp>
#include <src/ui/MainFrame.hpp>

wxGraphApp::wxGraphApp() : wxApp()
{

}

wxGraphApp::~wxGraphApp()
{

}

bool wxGraphApp::OnInit()
{
    MainFrame * frame = new MainFrame(nullptr, wxID_ANY, DEFAULT_TITLE, DEFAULT_POSITION, DEFAULT_SIZE);
    frame->Show();

    return true;
}

