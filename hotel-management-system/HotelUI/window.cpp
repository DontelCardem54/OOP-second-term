#include "pch.h"
#include "window.h"

void CppCLRWinFormsProject::Window::InitializeScreens() {
    csvguests = new CSVGuests();
    csvrooms = new CSVRooms();
    this->panel_history = (gcnew System::Collections::Generic::Stack<UserControl^>());

    this->admin_screen = (gcnew AdminScreen(this));
    this->Controls->Add(this->add_guest_screen);

    this->add_guest_screen = (gcnew AddGuestScreen(this, csvguests));
    this->Controls->Add(this->add_guest_screen);

    this->guest_screen = (gcnew GuestScreen(this));
    this->Controls->Add(this->guest_screen);

    this->guests_screen = (gcnew GuestsScreen(this));
    this->Controls->Add(this->guests_screen);

    this->guest_search_screen = (gcnew GuestSearchScreen(this, csvguests));
    this->Controls->Add(this->guest_search_screen);

    this->room_search_screen = (gcnew RoomSearchScreen(this, csvrooms));
    this->Controls->Add(this->room_search_screen);

    this->room_screen = (gcnew RoomScreen(this));
    this->Controls->Add(this->room_screen);
}

void CppCLRWinFormsProject::Window::ShowAdminScreen() {
    this->container_panel->Controls->Clear();
    this->container_panel->Controls->Add(this->admin_screen);  
    this->panel_history->Push(this->admin_screen);
}

void CppCLRWinFormsProject::Window::ShowRoomScreen(IRoom* room) {
    room_screen->set_room(room);
    this->container_panel->Controls->Clear();
    this->container_panel->Controls->Add(this->room_screen);
    this->panel_history->Push(this->room_screen);
}

void CppCLRWinFormsProject::Window::ShowRoomSearchScreen() {
    this->container_panel->Controls->Clear();
    this->container_panel->Controls->Add(this->room_search_screen);
    this->panel_history->Push(this->room_search_screen);
}

void CppCLRWinFormsProject::Window::ShowGuestScreen(IGuest* guest) {
    guest_screen->set_guest(guest);
    this->container_panel->Controls->Clear();
    this->container_panel->Controls->Add(this->guest_screen);
    this->panel_history->Push(this->guest_screen);
}

void CppCLRWinFormsProject::Window::ShowGuestsScreen() {
    this->container_panel->Controls->Clear();
    this->container_panel->Controls->Add(this->guests_screen);
    this->panel_history->Push(this->guests_screen);
}

void CppCLRWinFormsProject::Window::ShowGuestSearchScreen() {
    this->container_panel->Controls->Clear();
    this->container_panel->Controls->Add(this->guest_search_screen);
    this->panel_history->Push(this->guest_search_screen);
}

void CppCLRWinFormsProject::Window::ShowAddGuestScreen() {
    this->container_panel->Controls->Clear();
    this->container_panel->Controls->Add(this->add_guest_screen);
    this->panel_history->Push(this->add_guest_screen);
}

void CppCLRWinFormsProject::Window::GoBack() {
    if (this->panel_history->Count > 1)
    {
        this->panel_history->Pop();
        UserControl^ previousPanel = this->panel_history->Peek();
        this->container_panel->Controls->Clear();
        this->container_panel->Controls->Add(previousPanel);
    }
}
