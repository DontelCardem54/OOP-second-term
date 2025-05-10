#include "pch.h"
#include "window.h"

void CppCLRWinFormsProject::Window::InitializeScreens()
{
    this->panel_history = (gcnew System::Collections::Generic::Stack<UserControl^>());

    this->admin_screen = (gcnew AdminScreen(this));
    this->Controls->Add(this->add_guest_screen);

    this->add_guest_screen = (gcnew AddGuestScreen());
    this->Controls->Add(this->add_guest_screen);

    this->guest_screen = (gcnew GuestScreen());
    this->Controls->Add(this->guest_screen);
}

void CppCLRWinFormsProject::Window::ShowAdminScreen()
{
    this->container_panel->Controls->Clear();
    this->container_panel->Controls->Add(this->admin_screen);  
    this->panel_history->Push(this->admin_screen);
}

void CppCLRWinFormsProject::Window::ShowRoomSearchScreen()
{
    
}
