#include "pch.h"
#include <msclr/marshal_cppstd.h>
#include <string>
#include "guest_search_screen.h"
#include "iguest.h"
#include "TVector.h"

System::Void CppCLRWinFormsProject::GuestSearchScreen::saerch_button_Click(System::Object^ sender, System::EventArgs^ e)
{
    search_result_panel->Controls->Clear();
    result_label->Text = "Results:";
    std::string passport = msclr::interop::marshal_as<std::string>(passport_text_box->Text);

    if (passport.length() != 10) {
        MessageBox::Show(this,
            "Passport length should be 10 numbers",
            "Input Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Error);
            return;
    }

    for (char c : passport) {
        if (!std::isdigit(c)) {
            MessageBox::Show(this,
            "Passport should cintain numbers",
            "Input Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Error);
            return;
        }
    }

    if (_search_result != nullptr) {
        for (int i = 0; i < _search_result->size(); i++) {
            delete(*_search_result)[i];
        }

        delete _search_result;
    }

    _search_result = _guests->find(passport);

    if (_search_result->size() == 0) {
        result_label->Text = "No results";
        Button^ add_button = gcnew Button();
        add_button->Text = "Add Guest";
        add_button->Location = System::Drawing::Point(100, 5);
        add_button->Click += gcnew EventHandler(this, &GuestSearchScreen::add_guest_button_Click);
        search_result_panel->Controls->Add(add_button);
        return;
    }

    for (int i = 0; i < _search_result->size(); i++)
    {
        IGuest* found_guest = (*_search_result)[i];
        Panel^ found_guest_panel = gcnew Panel();
        found_guest_panel->Size = System::Drawing::Size(200, 35);
        found_guest_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

        Label^ found_guest_label = gcnew Label();
        System::String^ name = msclr::interop::marshal_as<System::String^>(found_guest->name());
        found_guest_label->Text = name;
        found_guest_label->AutoSize = true;
        found_guest_label->Location = System::Drawing::Point(10, 10);

        Button^ go_button = gcnew Button();
        go_button->Text = "Go to guest";
        go_button->Location = System::Drawing::Point(100, 5);
        go_button->Tag = i;
        go_button->Click += gcnew EventHandler(this, &GuestSearchScreen::go_to_button_Click);
        go_button->Click += gcnew EventHandler(this, &GuestSearchScreen::clear_screen);

        found_guest_panel->Controls->Add(found_guest_label);
        found_guest_panel->Controls->Add(go_button);

        search_result_panel->Controls->Add(found_guest_panel);
    }
}

System::Void CppCLRWinFormsProject::GuestSearchScreen::go_to_button_Click(System::Object^ sender, System::EventArgs^ e)
{
    Button^ button = (Button^)sender;
    int index = (int)button->Tag;
    _parent->ShowGuestScreen((*_search_result)[index]);
}
