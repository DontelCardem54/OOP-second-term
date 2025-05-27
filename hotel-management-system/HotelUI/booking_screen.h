#pragma once

#include "ibooking.h"
#include "iwindow.h"
#include "iguests.h"
#include "irooms.h"

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
        IRooms* _rooms;
        bool _has_unsaved_changes = false;
        bool _is_editing = false;

        bool _is_start_date_changed = false;
        bool _is_end_date_changed = false;

    public:
        BookingScreen(IWindow^ parent, IGuests* guests, IRooms* rooms) : _parent(parent), _guests(guests), _rooms(rooms) {
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
    private: System::Windows::Forms::Label^ room_label;
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
            this->room_label = (gcnew System::Windows::Forms::Label());
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
            this->end_date_picker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->end_date_picker->Location = System::Drawing::Point(379, 211);
            this->end_date_picker->Name = L"end_date_picker";
            this->end_date_picker->Size = System::Drawing::Size(127, 20);
            this->end_date_picker->TabIndex = 35;
            this->end_date_picker->ValueChanged += gcnew System::EventHandler(this, &BookingScreen::end_date_Changed);
            // 
            // start_date_picker
            // 
            this->start_date_picker->Enabled = false;
            this->start_date_picker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->start_date_picker->Location = System::Drawing::Point(379, 181);
            this->start_date_picker->Name = L"start_date_picker";
            this->start_date_picker->Size = System::Drawing::Size(127, 20);
            this->start_date_picker->TabIndex = 34;
            this->start_date_picker->ValueChanged += gcnew System::EventHandler(this, &BookingScreen::start_date_Changed);
            // 
            // room_label
            // 
            this->room_label->AutoSize = true;
            this->room_label->Location = System::Drawing::Point(313, 323);
            this->room_label->Name = L"room_label";
            this->room_label->Size = System::Drawing::Size(76, 13);
            this->room_label->TabIndex = 33;
            this->room_label->Text = L"Room number:";
            // 
            // staff_label
            // 
            this->staff_label->AutoSize = true;
            this->staff_label->Location = System::Drawing::Point(312, 297);
            this->staff_label->Name = L"staff_label";
            this->staff_label->Size = System::Drawing::Size(108, 13);
            this->staff_label->TabIndex = 32;
            this->staff_label->Text = L"Staff: name, role, mail";
            // 
            // guest_label
            // 
            this->guest_label->AutoSize = true;
            this->guest_label->Location = System::Drawing::Point(309, 263);
            this->guest_label->Name = L"guest_label";
            this->guest_label->Size = System::Drawing::Size(91, 13);
            this->guest_label->TabIndex = 31;
            this->guest_label->Text = L"Guest: name, mail";
            // 
            // creation_time_label
            // 
            this->creation_time_label->AutoSize = true;
            this->creation_time_label->Location = System::Drawing::Point(303, 138);
            this->creation_time_label->Name = L"creation_time_label";
            this->creation_time_label->Size = System::Drawing::Size(77, 13);
            this->creation_time_label->TabIndex = 30;
            this->creation_time_label->Text = L"Creation_time: ";
            // 
            // exit_edit_mode_button
            // 
            this->exit_edit_mode_button->Location = System::Drawing::Point(344, 383);
            this->exit_edit_mode_button->Name = L"exit_edit_mode_button";
            this->exit_edit_mode_button->Size = System::Drawing::Size(102, 45);
            this->exit_edit_mode_button->TabIndex = 29;
            this->exit_edit_mode_button->Text = L"Exit edit mode";
            this->exit_edit_mode_button->UseVisualStyleBackColor = true;
            this->exit_edit_mode_button->Visible = false;
            this->exit_edit_mode_button->Click += gcnew System::EventHandler(this, &BookingScreen::exit_edit_mode_button_Click);
            // 
            // edit_mode_button
            // 
            this->edit_mode_button->Location = System::Drawing::Point(287, 412);
            this->edit_mode_button->Name = L"edit_mode_button";
            this->edit_mode_button->Size = System::Drawing::Size(102, 45);
            this->edit_mode_button->TabIndex = 28;
            this->edit_mode_button->Text = L"Edit mode";
            this->edit_mode_button->UseVisualStyleBackColor = true;
            this->edit_mode_button->Click += gcnew System::EventHandler(this, &BookingScreen::edit_mode_button_Click);
            // 
            // close_and_pay_button
            // 
            this->close_and_pay_button->Location = System::Drawing::Point(287, 355);
            this->close_and_pay_button->Name = L"close_and_pay_button";
            this->close_and_pay_button->Size = System::Drawing::Size(102, 47);
            this->close_and_pay_button->TabIndex = 27;
            this->close_and_pay_button->Text = L"Close and Pay";
            this->close_and_pay_button->UseVisualStyleBackColor = true;
            // 
            // cancel_button
            // 
            this->cancel_button->Location = System::Drawing::Point(404, 355);
            this->cancel_button->Name = L"cancel_button";
            this->cancel_button->Size = System::Drawing::Size(102, 47);
            this->cancel_button->TabIndex = 26;
            this->cancel_button->Text = L"Cancel";
            this->cancel_button->UseVisualStyleBackColor = true;
            this->cancel_button->Click += gcnew System::EventHandler(this, &BookingScreen::cancel_button_Click);
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(404, 412);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(102, 45);
            this->back_button->TabIndex = 25;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            this->back_button->Click += gcnew System::EventHandler(this, &BookingScreen::back_button_Click);
            // 
            // start_date_label
            // 
            this->start_date_label->AutoSize = true;
            this->start_date_label->Location = System::Drawing::Point(305, 187);
            this->start_date_label->Name = L"start_date_label";
            this->start_date_label->Size = System::Drawing::Size(56, 13);
            this->start_date_label->TabIndex = 23;
            this->start_date_label->Text = L"Start date:";
            // 
            // end_date_label
            // 
            this->end_date_label->AutoSize = true;
            this->end_date_label->Location = System::Drawing::Point(305, 217);
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
            this->Controls->Add(this->room_label);
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
        System::Void save_changes();
        System::Void enable_fields() {
            start_date_picker->Enabled = true;
            end_date_picker->Enabled = true;
        }
        System::Void disable_fields() {
            start_date_picker->Enabled = false;
            end_date_picker->Enabled = false;
        }
        System::Void disable_edit_mode() {
            _is_editing = false;

            close_and_pay_button->Visible = true;
            cancel_button->Visible = true;
            back_button->Visible = true;
            edit_mode_button->Visible = true;
            exit_edit_mode_button->Visible = false;

            disable_fields();
        }
        System::Void discard_changes() {
            fill_screen();
            _has_unsaved_changes = false;
        }
        System::Void start_date_Changed(Object^ sender, EventArgs^ e) {
            if (_is_editing)
            {
                _has_unsaved_changes = true;
                _is_start_date_changed = true;
            }
        }
        System::Void end_date_Changed(Object^ sender, EventArgs^ e)
        {
            if (_is_editing)
            {
                _has_unsaved_changes = true;
                _is_end_date_changed = true;
            }
        }
        System::Void cancel_booking() {
            disable_fields();
            this->close_and_pay_button->Enabled = false;
            this->cancel_button->Enabled = false;
            this->edit_mode_button->Enabled = false;
            this->exit_edit_mode_button->Enabled = false;
            _booking->remove();
            _booking = nullptr;
        }
    private: System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e) {
        _parent->GoBack();
    }
    private: System::Void edit_mode_button_Click(System::Object^ sender, System::EventArgs^ e) {
        enable_fields();

        close_and_pay_button->Visible = false;
        cancel_button->Visible = false;
        back_button->Visible = false;
        edit_mode_button->Visible = false;
        exit_edit_mode_button->Visible = true;
        _is_editing = true;
    }
    private: System::Void exit_edit_mode_button_Click(System::Object^ sender, System::EventArgs^ e) {
        if (_has_unsaved_changes)
        {
            System::Windows::Forms::DialogResult result = MessageBox::Show(
                "Save the changes?",
                "Exit Edit Mode",
                MessageBoxButtons::YesNoCancel,
                MessageBoxIcon::Question);

            if (result == System::Windows::Forms::DialogResult::Yes)
            {
                save_changes();
                disable_edit_mode();
            }
            else if (result == System::Windows::Forms::DialogResult::No)
            {
                discard_changes();
                disable_edit_mode();
            }
        }
        else
        {
            disable_edit_mode();
        }
    }
    private: System::Void cancel_button_Click(System::Object^ sender, System::EventArgs^ e) {
        System::Windows::Forms::DialogResult result = MessageBox::Show(
            "Cancel a booking?",
            "Canceling confirmation",
            MessageBoxButtons::YesNo,
            MessageBoxIcon::Question);

        if (result == System::Windows::Forms::DialogResult::Yes)
        {
            cancel_booking();
        }
    }
    };
}
