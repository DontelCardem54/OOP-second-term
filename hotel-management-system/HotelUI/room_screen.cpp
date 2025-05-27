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

    if (_room->is_available()) {
        remove_from_repair_button->Visible = false;
        close_for_repair_button->Visible = true;
        book_room_button->Visible = true;
        guest_label->Visible = false;
        staff_label->Visible = false;
    }
    else if (_room->is_occupied()) {
        remove_from_repair_button->Visible = false;
        close_for_repair_button->Visible = false;
        book_room_button->Visible = false;
        guest_label->Visible = true;
        staff_label->Visible = true;
    }
    else {
        remove_from_repair_button->Visible = true;
        close_for_repair_button->Visible = false;
        book_room_button->Visible = false;
        guest_label->Visible = false;
        staff_label->Visible = false;
    }
}

System::Void CppCLRWinFormsProject::RoomScreen::close_for_repair_button_Click(System::Object^ sender, System::EventArgs^ e) {
    _room->change_state(RoomState::UnderMaintenance);
    remove_from_repair_button->Visible = true;
    close_for_repair_button->Visible = false;
    book_room_button->Visible = false;
    System::String^ state = msclr::interop::marshal_as<System::String^>(_room->state());
    state_label->Text = "State: " + state;
}

System::Void CppCLRWinFormsProject::RoomScreen::remove_from_repair_button_Click(System::Object^ sender, System::EventArgs^ e) {
    _room->change_state(RoomState::Available);
    remove_from_repair_button->Visible = false;
    close_for_repair_button->Visible = true;
    book_room_button->Visible = true;
    System::String^ state = msclr::interop::marshal_as<System::String^>(_room->state());
    state_label->Text = "State: " + state;
}
