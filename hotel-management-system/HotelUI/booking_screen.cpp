#include "pch.h"
#include "iguest.h";

#include "booking_screen.h"
#include <msclr/marshal_cppstd.h>
#include <string>

System::Void CppCLRWinFormsProject::BookingScreen::set_booking(IBooking* booking) {
    _booking = booking;
    fill_screen();
}

System::Void CppCLRWinFormsProject::BookingScreen::fill_screen() {
    System::String^ start_date = msclr::interop::marshal_as<System::String^>(_booking->start_date());
    System::String^ end_date = msclr::interop::marshal_as<System::String^>(_booking->end_date());
    start_date_picker->Value = DateTime::ParseExact(start_date, "dd.MM.yyyy", nullptr);
    end_date_picker->Value = DateTime::ParseExact(end_date, "dd.MM.yyyy", nullptr);

    IGuest* guest = _guests->get_by_id(_booking->guest_id());

    System::String^ guest_name = msclr::interop::marshal_as<System::String^>(guest->name());
    System::String^ guest_surname = msclr::interop::marshal_as<System::String^>(guest->surname());
    System::String^ guest_patronymic = msclr::interop::marshal_as<System::String^>(guest->patronymic());
    System::String^ guest_email = msclr::interop::marshal_as<System::String^>(guest->email());

    guest_label->Text = "Guest: " + guest_name + " " + guest_surname + " " + guest_patronymic + ", " + guest_email + ".";

    IRoom* room = _rooms->get_by_id(_booking->room_id());

    System::String^ room_number = msclr::interop::marshal_as<System::String^>(room->number());

    room_label->Text = "Room number: " + room_number + ".";

    delete guest;
    delete room;
}

System::Void CppCLRWinFormsProject::BookingScreen::save_changes() {
    if (_is_start_date_changed) {
        System::String^ date = start_date_picker->Text;
        std::string start_date = msclr::interop::marshal_as<std::string>(date);
        _booking->change_start_date(start_date);
        _is_start_date_changed = false;
    }

    if (_is_end_date_changed) {
        System::String^ date = end_date_picker->Text;
        std::string end_date = msclr::interop::marshal_as<std::string>(date);
        _booking->change_end_date(end_date);
        _is_end_date_changed = false;
    }

    _has_unsaved_changes = false;
}
