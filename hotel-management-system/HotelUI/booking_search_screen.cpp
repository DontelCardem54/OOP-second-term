#include "pch.h"
#include "booking_search_screen.h"
#include <msclr/marshal_cppstd.h>
#include <string>
#include "ibooking.h"
#include "TVector.h"

System::Void CppCLRWinFormsProject::BookingSearchScreen::saerch_button_Click(System::Object^ sender, System::EventArgs^ e) {
    search_result_panel->Controls->Clear();
    result_label->Text = "Results:";
    std::string start_date = msclr::interop::marshal_as<std::string>(start_date_time_picker->Text);
    std::string end_date = msclr::interop::marshal_as<std::string>(end_date_time_picker->Text);
    std::string room_number = msclr::interop::marshal_as<std::string>(room_number_text_box->Text);
    std::string guest_passport = msclr::interop::marshal_as<std::string>(guest_passport_text_box->Text);


    if (_search_result != nullptr) {
        for (int i = 0; i < _search_result->size(); i++) {
            delete(*_search_result)[i];
        }

        delete _search_result;
    }

    _search_result = _bookings->find(start_date, end_date, guest_passport, room_number);

    if (_search_result->size() == 0) {
        result_label->Text = "No results";
        return;
    }

    for (int i = 0; i < _search_result->size(); i++)
    {
        IBooking* found_booking = (*_search_result)[i];
        Panel^ found_booking_panel = gcnew Panel();
        found_booking_panel->Size = System::Drawing::Size(300, 35);
        found_booking_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

        IGuest* guest = _guests->get_by_id(found_booking->guest_id());

        Label^ found_booking_label = gcnew Label();
        System::String^ guest_name = msclr::interop::marshal_as<System::String^>("Booking for guest: " + guest->name() + " " + guest->surname() + " " + guest->patronymic());
        found_booking_label->Text = guest_name;
        found_booking_label->AutoSize = true;
        found_booking_label->Location = System::Drawing::Point(10, 10);

        Button^ go_button = gcnew Button();
        go_button->Text = "Go to booking";
        go_button->Location = System::Drawing::Point(200, 5);
        go_button->Tag = i;
        go_button->Click += gcnew EventHandler(this, &BookingSearchScreen::go_to_button_Click);
        go_button->Click += gcnew EventHandler(this, &BookingSearchScreen::clear_screen);

        found_booking_panel->Controls->Add(found_booking_label);
        found_booking_panel->Controls->Add(go_button);

        search_result_panel->Controls->Add(found_booking_panel);

        delete guest;
    }
}

System::Void CppCLRWinFormsProject::BookingSearchScreen::go_to_button_Click(System::Object^ sender, System::EventArgs^ e) {
    Button^ button = (Button^)sender;
    int index = (int)button->Tag;
    _parent->ShowBookingScreen((*_search_result)[index]);
}
