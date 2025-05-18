#pragma once

#include "iguests.h"
#include "iwindow.h"
#include "iguest.h"

namespace CppCLRWinFormsProject
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class AddGuestScreen : UserControl
    {
    private:
        IWindow^ _parent;
        IGuests* _guests;
        IGuest* _current_guest;
    public:
        AddGuestScreen(IWindow^ parent, IGuests* guests) : _parent(parent), _guests(guests) {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~AddGuestScreen()
        {
            if (components)
            {
                delete components;
            }

            delete _current_guest;
        }
    private: System::Windows::Forms::Button^ open_guest_button;
    private: System::Windows::Forms::Button^ add_again_button;
    private: System::Windows::Forms::DateTimePicker^ birth_date_time_picker;
    private: System::Windows::Forms::Button^ back_button;
    private: System::Windows::Forms::TextBox^ email_text_box;
    private: System::Windows::Forms::TextBox^ passport_text_box;
    private: System::Windows::Forms::TextBox^ patronymic_text_box;
    private: System::Windows::Forms::TextBox^ surname_text_box;
    private: System::Windows::Forms::TextBox^ name_text_box;
    private: System::Windows::Forms::Label^ email_label;
    private: System::Windows::Forms::Label^ birth_date_label;
    private: System::Windows::Forms::Label^ name_label;
    private: System::Windows::Forms::Label^ passport_label;
    private: System::Windows::Forms::Label^ surname_label;
    private: System::Windows::Forms::Label^ patronymic_label;
    private: System::Windows::Forms::Button^ add_button;
           /// <summary> 
        /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->birth_date_time_picker = (gcnew System::Windows::Forms::DateTimePicker());
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->email_text_box = (gcnew System::Windows::Forms::TextBox());
            this->passport_text_box = (gcnew System::Windows::Forms::TextBox());
            this->patronymic_text_box = (gcnew System::Windows::Forms::TextBox());
            this->surname_text_box = (gcnew System::Windows::Forms::TextBox());
            this->name_text_box = (gcnew System::Windows::Forms::TextBox());
            this->email_label = (gcnew System::Windows::Forms::Label());
            this->birth_date_label = (gcnew System::Windows::Forms::Label());
            this->name_label = (gcnew System::Windows::Forms::Label());
            this->passport_label = (gcnew System::Windows::Forms::Label());
            this->surname_label = (gcnew System::Windows::Forms::Label());
            this->patronymic_label = (gcnew System::Windows::Forms::Label());
            this->add_button = (gcnew System::Windows::Forms::Button());
            this->open_guest_button = (gcnew System::Windows::Forms::Button());
            this->add_again_button = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // birth_date_time_picker
            // 
            this->birth_date_time_picker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->birth_date_time_picker->Location = System::Drawing::Point(372, 300);
            this->birth_date_time_picker->Name = L"birth_date_time_picker";
            this->birth_date_time_picker->Size = System::Drawing::Size(120, 20);
            this->birth_date_time_picker->TabIndex = 27;
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(406, 381);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(100, 40);
            this->back_button->TabIndex = 26;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            this->back_button->Click += gcnew System::EventHandler(this, &AddGuestScreen::back_button_Click);
            // 
            // email_text_box
            // 
            this->email_text_box->Location = System::Drawing::Point(372, 330);
            this->email_text_box->Name = L"email_text_box";
            this->email_text_box->Size = System::Drawing::Size(120, 20);
            this->email_text_box->TabIndex = 25;
            // 
            // passport_text_box
            // 
            this->passport_text_box->Location = System::Drawing::Point(372, 270);
            this->passport_text_box->Name = L"passport_text_box";
            this->passport_text_box->Size = System::Drawing::Size(120, 20);
            this->passport_text_box->TabIndex = 24;
            // 
            // patronymic_text_box
            // 
            this->patronymic_text_box->Location = System::Drawing::Point(372, 240);
            this->patronymic_text_box->Name = L"patronymic_text_box";
            this->patronymic_text_box->Size = System::Drawing::Size(120, 20);
            this->patronymic_text_box->TabIndex = 23;
            // 
            // surname_text_box
            // 
            this->surname_text_box->Location = System::Drawing::Point(372, 210);
            this->surname_text_box->Name = L"surname_text_box";
            this->surname_text_box->Size = System::Drawing::Size(120, 20);
            this->surname_text_box->TabIndex = 22;
            // 
            // name_text_box
            // 
            this->name_text_box->Location = System::Drawing::Point(372, 180);
            this->name_text_box->Name = L"name_text_box";
            this->name_text_box->Size = System::Drawing::Size(120, 20);
            this->name_text_box->TabIndex = 21;
            // 
            // email_label
            // 
            this->email_label->AutoSize = true;
            this->email_label->Location = System::Drawing::Point(302, 330);
            this->email_label->Name = L"email_label";
            this->email_label->Size = System::Drawing::Size(38, 13);
            this->email_label->TabIndex = 20;
            this->email_label->Text = L"Email: ";
            // 
            // birth_date_label
            // 
            this->birth_date_label->AutoSize = true;
            this->birth_date_label->Location = System::Drawing::Point(302, 300);
            this->birth_date_label->Name = L"birth_date_label";
            this->birth_date_label->Size = System::Drawing::Size(58, 13);
            this->birth_date_label->TabIndex = 19;
            this->birth_date_label->Text = L"Birth date: ";
            // 
            // name_label
            // 
            this->name_label->AutoSize = true;
            this->name_label->Location = System::Drawing::Point(302, 180);
            this->name_label->Name = L"name_label";
            this->name_label->Size = System::Drawing::Size(41, 13);
            this->name_label->TabIndex = 16;
            this->name_label->Text = L"Name: ";
            // 
            // passport_label
            // 
            this->passport_label->AutoSize = true;
            this->passport_label->Location = System::Drawing::Point(302, 270);
            this->passport_label->Name = L"passport_label";
            this->passport_label->Size = System::Drawing::Size(54, 13);
            this->passport_label->TabIndex = 14;
            this->passport_label->Text = L"Passport: ";
            // 
            // surname_label
            // 
            this->surname_label->AutoSize = true;
            this->surname_label->Location = System::Drawing::Point(302, 210);
            this->surname_label->Name = L"surname_label";
            this->surname_label->Size = System::Drawing::Size(55, 13);
            this->surname_label->TabIndex = 17;
            this->surname_label->Text = L"Surname: ";
            // 
            // patronymic_label
            // 
            this->patronymic_label->AutoSize = true;
            this->patronymic_label->Location = System::Drawing::Point(302, 240);
            this->patronymic_label->Name = L"patronymic_label";
            this->patronymic_label->Size = System::Drawing::Size(65, 13);
            this->patronymic_label->TabIndex = 18;
            this->patronymic_label->Text = L"Patronymic: ";
            // 
            // add_button
            // 
            this->add_button->Location = System::Drawing::Point(288, 381);
            this->add_button->Name = L"add_button";
            this->add_button->Size = System::Drawing::Size(100, 40);
            this->add_button->TabIndex = 15;
            this->add_button->Text = L"Add";
            this->add_button->UseVisualStyleBackColor = true;
            this->add_button->Click += gcnew System::EventHandler(this, &AddGuestScreen::add_button_Click);
            // 
            // open_guest_button
            // 
            this->open_guest_button->Location = System::Drawing::Point(345, 427);
            this->open_guest_button->Name = L"open_guest_button";
            this->open_guest_button->Size = System::Drawing::Size(100, 40);
            this->open_guest_button->TabIndex = 28;
            this->open_guest_button->Text = L"Open guest";
            this->open_guest_button->UseVisualStyleBackColor = true;
            this->open_guest_button->Visible = false;
            this->open_guest_button->Click += gcnew System::EventHandler(this, &AddGuestScreen::open_guest_button_Click);
            // 
            // add_again_button
            // 
            this->add_again_button->Location = System::Drawing::Point(288, 381);
            this->add_again_button->Name = L"add_again_button";
            this->add_again_button->Size = System::Drawing::Size(100, 40);
            this->add_again_button->TabIndex = 29;
            this->add_again_button->Text = L"Add again";
            this->add_again_button->UseVisualStyleBackColor = true;
            this->add_again_button->Visible = false;
            this->add_again_button->Click += gcnew System::EventHandler(this, &AddGuestScreen::add_again_button_Click);
            // 
            // AddGuestScreen
            // 
            this->BackColor = System::Drawing::SystemColors::Control;
            this->Controls->Add(this->add_again_button);
            this->Controls->Add(this->open_guest_button);
            this->Controls->Add(this->birth_date_time_picker);
            this->Controls->Add(this->back_button);
            this->Controls->Add(this->email_text_box);
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
            this->Name = L"AddGuestScreen";
            this->Size = System::Drawing::Size(800, 600);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
    private: System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e) {
        clear_fields();
        enable_fields();
        _parent->GoBack();
    }
    private: System::Void add_button_Click(System::Object^ sender, System::EventArgs^ e);
    private:
        void disable_fields() {
            name_text_box->Enabled = false;
            surname_text_box->Enabled = false;
            patronymic_text_box->Enabled = false;
            passport_text_box->Enabled = false;
            birth_date_time_picker->Enabled = false;
            email_text_box->Enabled = false;
            add_button->Visible = false;
            add_again_button->Visible = true;
            open_guest_button->Visible = true;
        }

        void enable_fields() {
            name_text_box->Enabled = true;
            surname_text_box->Enabled = true;
            patronymic_text_box->Enabled = true;
            passport_text_box->Enabled = true;
            birth_date_time_picker->Enabled = true;
            email_text_box->Enabled = true;
            add_button->Visible = true;
            add_again_button->Visible = false;
            open_guest_button->Visible = false;
        }

        void clear_fields() {
            name_text_box->Text = System::String::Empty;
            surname_text_box->Text = System::String::Empty;
            patronymic_text_box->Text = System::String::Empty;
            passport_text_box->Text = System::String::Empty;
            birth_date_time_picker->Value = DateTime::Now;
            email_text_box->Text = System::String::Empty;
        }

    private: System::Void add_again_button_Click(System::Object^ sender, System::EventArgs^ e) {
        clear_fields();
        enable_fields();
    }
    private:System::Void open_guest_button_Click(System::Object^ sender, System::EventArgs^ e) {
        clear_fields();
        enable_fields();
        _parent->ShowGuestScreen(_current_guest);
    }
    };
}
