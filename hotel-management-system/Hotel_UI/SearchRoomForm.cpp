#include "pch.h"
#include "SearchRoomForm.h"
#include "AdminForm.h"

System::Void CppCLRWinFormsProject::SearchRoomForm::back_button_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();

    AdminForm^ admin_form = gcnew AdminForm(_hotel);
    admin_form->Show();
}
