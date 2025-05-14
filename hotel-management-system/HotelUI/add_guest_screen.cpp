#include "pch.h"
#include "add_guest_screen.h"
#include <msclr/marshal_cppstd.h>
#include <string>

System::Void CppCLRWinFormsProject::AddGuestScreen::add_button_Click(System::Object^ sender, System::EventArgs^ e) {
    std::string passport = msclr::interop::marshal_as<std::string>(passport_text_box->Text);
    std::string name = msclr::interop::marshal_as<std::string>(name_text_box->Text);
    std::string surname = msclr::interop::marshal_as<std::string>(surname_text_box->Text);
    std::string patronymic = msclr::interop::marshal_as<std::string>(patronymic_text_box->Text);
    System::String^ date = birth_date_time_picker->Text;
    std::string birth_date = msclr::interop::marshal_as<std::string>(date);
    std::string email = msclr::interop::marshal_as<std::string>(email_text_box->Text);

    try {
        if (_current_guest != nullptr) {
            delete _current_guest;
        }

        _current_guest = _guests->add(passport, name, surname, patronymic, birth_date, email);
    }
    catch (const std::exception& ex){
        MessageBox::Show(this,
            msclr::interop::marshal_as< System::String^>(ex.what()),
            "Ошибка ввода",
            MessageBoxButtons::OK,
            MessageBoxIcon::Error
        );

        return;
    }

    disable_fields();
}
