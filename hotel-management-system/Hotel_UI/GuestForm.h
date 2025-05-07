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
    /// Summary for GuestForm
    /// </summary>
    public ref class GuestForm : public System::Windows::Forms::Form
    {
    private:
        Hotel* _hotel;

    public:
        GuestForm(Hotel* hotel) : _hotel(hotel)
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
        ~GuestForm()
        {
            if (components)
            {
                delete components;
            }
        }

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
    private: System::Windows::Forms::Button^ delete_button;
    private: System::Windows::Forms::Button^ view_booking_history_button;
    private: System::Windows::Forms::Button^ edit_mode_button;
    private: System::Windows::Forms::Button^ exit_edit_mode_button;

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
            this->delete_button = (gcnew System::Windows::Forms::Button());
            this->view_booking_history_button = (gcnew System::Windows::Forms::Button());
            this->edit_mode_button = (gcnew System::Windows::Forms::Button());
            this->exit_edit_mode_button = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
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
            this->name_text_box->ReadOnly = true;
            this->name_text_box->Size = System::Drawing::Size(120, 20);
            this->name_text_box->TabIndex = 6;
            // 
            // surname_text_box
            // 
            this->surname_text_box->Location = System::Drawing::Point(108, 71);
            this->surname_text_box->Name = L"surname_text_box";
            this->surname_text_box->ReadOnly = true;
            this->surname_text_box->Size = System::Drawing::Size(120, 20);
            this->surname_text_box->TabIndex = 7;
            // 
            // patronymic_text_box
            // 
            this->patronymic_text_box->Location = System::Drawing::Point(108, 101);
            this->patronymic_text_box->Name = L"patronymic_text_box";
            this->patronymic_text_box->ReadOnly = true;
            this->patronymic_text_box->Size = System::Drawing::Size(120, 20);
            this->patronymic_text_box->TabIndex = 8;
            // 
            // passport_text_box
            // 
            this->passport_text_box->Location = System::Drawing::Point(108, 131);
            this->passport_text_box->Name = L"passport_text_box";
            this->passport_text_box->ReadOnly = true;
            this->passport_text_box->Size = System::Drawing::Size(120, 20);
            this->passport_text_box->TabIndex = 9;
            // 
            // birth_date_text_box
            // 
            this->birth_date_text_box->Location = System::Drawing::Point(108, 161);
            this->birth_date_text_box->Name = L"birth_date_text_box";
            this->birth_date_text_box->ReadOnly = true;
            this->birth_date_text_box->Size = System::Drawing::Size(120, 20);
            this->birth_date_text_box->TabIndex = 10;
            // 
            // email_text_box
            // 
            this->email_text_box->Location = System::Drawing::Point(108, 191);
            this->email_text_box->Name = L"email_text_box";
            this->email_text_box->ReadOnly = true;
            this->email_text_box->Size = System::Drawing::Size(120, 20);
            this->email_text_box->TabIndex = 11;
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(245, 318);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(106, 40);
            this->back_button->TabIndex = 12;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            // 
            // delete_button
            // 
            this->delete_button->Location = System::Drawing::Point(204, 252);
            this->delete_button->Name = L"delete_button";
            this->delete_button->Size = System::Drawing::Size(115, 43);
            this->delete_button->TabIndex = 13;
            this->delete_button->Text = L"Delete";
            this->delete_button->UseVisualStyleBackColor = true;
            // 
            // view_booking_history_button
            // 
            this->view_booking_history_button->Location = System::Drawing::Point(71, 252);
            this->view_booking_history_button->Name = L"view_booking_history_button";
            this->view_booking_history_button->Size = System::Drawing::Size(102, 47);
            this->view_booking_history_button->TabIndex = 14;
            this->view_booking_history_button->Text = L"View booking history";
            this->view_booking_history_button->UseVisualStyleBackColor = true;
            // 
            // edit_mode_button
            // 
            this->edit_mode_button->Location = System::Drawing::Point(24, 305);
            this->edit_mode_button->Name = L"edit_mode_button";
            this->edit_mode_button->Size = System::Drawing::Size(93, 42);
            this->edit_mode_button->TabIndex = 15;
            this->edit_mode_button->Text = L"Edit mode";
            this->edit_mode_button->UseVisualStyleBackColor = true;
            // 
            // exit_edit_mode_button
            // 
            this->exit_edit_mode_button->Location = System::Drawing::Point(137, 305);
            this->exit_edit_mode_button->Name = L"exit_edit_mode_button";
            this->exit_edit_mode_button->Size = System::Drawing::Size(91, 45);
            this->exit_edit_mode_button->TabIndex = 16;
            this->exit_edit_mode_button->Text = L"Exit edit mode";
            this->exit_edit_mode_button->UseVisualStyleBackColor = true;
            // 
            // GuestForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(363, 385);
            this->Controls->Add(this->exit_edit_mode_button);
            this->Controls->Add(this->edit_mode_button);
            this->Controls->Add(this->view_booking_history_button);
            this->Controls->Add(this->delete_button);
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
            this->Name = L"GuestForm";
            this->Text = L"Guest";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    };
}