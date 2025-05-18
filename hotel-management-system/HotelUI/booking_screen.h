#pragma once

#include "ibooking.h"
#include "iwindow.h"
#include "iguests.h"

namespace CppCLRWinFormsProject
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class BookingScreen : UserControl
    {
    private: 
        IWindow^ _parent;
        IBooking* _booking;
        IGuests* _guests;
    public:
        BookingScreen(IWindow^ parent) : _parent(parent) {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~BookingScreen()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::DateTimePicker^ end_date_picker;
    private: System::Windows::Forms::DateTimePicker^ start_date_picker;
    private: System::Windows::Forms::Label^ state_label;
    private: System::Windows::Forms::Label^ staff_label;
    private: System::Windows::Forms::Label^ guest_label;
    private: System::Windows::Forms::Label^ creation_time_label;
    private: System::Windows::Forms::Button^ exit_edit_mode_button;
    private: System::Windows::Forms::Button^ edit_mode_button;
    private: System::Windows::Forms::Button^ close_and_pay_button;
    private: System::Windows::Forms::Button^ cancel_button;
    private: System::Windows::Forms::Button^ back_button;
    private: System::Windows::Forms::Label^ start_date_label;
    private: System::Windows::Forms::Label^ end_date_label;
           /// <summary> 
        /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->end_date_picker = (gcnew System::Windows::Forms::DateTimePicker());
            this->start_date_picker = (gcnew System::Windows::Forms::DateTimePicker());
            this->state_label = (gcnew System::Windows::Forms::Label());
            this->staff_label = (gcnew System::Windows::Forms::Label());
            this->guest_label = (gcnew System::Windows::Forms::Label());
            this->creation_time_label = (gcnew System::Windows::Forms::Label());
            this->exit_edit_mode_button = (gcnew System::Windows::Forms::Button());
            this->edit_mode_button = (gcnew System::Windows::Forms::Button());
            this->close_and_pay_button = (gcnew System::Windows::Forms::Button());
            this->cancel_button = (gcnew System::Windows::Forms::Button());
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->start_date_label = (gcnew System::Windows::Forms::Label());
            this->end_date_label = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // end_date_picker
            // 
            this->end_date_picker->Enabled = false;
            this->end_date_picker->Location = System::Drawing::Point(325, 210);
            this->end_date_picker->Name = L"end_date_picker";
            this->end_date_picker->Size = System::Drawing::Size(127, 20);
            this->end_date_picker->TabIndex = 35;
            // 
            // start_date_picker
            // 
            this->start_date_picker->Enabled = false;
            this->start_date_picker->Location = System::Drawing::Point(325, 180);
            this->start_date_picker->Name = L"start_date_picker";
            this->start_date_picker->Size = System::Drawing::Size(127, 20);
            this->start_date_picker->TabIndex = 34;
            // 
            // state_label
            // 
            this->state_label->AutoSize = true;
            this->state_label->Location = System::Drawing::Point(259, 322);
            this->state_label->Name = L"state_label";
            this->state_label->Size = System::Drawing::Size(38, 13);
            this->state_label->TabIndex = 33;
            this->state_label->Text = L"State: ";
            // 
            // staff_label
            // 
            this->staff_label->AutoSize = true;
            this->staff_label->Location = System::Drawing::Point(258, 296);
            this->staff_label->Name = L"staff_label";
            this->staff_label->Size = System::Drawing::Size(108, 13);
            this->staff_label->TabIndex = 32;
            this->staff_label->Text = L"Staff: name, role, mail";
            // 
            // guest_label
            // 
            this->guest_label->AutoSize = true;
            this->guest_label->Location = System::Drawing::Point(255, 262);
            this->guest_label->Name = L"guest_label";
            this->guest_label->Size = System::Drawing::Size(91, 13);
            this->guest_label->TabIndex = 31;
            this->guest_label->Text = L"Guest: name, mail";
            // 
            // creation_time_label
            // 
            this->creation_time_label->AutoSize = true;
            this->creation_time_label->Location = System::Drawing::Point(249, 137);
            this->creation_time_label->Name = L"creation_time_label";
            this->creation_time_label->Size = System::Drawing::Size(77, 13);
            this->creation_time_label->TabIndex = 30;
            this->creation_time_label->Text = L"Creation_time: ";
            // 
            // exit_edit_mode_button
            // 
            this->exit_edit_mode_button->Location = System::Drawing::Point(350, 411);
            this->exit_edit_mode_button->Name = L"exit_edit_mode_button";
            this->exit_edit_mode_button->Size = System::Drawing::Size(91, 45);
            this->exit_edit_mode_button->TabIndex = 29;
            this->exit_edit_mode_button->Text = L"Exit edit mode";
            this->exit_edit_mode_button->UseVisualStyleBackColor = true;
            // 
            // edit_mode_button
            // 
            this->edit_mode_button->Location = System::Drawing::Point(233, 411);
            this->edit_mode_button->Name = L"edit_mode_button";
            this->edit_mode_button->Size = System::Drawing::Size(93, 45);
            this->edit_mode_button->TabIndex = 28;
            this->edit_mode_button->Text = L"Edit mode";
            this->edit_mode_button->UseVisualStyleBackColor = true;
            // 
            // close_and_pay_button
            // 
            this->close_and_pay_button->Location = System::Drawing::Point(284, 358);
            this->close_and_pay_button->Name = L"close_and_pay_button";
            this->close_and_pay_button->Size = System::Drawing::Size(102, 47);
            this->close_and_pay_button->TabIndex = 27;
            this->close_and_pay_button->Text = L"Close and Pay";
            this->close_and_pay_button->UseVisualStyleBackColor = true;
            // 
            // cancel_button
            // 
            this->cancel_button->Location = System::Drawing::Point(417, 358);
            this->cancel_button->Name = L"cancel_button";
            this->cancel_button->Size = System::Drawing::Size(115, 43);
            this->cancel_button->TabIndex = 26;
            this->cancel_button->Text = L"Cancel";
            this->cancel_button->UseVisualStyleBackColor = true;
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(460, 411);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(106, 45);
            this->back_button->TabIndex = 25;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            this->back_button->Click += gcnew System::EventHandler(this, &BookingScreen::back_button_Click);
            // 
            // start_date_label
            // 
            this->start_date_label->AutoSize = true;
            this->start_date_label->Location = System::Drawing::Point(251, 186);
            this->start_date_label->Name = L"start_date_label";
            this->start_date_label->Size = System::Drawing::Size(56, 13);
            this->start_date_label->TabIndex = 23;
            this->start_date_label->Text = L"Start date:";
            // 
            // end_date_label
            // 
            this->end_date_label->AutoSize = true;
            this->end_date_label->Location = System::Drawing::Point(251, 216);
            this->end_date_label->Name = L"end_date_label";
            this->end_date_label->Size = System::Drawing::Size(56, 13);
            this->end_date_label->TabIndex = 24;
            this->end_date_label->Text = L"End date: ";
            // 
            // BookingScreen
            // 
            this->BackColor = System::Drawing::SystemColors::Control;
            this->Controls->Add(this->end_date_picker);
            this->Controls->Add(this->start_date_picker);
            this->Controls->Add(this->state_label);
            this->Controls->Add(this->staff_label);
            this->Controls->Add(this->guest_label);
            this->Controls->Add(this->creation_time_label);
            this->Controls->Add(this->exit_edit_mode_button);
            this->Controls->Add(this->edit_mode_button);
            this->Controls->Add(this->close_and_pay_button);
            this->Controls->Add(this->cancel_button);
            this->Controls->Add(this->back_button);
            this->Controls->Add(this->start_date_label);
            this->Controls->Add(this->end_date_label);
            this->Name = L"BookingScreen";
            this->Size = System::Drawing::Size(800, 600);
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        public:
            System::Void set_booking(IBooking* booking);

        private:
            System::Void fill_screen();
    private: System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e) {
        _parent->GoBack();
    }
};
}
