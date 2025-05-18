#include "pch.h"
#include <msclr/marshal_cppstd.h>
#include <string>
#include "room_search_screen.h"
#include "iroom.h"
#include "TVector.h"

System::Void CppCLRWinFormsProject::RoomSearchScreen::saerch_button_Click(System::Object^ sender, System::EventArgs^ e) {
    search_result_panel->Controls->Clear();
    result_label->Text = "Results:";
    std::string category = msclr::interop::marshal_as<std::string>(category_text_box->Text);
    std::string state = msclr::interop::marshal_as<std::string>(state_text_box->Text);
    std::string number = msclr::interop::marshal_as<std::string>(number_text_box->Text);
    std::string beds_count = msclr::interop::marshal_as<std::string>(beds_count_text_box->Text);


    if (_search_result != nullptr) {
        for (int i = 0; i < _search_result->size(); i++) {
            delete(*_search_result)[i];
        }

        delete _search_result;
    }

    _search_result = _rooms->find(number, "", beds_count, state);

    if (_search_result->size() == 0) {
        result_label->Text = "No results";        
        return;
    }

    for (int i = 0; i < _search_result->size(); i++)
    {
        IRoom* found_room = (*_search_result)[i];
        Panel^ found_room_panel = gcnew Panel();
        found_room_panel->Size = System::Drawing::Size(200, 35);
        found_room_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

        Label^ found_room_label = gcnew Label();
        System::String^ number = msclr::interop::marshal_as<System::String^>(found_room->number());
        found_room_label->Text = number;
        found_room_label->AutoSize = true;
        found_room_label->Location = System::Drawing::Point(10, 10);

        Button^ go_button = gcnew Button();
        go_button->Text = "Go to room";
        go_button->Location = System::Drawing::Point(100, 5);
        go_button->Tag = i;
        go_button->Click += gcnew EventHandler(this, &RoomSearchScreen::go_to_button_Click);
        go_button->Click += gcnew EventHandler(this, &RoomSearchScreen::clear_screen);

        found_room_panel->Controls->Add(found_room_label);
        found_room_panel->Controls->Add(go_button);

        search_result_panel->Controls->Add(found_room_panel);
    }
}

System::Void CppCLRWinFormsProject::RoomSearchScreen::go_to_button_Click(System::Object^ sender, System::EventArgs^ e) {
    Button^ button = (Button^)sender;
    int index = (int)button->Tag;
    _parent->ShowRoomScreen((*_search_result)[index]);
}
