#pragma once
namespace CppCLRWinFormsProject
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class RoomSearchScreen : UserControl
    {
    public:
        RoomSearchScreen() {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~RoomSearchScreen()
        {
            if (components)
            {
                delete components;
            }
        }

    protected:
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
            // RoomSearchScreen
            // 
            this->BackColor = System::Drawing::SystemColors::Control;
            this->Name = L"RoomSearchScreen";
            this->Size = System::Drawing::Size(800, 600);
            this->ResumeLayout(false);

        }
    };
}
