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
    /// Summary for BookingForm
    /// </summary>
    public ref class BookingForm : public System::Windows::Forms::Form
    {
    private:
        Hotel* _hotel;

    public:
        BookingForm(Hotel* hotel) : _hotel(hotel)
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
        ~BookingForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ start_date_label;
    private: System::Windows::Forms::Label^ end_date_label;
    protected:







    private: System::Windows::Forms::TextBox^ name_text_box;
    private: System::Windows::Forms::TextBox^ surname_text_box;




    private: System::Windows::Forms::Button^ back_button;
    private: System::Windows::Forms::Button^ cancel_button;
    private: System::Windows::Forms::Button^ close_and_pay_button;


    private: System::Windows::Forms::Button^ edit_mode_button;
    private: System::Windows::Forms::Button^ exit_edit_mode_button;
    private: System::Windows::Forms::Label^ creation_time_label;
    private: System::Windows::Forms::Label^ guest_label;
    private: System::Windows::Forms::Label^ staff_label;
    private: System::Windows::Forms::Label^ state_label;

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
            this->start_date_label = (gcnew System::Windows::Forms::Label());
            this->end_date_label = (gcnew System::Windows::Forms::Label());
            this->name_text_box = (gcnew System::Windows::Forms::TextBox());
            this->surname_text_box = (gcnew System::Windows::Forms::TextBox());
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->cancel_button = (gcnew System::Windows::Forms::Button());
            this->close_and_pay_button = (gcnew System::Windows::Forms::Button());
            this->edit_mode_button = (gcnew System::Windows::Forms::Button());
            this->exit_edit_mode_button = (gcnew System::Windows::Forms::Button());
            this->creation_time_label = (gcnew System::Windows::Forms::Label());
            this->guest_label = (gcnew System::Windows::Forms::Label());
            this->staff_label = (gcnew System::Windows::Forms::Label());
            this->state_label = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // start_date_label
            // 
            this->start_date_label->AutoSize = true;
            this->start_date_label->Location = System::Drawing::Point(38, 80);
            this->start_date_label->Name = L"start_date_label";
            this->start_date_label->Size = System::Drawing::Size(56, 13);
            this->start_date_label->TabIndex = 1;
            this->start_date_label->Text = L"Start date:";
            // 
            // end_date_label
            // 
            this->end_date_label->AutoSize = true;
            this->end_date_label->Location = System::Drawing::Point(38, 110);
            this->end_date_label->Name = L"end_date_label";
            this->end_date_label->Size = System::Drawing::Size(56, 13);
            this->end_date_label->TabIndex = 2;
            this->end_date_label->Text = L"End date: ";
            // 
            // name_text_box
            // 
            this->name_text_box->Location = System::Drawing::Point(108, 80);
            this->name_text_box->Name = L"name_text_box";
            this->name_text_box->ReadOnly = true;
            this->name_text_box->Size = System::Drawing::Size(120, 20);
            this->name_text_box->TabIndex = 6;
            // 
            // surname_text_box
            // 
            this->surname_text_box->Location = System::Drawing::Point(108, 110);
            this->surname_text_box->Name = L"surname_text_box";
            this->surname_text_box->ReadOnly = true;
            this->surname_text_box->Size = System::Drawing::Size(120, 20);
            this->surname_text_box->TabIndex = 7;
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
            // cancel_button
            // 
            this->cancel_button->Location = System::Drawing::Point(204, 252);
            this->cancel_button->Name = L"cancel_button";
            this->cancel_button->Size = System::Drawing::Size(115, 43);
            this->cancel_button->TabIndex = 13;
            this->cancel_button->Text = L"Cancel";
            this->cancel_button->UseVisualStyleBackColor = true;
            // 
            // close_and_pay_button
            // 
            this->close_and_pay_button->Location = System::Drawing::Point(71, 252);
            this->close_and_pay_button->Name = L"close_and_pay_button";
            this->close_and_pay_button->Size = System::Drawing::Size(102, 47);
            this->close_and_pay_button->TabIndex = 14;
            this->close_and_pay_button->Text = L"Close and Pay";
            this->close_and_pay_button->UseVisualStyleBackColor = true;
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
            // creation_time_label
            // 
            this->creation_time_label->AutoSize = true;
            this->creation_time_label->Location = System::Drawing::Point(36, 31);
            this->creation_time_label->Name = L"creation_time_label";
            this->creation_time_label->Size = System::Drawing::Size(77, 13);
            this->creation_time_label->TabIndex = 17;
            this->creation_time_label->Text = L"Creation_time: ";
            // 
            // guest_label
            // 
            this->guest_label->AutoSize = true;
            this->guest_label->Location = System::Drawing::Point(42, 156);
            this->guest_label->Name = L"guest_label";
            this->guest_label->Size = System::Drawing::Size(91, 13);
            this->guest_label->TabIndex = 18;
            this->guest_label->Text = L"Guest: name, mail";
            // 
            // staff_label
            // 
            this->staff_label->AutoSize = true;
            this->staff_label->Location = System::Drawing::Point(45, 190);
            this->staff_label->Name = L"staff_label";
            this->staff_label->Size = System::Drawing::Size(108, 13);
            this->staff_label->TabIndex = 19;
            this->staff_label->Text = L"Staff: name, role, mail";
            // 
            // state_label
            // 
            this->state_label->AutoSize = true;
            this->state_label->Location = System::Drawing::Point(46, 216);
            this->state_label->Name = L"state_label";
            this->state_label->Size = System::Drawing::Size(38, 13);
            this->state_label->TabIndex = 20;
            this->state_label->Text = L"State: ";
            // 
            // BookingForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(363, 385);
            this->Controls->Add(this->state_label);
            this->Controls->Add(this->staff_label);
            this->Controls->Add(this->guest_label);
            this->Controls->Add(this->creation_time_label);
            this->Controls->Add(this->exit_edit_mode_button);
            this->Controls->Add(this->edit_mode_button);
            this->Controls->Add(this->close_and_pay_button);
            this->Controls->Add(this->cancel_button);
            this->Controls->Add(this->back_button);
            this->Controls->Add(this->surname_text_box);
            this->Controls->Add(this->name_text_box);
            this->Controls->Add(this->start_date_label);
            this->Controls->Add(this->end_date_label);
            this->Name = L"BookingForm";
            this->Text = L"Booking";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void email_label_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void email_text_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void birth_date_label_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void birth_date_text_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void passport_label_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void passport_text_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void patronymic_text_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void patronymic_label_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};
}