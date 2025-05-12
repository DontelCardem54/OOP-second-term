#pragma once
#include "iwindow.h"

namespace CppCLRWinFormsProject
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class GuestsScreen : UserControl
    {
    private:
        IWindow^ _parent;

    public:
        GuestsScreen(IWindow^ parent) : _parent(parent) {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~GuestsScreen()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ back_button;
    protected:
    private: System::Windows::Forms::Button^ search_guest_button;
    private: System::Windows::Forms::Button^ add_guest_button;
           /// <summary> 
        /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->search_guest_button = (gcnew System::Windows::Forms::Button());
            this->add_guest_button = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(346, 329);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(109, 39);
            this->back_button->TabIndex = 5;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            this->back_button->Click += gcnew System::EventHandler(this, &GuestsScreen::back_button_Click);
            // 
            // search_guest_button
            // 
            this->search_guest_button->Location = System::Drawing::Point(347, 280);
            this->search_guest_button->Name = L"search_guest_button";
            this->search_guest_button->Size = System::Drawing::Size(108, 43);
            this->search_guest_button->TabIndex = 4;
            this->search_guest_button->Text = L"Search Guest";
            this->search_guest_button->UseVisualStyleBackColor = true;
            // 
            // add_guest_button
            // 
            this->add_guest_button->Location = System::Drawing::Point(347, 232);
            this->add_guest_button->Name = L"add_guest_button";
            this->add_guest_button->Size = System::Drawing::Size(108, 42);
            this->add_guest_button->TabIndex = 3;
            this->add_guest_button->Text = L"Add Guest";
            this->add_guest_button->UseVisualStyleBackColor = true;
            this->add_guest_button->Click += gcnew System::EventHandler(this, &GuestsScreen::add_guest_button_Click);
            // 
            // GuestsScreen
            // 
            this->BackColor = System::Drawing::SystemColors::Control;
            this->Controls->Add(this->back_button);
            this->Controls->Add(this->search_guest_button);
            this->Controls->Add(this->add_guest_button);
            this->Name = L"GuestsScreen";
            this->Size = System::Drawing::Size(800, 600);
            this->ResumeLayout(false);

        }
    private: System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e) {
        _parent->GoBack();
    }
    private: System::Void add_guest_button_Click(System::Object^ sender, System::EventArgs^ e) {
        _parent->ShowAddGuestScreen();
    }
    };
}
