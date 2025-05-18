#pragma once
#include "iwindow.h"
#include "ibooking.h"
#include "ibookings.h"
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

    public ref class CreateBookingScreen : UserControl
    {
    private:
        IWindow^ _parent;
        IBookings* _bookings;
        IBooking* _current_booking;
        IGuests* _guests;
        IRooms* _rooms;
    private: System::Windows::Forms::Button^ open_booking_button;
    private: System::Windows::Forms::Button^ add_again_button;

    public:
        CreateBookingScreen(IWindow^ parent, IBookings* bookings, IGuests* guests, IRooms* rooms)
            : _parent(parent), _bookings(bookings), _guests(guests), _rooms(rooms) {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~CreateBookingScreen()
        {
            if (components)
            {
                delete components;
            }

            delete _current_booking;
        }
    private: System::Windows::Forms::Button^ back_button;
    private: System::Windows::Forms::TextBox^ room_number_text_box;
    private: System::Windows::Forms::TextBox^ staff_passport_text_box;
    private: System::Windows::Forms::TextBox^ guest_passport_text_box;
    private: System::Windows::Forms::Label^ room_number_label;
    private: System::Windows::Forms::Label^ start_date_label;
    private: System::Windows::Forms::Label^ staff_passport_label;
    private: System::Windows::Forms::Label^ end_date_label;
    private: System::Windows::Forms::Label^ guest_passport_label;
    private: System::Windows::Forms::Button^ create_button;
    private: System::Windows::Forms::DateTimePicker^ start_date_time_picker;
    private: System::Windows::Forms::DateTimePicker^ end_date_time_picker;

    protected:
        /// <summary> 
        /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->room_number_text_box = (gcnew System::Windows::Forms::TextBox());
            this->staff_passport_text_box = (gcnew System::Windows::Forms::TextBox());
            this->guest_passport_text_box = (gcnew System::Windows::Forms::TextBox());
            this->room_number_label = (gcnew System::Windows::Forms::Label());
            this->start_date_label = (gcnew System::Windows::Forms::Label());
            this->staff_passport_label = (gcnew System::Windows::Forms::Label());
            this->end_date_label = (gcnew System::Windows::Forms::Label());
            this->guest_passport_label = (gcnew System::Windows::Forms::Label());
            this->create_button = (gcnew System::Windows::Forms::Button());
            this->start_date_time_picker = (gcnew System::Windows::Forms::DateTimePicker());
            this->end_date_time_picker = (gcnew System::Windows::Forms::DateTimePicker());
            this->open_booking_button = (gcnew System::Windows::Forms::Button());
            this->add_again_button = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(406, 363);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(106, 40);
            this->back_button->TabIndex = 24;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            this->back_button->Click += gcnew System::EventHandler(this, &CreateBookingScreen::back_button_Click);
            // 
            // room_number_text_box
            // 
            this->room_number_text_box->Location = System::Drawing::Point(375, 318);
            this->room_number_text_box->Name = L"room_number_text_box";
            this->room_number_text_box->Size = System::Drawing::Size(120, 20);
            this->room_number_text_box->TabIndex = 23;
            // 
            // staff_passport_text_box
            // 
            this->staff_passport_text_box->Location = System::Drawing::Point(375, 288);
            this->staff_passport_text_box->Name = L"staff_passport_text_box";
            this->staff_passport_text_box->Size = System::Drawing::Size(120, 20);
            this->staff_passport_text_box->TabIndex = 22;
            // 
            // guest_passport_text_box
            // 
            this->guest_passport_text_box->Location = System::Drawing::Point(375, 258);
            this->guest_passport_text_box->Name = L"guest_passport_text_box";
            this->guest_passport_text_box->Size = System::Drawing::Size(120, 20);
            this->guest_passport_text_box->TabIndex = 21;
            // 
            // room_number_label
            // 
            this->room_number_label->AutoSize = true;
            this->room_number_label->Location = System::Drawing::Point(293, 321);
            this->room_number_label->Name = L"room_number_label";
            this->room_number_label->Size = System::Drawing::Size(76, 13);
            this->room_number_label->TabIndex = 18;
            this->room_number_label->Text = L"Room number:";
            // 
            // start_date_label
            // 
            this->start_date_label->AutoSize = true;
            this->start_date_label->Location = System::Drawing::Point(305, 198);
            this->start_date_label->Name = L"start_date_label";
            this->start_date_label->Size = System::Drawing::Size(56, 13);
            this->start_date_label->TabIndex = 15;
            this->start_date_label->Text = L"Start date:";
            // 
            // staff_passport_label
            // 
            this->staff_passport_label->AutoSize = true;
            this->staff_passport_label->Location = System::Drawing::Point(293, 291);
            this->staff_passport_label->Name = L"staff_passport_label";
            this->staff_passport_label->Size = System::Drawing::Size(78, 13);
            this->staff_passport_label->TabIndex = 13;
            this->staff_passport_label->Text = L"Staff passport: ";
            // 
            // end_date_label
            // 
            this->end_date_label->AutoSize = true;
            this->end_date_label->Location = System::Drawing::Point(305, 228);
            this->end_date_label->Name = L"end_date_label";
            this->end_date_label->Size = System::Drawing::Size(56, 13);
            this->end_date_label->TabIndex = 16;
            this->end_date_label->Text = L"End date: ";
            // 
            // guest_passport_label
            // 
            this->guest_passport_label->AutoSize = true;
            this->guest_passport_label->Location = System::Drawing::Point(288, 261);
            this->guest_passport_label->Name = L"guest_passport_label";
            this->guest_passport_label->Size = System::Drawing::Size(81, 13);
            this->guest_passport_label->TabIndex = 17;
            this->guest_passport_label->Text = L"Guest passport:";
            // 
            // create_button
            // 
            this->create_button->Location = System::Drawing::Point(288, 363);
            this->create_button->Name = L"create_button";
            this->create_button->Size = System::Drawing::Size(100, 40);
            this->create_button->TabIndex = 14;
            this->create_button->Text = L"Create";
            this->create_button->UseVisualStyleBackColor = true;
            this->create_button->Click += gcnew System::EventHandler(this, &CreateBookingScreen::create_button_Click);
            // 
            // start_date_time_picker
            // 
            this->start_date_time_picker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->start_date_time_picker->Location = System::Drawing::Point(374, 198);
            this->start_date_time_picker->Name = L"start_date_time_picker";
            this->start_date_time_picker->Size = System::Drawing::Size(120, 20);
            this->start_date_time_picker->TabIndex = 25;
            // 
            // end_date_time_picker
            // 
            this->end_date_time_picker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->end_date_time_picker->Location = System::Drawing::Point(376, 228);
            this->end_date_time_picker->Name = L"end_date_time_picker";
            this->end_date_time_picker->Size = System::Drawing::Size(119, 20);
            this->end_date_time_picker->TabIndex = 26;
            // 
            // open_booking_button
            // 
            this->open_booking_button->Location = System::Drawing::Point(353, 409);
            this->open_booking_button->Name = L"open_booking_button";
            this->open_booking_button->Size = System::Drawing::Size(94, 42);
            this->open_booking_button->TabIndex = 27;
            this->open_booking_button->Text = L"Open booking";
            this->open_booking_button->UseVisualStyleBackColor = true;
            this->open_booking_button->Visible = false;
            this->open_booking_button->Click += gcnew System::EventHandler(this, &CreateBookingScreen::open_booking_button_Click);
            // 
            // add_again_button
            // 
            this->add_again_button->Location = System::Drawing::Point(288, 363);
            this->add_again_button->Name = L"add_again_button";
            this->add_again_button->Size = System::Drawing::Size(100, 40);
            this->add_again_button->TabIndex = 30;
            this->add_again_button->Text = L"Add again";
            this->add_again_button->UseVisualStyleBackColor = true;
            this->add_again_button->Visible = false;
            this->add_again_button->Click += gcnew System::EventHandler(this, &CreateBookingScreen::add_again_button_Click);
            // 
            // CreateBookingScreen
            // 
            this->BackColor = System::Drawing::SystemColors::Control;
            this->Controls->Add(this->add_again_button);
            this->Controls->Add(this->open_booking_button);
            this->Controls->Add(this->end_date_time_picker);
            this->Controls->Add(this->start_date_time_picker);
            this->Controls->Add(this->back_button);
            this->Controls->Add(this->room_number_text_box);
            this->Controls->Add(this->staff_passport_text_box);
            this->Controls->Add(this->guest_passport_text_box);
            this->Controls->Add(this->room_number_label);
            this->Controls->Add(this->start_date_label);
            this->Controls->Add(this->staff_passport_label);
            this->Controls->Add(this->end_date_label);
            this->Controls->Add(this->guest_passport_label);
            this->Controls->Add(this->create_button);
            this->Name = L"CreateBookingScreen";
            this->Size = System::Drawing::Size(800, 600);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
    private: System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e) {
        clear_fields();
        enable_fields();
        _parent->GoBack();
    }
    private: System::Void create_button_Click(System::Object^ sender, System::EventArgs^ e);
    private:
        void disable_fields() {
            guest_passport_text_box->Enabled = false;
            staff_passport_text_box->Enabled = false;
            room_number_text_box->Enabled = false;
            start_date_time_picker->Enabled = false;
            end_date_time_picker->Enabled = false;
            create_button->Visible = false;
            add_again_button->Visible = true;
            open_booking_button->Visible = true;
        }

        void enable_fields() {
            guest_passport_text_box->Enabled = true;
            staff_passport_text_box->Enabled = true;
            room_number_text_box->Enabled = true;
            start_date_time_picker->Enabled = true;
            end_date_time_picker->Enabled = true;
            create_button->Visible = true;
            add_again_button->Visible = false;
            open_booking_button->Visible = false;
        }

        void clear_fields() {
            guest_passport_text_box->Text = System::String::Empty;
            staff_passport_text_box->Text = System::String::Empty;
            room_number_text_box->Text = System::String::Empty;
            start_date_time_picker->Value = DateTime::Now;
            end_date_time_picker->Value = DateTime::Now;
        }

        bool check_dates(String^ startDateStr, String^ endDateStr) {
            DateTime startDate;
            DateTime endDate;
            DateTime today = DateTime::Today;

            bool startParsed = DateTime::TryParse(startDateStr, startDate);
            bool endParsed = DateTime::TryParse(endDateStr, endDate);

            if (!startParsed || !endParsed) {
                MessageBox::Show("Invalid date format.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return false;
            }

            if (startDate > endDate) {
                MessageBox::Show("Start date cannot be later than end date.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return false;
            }

            if (startDate < today) {
                MessageBox::Show("Start date cannot be later than today.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return false;
            }

            return true;
        }

    private: System::Void add_again_button_Click(System::Object^ sender, System::EventArgs^ e) {
        clear_fields();
        enable_fields();
    }
    private: System::Void open_booking_button_Click(System::Object^ sender, System::EventArgs^ e) {
        clear_fields();
        enable_fields();
        _parent->ShowBookingScreen(_current_booking);
    }
    };
}
