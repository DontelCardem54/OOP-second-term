#pragma once

#include "hotel.h"

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for AdminForm
    /// </summary>
    public ref class AdminForm : public System::Windows::Forms::Form
    {
    private:
        Hotel* _hotel;

    public:
        AdminForm(Hotel* hotel) : _hotel(hotel)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~AdminForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ logout_button;
    private: System::Windows::Forms::Button^ search_room_button;
    private: System::Windows::Forms::Button^ guests_button;
    private: System::Windows::Forms::Button^ bookings_button;
    private: System::Windows::Forms::Label^ user_name_label;


    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->logout_button = (gcnew System::Windows::Forms::Button());
            this->search_room_button = (gcnew System::Windows::Forms::Button());
            this->guests_button = (gcnew System::Windows::Forms::Button());
            this->bookings_button = (gcnew System::Windows::Forms::Button());
            this->user_name_label = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // logout_button
            // 
            this->logout_button->Location = System::Drawing::Point(56, 215);
            this->logout_button->Name = L"logout_button";
            this->logout_button->Size = System::Drawing::Size(100, 40);
            this->logout_button->TabIndex = 0;
            this->logout_button->Text = L"Выйти из системы";
            this->logout_button->UseVisualStyleBackColor = true;
            // 
            // search_room_button
            // 
            this->search_room_button->Location = System::Drawing::Point(55, 77);
            this->search_room_button->Name = L"search_room_button";
            this->search_room_button->Size = System::Drawing::Size(100, 40);
            this->search_room_button->TabIndex = 1;
            this->search_room_button->Text = L"Поиск номера";
            this->search_room_button->UseVisualStyleBackColor = true;
            this->search_room_button->Click += gcnew System::EventHandler(this, &AdminForm::search_room_button_Click);
            // 
            // guests_button
            // 
            this->guests_button->Location = System::Drawing::Point(55, 123);
            this->guests_button->Name = L"guests_button";
            this->guests_button->Size = System::Drawing::Size(100, 40);
            this->guests_button->TabIndex = 2;
            this->guests_button->Text = L"Гости";
            this->guests_button->UseVisualStyleBackColor = true;
            // 
            // bookings_button
            // 
            this->bookings_button->Location = System::Drawing::Point(56, 169);
            this->bookings_button->Name = L"bookings_button";
            this->bookings_button->Size = System::Drawing::Size(100, 40);
            this->bookings_button->TabIndex = 3;
            this->bookings_button->Text = L"Брони";
            this->bookings_button->UseVisualStyleBackColor = true;
            // 
            // user_name_label
            // 
            this->user_name_label->AutoSize = true;
            this->user_name_label->Location = System::Drawing::Point(33, 27);
            this->user_name_label->Name = L"user_name_label";
            this->user_name_label->Size = System::Drawing::Size(153, 13);
            this->user_name_label->TabIndex = 4;
            this->user_name_label->Text = L"Пользователь: Иванов Иван";
            // 
            // AdminForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(226, 304);
            this->Controls->Add(this->user_name_label);
            this->Controls->Add(this->bookings_button);
            this->Controls->Add(this->guests_button);
            this->Controls->Add(this->search_room_button);
            this->Controls->Add(this->logout_button);
            this->Name = L"AdminForm";
            this->Text = L"Администратор";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void search_room_button_Click(System::Object^ sender, System::EventArgs^ e);
    };
}