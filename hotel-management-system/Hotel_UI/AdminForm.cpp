#include "pch.h"
#include "AdminForm.h"
#include "SearchRoomForm.h"

System::Void CppCLRWinFormsProject::AdminForm::search_room_button_Click(System::Object^ sender, System::EventArgs^ e) {
    SearchRoomForm^ search_room_form = gcnew SearchRoomForm(_hotel);
    search_room_form->Show();

    this->Close();
}
