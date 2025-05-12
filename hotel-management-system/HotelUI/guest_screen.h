#pragma once
namespace CppCLRWinFormsProject
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class GuestScreen : UserControl
    {
    public:
        GuestScreen() {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~GuestScreen()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::DateTimePicker^ birth_date_time_picker;
    protected:
    private: System::Windows::Forms::Button^ exit_edit_mode_button;
    private: System::Windows::Forms::Button^ edit_mode_button;
    private: System::Windows::Forms::Button^ view_booking_history_button;
    private: System::Windows::Forms::Button^ delete_button;
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

    protected:

        /// <summary> 
        /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->birth_date_time_picker = (gcnew System::Windows::Forms::DateTimePicker());
            this->exit_edit_mode_button = (gcnew System::Windows::Forms::Button());
            this->edit_mode_button = (gcnew System::Windows::Forms::Button());
            this->view_booking_history_button = (gcnew System::Windows::Forms::Button());
            this->delete_button = (gcnew System::Windows::Forms::Button());
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
            this->SuspendLayout();
            // 
            // birth_date_time_picker
            // 
            this->birth_date_time_picker->Enabled = false;
            this->birth_date_time_picker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->birth_date_time_picker->Location = System::Drawing::Point(375, 271);
            this->birth_date_time_picker->Name = L"birth_date_time_picker";
            this->birth_date_time_picker->Size = System::Drawing::Size(120, 20);
            this->birth_date_time_picker->TabIndex = 51;
            // 
            // exit_edit_mode_button
            // 
            this->exit_edit_mode_button->Location = System::Drawing::Point(354, 370);
            this->exit_edit_mode_button->Name = L"exit_edit_mode_button";
            this->exit_edit_mode_button->Size = System::Drawing::Size(90, 50);
            this->exit_edit_mode_button->TabIndex = 50;
            this->exit_edit_mode_button->Text = L"Exit edit mode";
            this->exit_edit_mode_button->UseVisualStyleBackColor = true;
            this->exit_edit_mode_button->Visible = false;
            // 
            // edit_mode_button
            // 
            this->edit_mode_button->Location = System::Drawing::Point(308, 399);
            this->edit_mode_button->Name = L"edit_mode_button";
            this->edit_mode_button->Size = System::Drawing::Size(90, 50);
            this->edit_mode_button->TabIndex = 49;
            this->edit_mode_button->Text = L"Edit mode";
            this->edit_mode_button->UseVisualStyleBackColor = true;
            // 
            // view_booking_history_button
            // 
            this->view_booking_history_button->Location = System::Drawing::Point(308, 343);
            this->view_booking_history_button->Name = L"view_booking_history_button";
            this->view_booking_history_button->Size = System::Drawing::Size(90, 50);
            this->view_booking_history_button->TabIndex = 48;
            this->view_booking_history_button->Text = L"View booking history";
            this->view_booking_history_button->UseVisualStyleBackColor = true;
            // 
            // delete_button
            // 
            this->delete_button->Location = System::Drawing::Point(405, 343);
            this->delete_button->Name = L"delete_button";
            this->delete_button->Size = System::Drawing::Size(90, 50);
            this->delete_button->TabIndex = 47;
            this->delete_button->Text = L"Delete";
            this->delete_button->UseVisualStyleBackColor = true;
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(404, 399);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(90, 50);
            this->back_button->TabIndex = 46;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            this->back_button->Click += gcnew System::EventHandler(this, &GuestScreen::back_button_Click);
            // 
            // email_text_box
            // 
            this->email_text_box->Location = System::Drawing::Point(375, 301);
            this->email_text_box->Name = L"email_text_box";
            this->email_text_box->ReadOnly = true;
            this->email_text_box->Size = System::Drawing::Size(120, 20);
            this->email_text_box->TabIndex = 45;
            // 
            // passport_text_box
            // 
            this->passport_text_box->Location = System::Drawing::Point(375, 241);
            this->passport_text_box->Name = L"passport_text_box";
            this->passport_text_box->ReadOnly = true;
            this->passport_text_box->Size = System::Drawing::Size(120, 20);
            this->passport_text_box->TabIndex = 44;
            // 
            // patronymic_text_box
            // 
            this->patronymic_text_box->Location = System::Drawing::Point(375, 211);
            this->patronymic_text_box->Name = L"patronymic_text_box";
            this->patronymic_text_box->ReadOnly = true;
            this->patronymic_text_box->Size = System::Drawing::Size(120, 20);
            this->patronymic_text_box->TabIndex = 43;
            // 
            // surname_text_box
            // 
            this->surname_text_box->Location = System::Drawing::Point(375, 181);
            this->surname_text_box->Name = L"surname_text_box";
            this->surname_text_box->ReadOnly = true;
            this->surname_text_box->Size = System::Drawing::Size(120, 20);
            this->surname_text_box->TabIndex = 42;
            // 
            // name_text_box
            // 
            this->name_text_box->Location = System::Drawing::Point(375, 151);
            this->name_text_box->Name = L"name_text_box";
            this->name_text_box->ReadOnly = true;
            this->name_text_box->Size = System::Drawing::Size(120, 20);
            this->name_text_box->TabIndex = 41;
            // 
            // email_label
            // 
            this->email_label->AutoSize = true;
            this->email_label->Location = System::Drawing::Point(305, 301);
            this->email_label->Name = L"email_label";
            this->email_label->Size = System::Drawing::Size(38, 13);
            this->email_label->TabIndex = 40;
            this->email_label->Text = L"Email: ";
            // 
            // birth_date_label
            // 
            this->birth_date_label->AutoSize = true;
            this->birth_date_label->Location = System::Drawing::Point(305, 271);
            this->birth_date_label->Name = L"birth_date_label";
            this->birth_date_label->Size = System::Drawing::Size(58, 13);
            this->birth_date_label->TabIndex = 39;
            this->birth_date_label->Text = L"Birth date: ";
            // 
            // name_label
            // 
            this->name_label->AutoSize = true;
            this->name_label->Location = System::Drawing::Point(305, 151);
            this->name_label->Name = L"name_label";
            this->name_label->Size = System::Drawing::Size(41, 13);
            this->name_label->TabIndex = 36;
            this->name_label->Text = L"Name: ";
            // 
            // passport_label
            // 
            this->passport_label->AutoSize = true;
            this->passport_label->Location = System::Drawing::Point(305, 241);
            this->passport_label->Name = L"passport_label";
            this->passport_label->Size = System::Drawing::Size(54, 13);
            this->passport_label->TabIndex = 35;
            this->passport_label->Text = L"Passport: ";
            // 
            // surname_label
            // 
            this->surname_label->AutoSize = true;
            this->surname_label->Location = System::Drawing::Point(305, 181);
            this->surname_label->Name = L"surname_label";
            this->surname_label->Size = System::Drawing::Size(55, 13);
            this->surname_label->TabIndex = 37;
            this->surname_label->Text = L"Surname: ";
            // 
            // patronymic_label
            // 
            this->patronymic_label->AutoSize = true;
            this->patronymic_label->Location = System::Drawing::Point(305, 211);
            this->patronymic_label->Name = L"patronymic_label";
            this->patronymic_label->Size = System::Drawing::Size(65, 13);
            this->patronymic_label->TabIndex = 38;
            this->patronymic_label->Text = L"Patronymic: ";
            // 
            // GuestPanel
            // 
            this->BackColor = System::Drawing::SystemColors::Control;
            this->Controls->Add(this->birth_date_time_picker);
            this->Controls->Add(this->exit_edit_mode_button);
            this->Controls->Add(this->edit_mode_button);
            this->Controls->Add(this->view_booking_history_button);
            this->Controls->Add(this->delete_button);
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
            this->Name = L"GuestPanel";
            this->Size = System::Drawing::Size(800, 600);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
    private: System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Visible = false;
    }
};
}
