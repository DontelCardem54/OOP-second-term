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
}
