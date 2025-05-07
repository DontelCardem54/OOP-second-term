#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "AdminForm.h"
#include "Hotel.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
    Hotel* hotel = new Hotel();

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    CppCLRWinFormsProject::AdminForm^ admin_form = gcnew CppCLRWinFormsProject::AdminForm(hotel);
    admin_form->Show();
    Application::Run();
    delete hotel;
    return 0;
}