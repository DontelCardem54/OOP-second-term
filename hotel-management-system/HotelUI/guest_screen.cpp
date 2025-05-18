#include "pch.h"

#include "guest_screen.h"
#include <msclr/marshal_cppstd.h>
#include <string>

System::Void CppCLRWinFormsProject::GuestScreen::set_guest(IGuest* guest) {
    _guest = guest;
    fill_screen();
}

System::Void CppCLRWinFormsProject::GuestScreen::save_changes() {
    if (_is_passport_changed) {
        std::string passport = msclr::interop::marshal_as<std::string>(passport_text_box->Text);
        _guest->change_passport(passport);
        _is_passport_changed = false;
    }

    if (_is_name_changed) {
        std::string name = msclr::interop::marshal_as<std::string>(name_text_box->Text);
        _guest->change_name(name);
        _is_name_changed = false;
    }

    if (_is_surname_changed) {
        std::string surname = msclr::interop::marshal_as<std::string>(surname_text_box->Text);
        _guest->change_surname(surname);
        _is_surname_changed = false;
    }

    if (_is_patronymic_changed) {
        std::string patronymic = msclr::interop::marshal_as<std::string>(patronymic_text_box->Text);
        _guest->change_patronymic(patronymic);
        _is_patronymic_changed = false;
    }

    if (_is_email_changed) {
        std::string email = msclr::interop::marshal_as<std::string>(email_text_box->Text);
        _guest->change_email(email);
        _is_email_changed = false;
    }

    if (_is_birth_date_changed) {
        System::String^ date = birth_date_time_picker->Text;
        std::string birth_date = msclr::interop::marshal_as<std::string>(date);
        _guest->change_birth_date(birth_date);
        _is_birth_date_changed = false;
    }

    _has_unsaved_changes = false;
}

System::Void CppCLRWinFormsProject::GuestScreen::fill_screen() {
    System::String^ passport = msclr::interop::marshal_as<System::String^>(_guest->passport());
    System::String^ name = msclr::interop::marshal_as<System::String^>(_guest->name());
    System::String^ surname = msclr::interop::marshal_as<System::String^>(_guest->surname());
    System::String^ patronymic = msclr::interop::marshal_as<System::String^>(_guest->patronymic());
    System::String^ birth_date = msclr::interop::marshal_as<System::String^>(_guest->birth_date());
    System::String^ email = msclr::interop::marshal_as<System::String^>(_guest->email());

    passport_text_box->Text = passport;
    name_text_box->Text = name;
    surname_text_box->Text = surname;
    patronymic_text_box->Text = patronymic;
    birth_date_time_picker->Value = DateTime::ParseExact(birth_date, "dd.MM.yyyy", nullptr);
    email_text_box->Text = email;
}
