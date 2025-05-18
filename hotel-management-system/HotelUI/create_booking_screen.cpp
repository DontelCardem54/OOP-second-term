#include "pch.h"
#include "create_booking_screen.h"
#include <msclr/marshal_cppstd.h>
#include <string>

System::Void CppCLRWinFormsProject::CreateBookingScreen::create_button_Click(System::Object^ sender, System::EventArgs^ e) {
    System::String^ date = start_date_time_picker->Text;
    std::string start_date = msclr::interop::marshal_as<std::string>(date);
    date = end_date_time_picker->Text;
    std::string end_date = msclr::interop::marshal_as<std::string>(date);
    std::string guest_passport = msclr::interop::marshal_as<std::string>(guest_passport_text_box->Text);
    std::string room_number = msclr::interop::marshal_as<std::string>(room_number_text_box->Text);
    std::string employe_passport = msclr::interop::marshal_as<std::string>(staff_passport_text_box->Text);

    if (!check_dates(start_date_time_picker->Text, end_date_time_picker->Text)) {
        return;
    }

    IGuest* guest = _guests->get_by_passport(guest_passport);

    if (guest == nullptr) {
        MessageBox::Show(this, "Guest not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    IRoom* room = _rooms->get_by_room_number(room_number);

    if (room == nullptr) {
        MessageBox::Show(this, "Room not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        delete guest;
        return;
    }


    try {
        if (_current_booking != nullptr) {
            delete _current_booking;
        }

        _current_booking = _bookings->add(start_date, end_date, guest->id(), room->id(), employe_passport);
    }
    catch (const std::exception& ex) {
        MessageBox::Show(this,
            msclr::interop::marshal_as< System::String^>(ex.what()),
            "Input error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Error
        );

        delete guest;
        delete room;
        return;
    }

    disable_fields();
    delete guest;
    delete room;
}
