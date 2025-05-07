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
    /// Summary for CreateBookingForm
    /// </summary>
    public ref class CreateBookingForm : public System::Windows::Forms::Form
    {
    private:
        Hotel* _hotel;

    public:
        CreateBookingForm(Hotel* hotel) : _hotel(hotel)
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
        ~CreateBookingForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ create_button;
    private: System::Windows::Forms::Label^ start_date_label;
    private: System::Windows::Forms::Label^ end_date_label;
    private: System::Windows::Forms::Label^ guest_passport_label;
    private: System::Windows::Forms::Label^ staff_passport_label;
    private: System::Windows::Forms::Label^ room_number_label;
    protected:







    private: System::Windows::Forms::TextBox^ name_text_box;
    private: System::Windows::Forms::TextBox^ surname_text_box;
    private: System::Windows::Forms::TextBox^ patronymic_text_box;
    private: System::Windows::Forms::TextBox^ passport_text_box;
    private: System::Windows::Forms::TextBox^ birth_date_text_box;

    private: System::Windows::Forms::Button^ back_button;
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
            this->create_button = (gcnew System::Windows::Forms::Button());
            this->start_date_label = (gcnew System::Windows::Forms::Label());
            this->end_date_label = (gcnew System::Windows::Forms::Label());
            this->guest_passport_label = (gcnew System::Windows::Forms::Label());
            this->staff_passport_label = (gcnew System::Windows::Forms::Label());
            this->room_number_label = (gcnew System::Windows::Forms::Label());
            this->name_text_box = (gcnew System::Windows::Forms::TextBox());
            this->surname_text_box = (gcnew System::Windows::Forms::TextBox());
            this->patronymic_text_box = (gcnew System::Windows::Forms::TextBox());
            this->passport_text_box = (gcnew System::Windows::Forms::TextBox());
            this->birth_date_text_box = (gcnew System::Windows::Forms::TextBox());
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // create_button
            // 
            this->create_button->Location = System::Drawing::Point(21, 206);
            this->create_button->Name = L"create_button";
            this->create_button->Size = System::Drawing::Size(100, 40);
            this->create_button->TabIndex = 0;
            this->create_button->Text = L"Create";
            this->create_button->UseVisualStyleBackColor = true;
            // 
            // start_date_label
            // 
            this->start_date_label->AutoSize = true;
            this->start_date_label->Location = System::Drawing::Point(38, 41);
            this->start_date_label->Name = L"start_date_label";
            this->start_date_label->Size = System::Drawing::Size(56, 13);
            this->start_date_label->TabIndex = 1;
            this->start_date_label->Text = L"Start date:";
            // 
            // end_date_label
            // 
            this->end_date_label->AutoSize = true;
            this->end_date_label->Location = System::Drawing::Point(38, 71);
            this->end_date_label->Name = L"end_date_label";
            this->end_date_label->Size = System::Drawing::Size(56, 13);
            this->end_date_label->TabIndex = 2;
            this->end_date_label->Text = L"End date: ";
            // 
            // guest_passport_label
            // 
            this->guest_passport_label->AutoSize = true;
            this->guest_passport_label->Location = System::Drawing::Point(21, 104);
            this->guest_passport_label->Name = L"guest_passport_label";
            this->guest_passport_label->Size = System::Drawing::Size(81, 13);
            this->guest_passport_label->TabIndex = 3;
            this->guest_passport_label->Text = L"Guest passport:";
            // 
            // staff_passport_label
            // 
            this->staff_passport_label->AutoSize = true;
            this->staff_passport_label->Location = System::Drawing::Point(26, 134);
            this->staff_passport_label->Name = L"staff_passport_label";
            this->staff_passport_label->Size = System::Drawing::Size(78, 13);
            this->staff_passport_label->TabIndex = 0;
            this->staff_passport_label->Text = L"Staff passport: ";
            // 
            // room_number_label
            // 
            this->room_number_label->AutoSize = true;
            this->room_number_label->Location = System::Drawing::Point(26, 164);
            this->room_number_label->Name = L"room_number_label";
            this->room_number_label->Size = System::Drawing::Size(76, 13);
            this->room_number_label->TabIndex = 4;
            this->room_number_label->Text = L"Room number:";
            // 
            // name_text_box
            // 
            this->name_text_box->Location = System::Drawing::Point(108, 41);
            this->name_text_box->Name = L"name_text_box";
            this->name_text_box->Size = System::Drawing::Size(120, 20);
            this->name_text_box->TabIndex = 6;
            // 
            // surname_text_box
            // 
            this->surname_text_box->Location = System::Drawing::Point(108, 71);
            this->surname_text_box->Name = L"surname_text_box";
            this->surname_text_box->Size = System::Drawing::Size(120, 20);
            this->surname_text_box->TabIndex = 7;
            // 
            // patronymic_text_box
            // 
            this->patronymic_text_box->Location = System::Drawing::Point(108, 101);
            this->patronymic_text_box->Name = L"patronymic_text_box";
            this->patronymic_text_box->Size = System::Drawing::Size(120, 20);
            this->patronymic_text_box->TabIndex = 8;
            // 
            // passport_text_box
            // 
            this->passport_text_box->Location = System::Drawing::Point(108, 131);
            this->passport_text_box->Name = L"passport_text_box";
            this->passport_text_box->Size = System::Drawing::Size(120, 20);
            this->passport_text_box->TabIndex = 9;
            // 
            // birth_date_text_box
            // 
            this->birth_date_text_box->Location = System::Drawing::Point(108, 161);
            this->birth_date_text_box->Name = L"birth_date_text_box";
            this->birth_date_text_box->Size = System::Drawing::Size(120, 20);
            this->birth_date_text_box->TabIndex = 10;
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(139, 206);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(106, 40);
            this->back_button->TabIndex = 12;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            // 
            // CreateBookingForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(269, 265);
            this->Controls->Add(this->back_button);
            this->Controls->Add(this->birth_date_text_box);
            this->Controls->Add(this->passport_text_box);
            this->Controls->Add(this->patronymic_text_box);
            this->Controls->Add(this->surname_text_box);
            this->Controls->Add(this->name_text_box);
            this->Controls->Add(this->room_number_label);
            this->Controls->Add(this->start_date_label);
            this->Controls->Add(this->staff_passport_label);
            this->Controls->Add(this->end_date_label);
            this->Controls->Add(this->guest_passport_label);
            this->Controls->Add(this->create_button);
            this->Name = L"CreateBookingForm";
            this->Text = L"Create Booking";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
};
}