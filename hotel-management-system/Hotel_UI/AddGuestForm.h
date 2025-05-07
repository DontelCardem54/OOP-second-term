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
    /// Summary for AddGuestForm
    /// </summary>
    public ref class AddGuestForm : public System::Windows::Forms::Form
    {
    private:
        Hotel* _hotel;

    public:
        AddGuestForm(Hotel* hotel) : _hotel(hotel)
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
        ~AddGuestForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ add_button;
    private: System::Windows::Forms::Label^ name_label;
    private: System::Windows::Forms::Label^ surname_label;
    private: System::Windows::Forms::Label^ patronymic_label;
    private: System::Windows::Forms::Label^ passport_label;
    private: System::Windows::Forms::Label^ birth_date_label;
    private: System::Windows::Forms::Label^ email_label;
    private: System::Windows::Forms::TextBox^ name_text_box;
    private: System::Windows::Forms::TextBox^ surname_text_box;
    private: System::Windows::Forms::TextBox^ patronymic_text_box;
    private: System::Windows::Forms::TextBox^ passport_text_box;
    private: System::Windows::Forms::TextBox^ birth_date_text_box;
    private: System::Windows::Forms::TextBox^ email_text_box;
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
            this->add_button = (gcnew System::Windows::Forms::Button());
            this->name_label = (gcnew System::Windows::Forms::Label());
            this->surname_label = (gcnew System::Windows::Forms::Label());
            this->patronymic_label = (gcnew System::Windows::Forms::Label());
            this->passport_label = (gcnew System::Windows::Forms::Label());
            this->birth_date_label = (gcnew System::Windows::Forms::Label());
            this->email_label = (gcnew System::Windows::Forms::Label());
            this->name_text_box = (gcnew System::Windows::Forms::TextBox());
            this->surname_text_box = (gcnew System::Windows::Forms::TextBox());
            this->patronymic_text_box = (gcnew System::Windows::Forms::TextBox());
            this->passport_text_box = (gcnew System::Windows::Forms::TextBox());
            this->birth_date_text_box = (gcnew System::Windows::Forms::TextBox());
            this->email_text_box = (gcnew System::Windows::Forms::TextBox());
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // add_button
            // 
            this->add_button->Location = System::Drawing::Point(24, 242);
            this->add_button->Name = L"add_button";
            this->add_button->Size = System::Drawing::Size(100, 40);
            this->add_button->TabIndex = 0;
            this->add_button->Text = L"Add";
            this->add_button->UseVisualStyleBackColor = true;
            // 
            // name_label
            // 
            this->name_label->AutoSize = true;
            this->name_label->Location = System::Drawing::Point(38, 41);
            this->name_label->Name = L"name_label";
            this->name_label->Size = System::Drawing::Size(41, 13);
            this->name_label->TabIndex = 1;
            this->name_label->Text = L"Name: ";
            // 
            // surname_label
            // 
            this->surname_label->AutoSize = true;
            this->surname_label->Location = System::Drawing::Point(38, 71);
            this->surname_label->Name = L"surname_label";
            this->surname_label->Size = System::Drawing::Size(55, 13);
            this->surname_label->TabIndex = 2;
            this->surname_label->Text = L"Surname: ";
            // 
            // patronymic_label
            // 
            this->patronymic_label->AutoSize = true;
            this->patronymic_label->Location = System::Drawing::Point(38, 101);
            this->patronymic_label->Name = L"patronymic_label";
            this->patronymic_label->Size = System::Drawing::Size(65, 13);
            this->patronymic_label->TabIndex = 3;
            this->patronymic_label->Text = L"Patronymic: ";
            // 
            // passport_label
            // 
            this->passport_label->AutoSize = true;
            this->passport_label->Location = System::Drawing::Point(38, 131);
            this->passport_label->Name = L"passport_label";
            this->passport_label->Size = System::Drawing::Size(54, 13);
            this->passport_label->TabIndex = 0;
            this->passport_label->Text = L"Passport: ";
            // 
            // birth_date_label
            // 
            this->birth_date_label->AutoSize = true;
            this->birth_date_label->Location = System::Drawing::Point(38, 161);
            this->birth_date_label->Name = L"birth_date_label";
            this->birth_date_label->Size = System::Drawing::Size(58, 13);
            this->birth_date_label->TabIndex = 4;
            this->birth_date_label->Text = L"Birth date: ";
            // 
            // email_label
            // 
            this->email_label->AutoSize = true;
            this->email_label->Location = System::Drawing::Point(38, 191);
            this->email_label->Name = L"email_label";
            this->email_label->Size = System::Drawing::Size(38, 13);
            this->email_label->TabIndex = 5;
            this->email_label->Text = L"Email: ";
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
            // email_text_box
            // 
            this->email_text_box->Location = System::Drawing::Point(108, 191);
            this->email_text_box->Name = L"email_text_box";
            this->email_text_box->Size = System::Drawing::Size(120, 20);
            this->email_text_box->TabIndex = 11;
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(142, 242);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(106, 40);
            this->back_button->TabIndex = 12;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            // 
            // AddGuestForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(269, 304);
            this->Controls->Add(this->back_button);
            this->Controls->Add(this->email_text_box);
            this->Controls->Add(this->birth_date_text_box);
            this->Controls->Add(this->passport_text_box);
            this->Controls->Add(this->patronymic_text_box);
            this->Controls->Add(this->surname_text_box);
            this->Controls->Add(this->name_text_box);
            this->Controls->Add(this->email_label);
            this->Controls->Add(this->birth_date_label);
            this->Controls->Add(this->name_label);
            this->Controls->Add(this->passport_label);
            this->Controls->Add(this->surname_label);
            this->Controls->Add(this->patronymic_label);
            this->Controls->Add(this->add_button);
            this->Name = L"AddGuestForm";
            this->Text = L"Add Guest";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
};
}