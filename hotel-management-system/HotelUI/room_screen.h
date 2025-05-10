#pragma once
namespace CppCLRWinFormsProject
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class RoomScreen : UserControl
    {
    public:
        RoomScreen() {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~RoomScreen()
        {
            if (components)
            {
                delete components;
            }
        }
        /// <summary> 
        /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->SuspendLayout();
            // 
            // BookingPanel
            // 
            this->BackColor = System::Drawing::SystemColors::Control;
            this->Name = L"RoomScreen";
            this->Size = System::Drawing::Size(800, 600);
            this->ResumeLayout(false);

        }
    };
}
