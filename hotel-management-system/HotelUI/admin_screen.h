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

    public ref class AdminScreen : UserControl
    {
    private:
        IWindow^ _parent;

    public:
        AdminScreen(IWindow^ parent) : _parent(parent) {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~AdminScreen()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ user_name_label;
    private: System::Windows::Forms::Button^ bookings_button;
    private: System::Windows::Forms::Button^ guests_button;
    private: System::Windows::Forms::Button^ search_room_button;
    private: System::Windows::Forms::Button^ logout_button;
           /// <summary> 
        /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->user_name_label = (gcnew System::Windows::Forms::Label());
            this->bookings_button = (gcnew System::Windows::Forms::Button());
            this->guests_button = (gcnew System::Windows::Forms::Button());
            this->search_room_button = (gcnew System::Windows::Forms::Button());
            this->logout_button = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // user_name_label
            // 
            this->user_name_label->AutoSize = true;
            this->user_name_label->Location = System::Drawing::Point(324, 186);
            this->user_name_label->Name = L"user_name_label";
            this->user_name_label->Size = System::Drawing::Size(153, 13);
            this->user_name_label->TabIndex = 9;
            this->user_name_label->Text = L"ѕользователь: »ванов »ван";
            // 
            // bookings_button
            // 
            this->bookings_button->Location = System::Drawing::Point(347, 328);
            this->bookings_button->Name = L"bookings_button";
            this->bookings_button->Size = System::Drawing::Size(100, 40);
            this->bookings_button->TabIndex = 8;
            this->bookings_button->Text = L"Bookings";
            this->bookings_button->UseVisualStyleBackColor = true;
            this->bookings_button->Click += gcnew System::EventHandler(this, &AdminScreen::bookings_button_Click);
            // 
            // guests_button
            // 
            this->guests_button->Location = System::Drawing::Point(346, 282);
            this->guests_button->Name = L"guests_button";
            this->guests_button->Size = System::Drawing::Size(100, 40);
            this->guests_button->TabIndex = 7;
            this->guests_button->Text = L"Guests";
            this->guests_button->UseVisualStyleBackColor = true;
            this->guests_button->Click += gcnew System::EventHandler(this, &AdminScreen::guests_button_Click);
            // 
            // search_room_button
            // 
            this->search_room_button->Location = System::Drawing::Point(346, 236);
            this->search_room_button->Name = L"search_room_button";
            this->search_room_button->Size = System::Drawing::Size(100, 40);
            this->search_room_button->TabIndex = 6;
            this->search_room_button->Text = L"Room search";
            this->search_room_button->UseVisualStyleBackColor = true;
            this->search_room_button->Click += gcnew System::EventHandler(this, &AdminScreen::search_room_button_Click);
            // 
            // logout_button
            // 
            this->logout_button->Location = System::Drawing::Point(347, 374);
            this->logout_button->Name = L"logout_button";
            this->logout_button->Size = System::Drawing::Size(100, 40);
            this->logout_button->TabIndex = 5;
            this->logout_button->Text = L"Logout";
            this->logout_button->UseVisualStyleBackColor = true;
            // 
            // AdminScreen
            // 
            this->BackColor = System::Drawing::SystemColors::Control;
            this->Controls->Add(this->user_name_label);
            this->Controls->Add(this->bookings_button);
            this->Controls->Add(this->guests_button);
            this->Controls->Add(this->search_room_button);
            this->Controls->Add(this->logout_button);
            this->Name = L"AdminScreen";
            this->Size = System::Drawing::Size(800, 600);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
    private: System::Void search_room_button_Click(System::Object^ sender, System::EventArgs^ e) {
        _parent->ShowRoomSearchScreen();
    }
    private: System::Void guests_button_Click(System::Object^ sender, System::EventArgs^ e) {
        _parent->ShowGuestsScreen();
    }
    private: System::Void bookings_button_Click(System::Object^ sender, System::EventArgs^ e) {
        _parent->ShowBookingsScreen();
    }
};
}
