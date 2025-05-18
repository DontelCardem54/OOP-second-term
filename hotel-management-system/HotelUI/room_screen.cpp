#include "pch.h"
#include "room_screen.h"
#include <msclr/marshal_cppstd.h>
#include <string>

System::Void CppCLRWinFormsProject::RoomScreen::set_room(IRoom* room)
{
    _room = room;
    fill_screen();
}

System::Void CppCLRWinFormsProject::RoomScreen::fill_screen()
{
    System::String^ state = msclr::interop::marshal_as<System::String^>(_room->state());
    System::String^ category = msclr::interop::marshal_as<System::String^>(_room->category_name());
    System::String^ number = msclr::interop::marshal_as<System::String^>(_room->number());
    System::String^ beds_count = msclr::interop::marshal_as<System::String^>(_room->beds_count());

    state_label->Text = "State: " + state;
    category_label->Text = "Category: " + category;
    room_number_label->Text = "Number: " + number;
    beds_count_label->Text = "Beds count: " + beds_count;
}
