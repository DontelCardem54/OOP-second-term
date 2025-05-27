#pragma once
#include "iwindow.h"
#include "ibookings.h"
#include "iguests.h"

namespace CppCLRWinFormsProject
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class BookingSearchScreen : UserControl
    {
    private:
        IWindow^ _parent;
        IBookings* _bookings;
        IGuests* _guests;
        TVector<IBooking*>* _search_result;
    public:
        BookingSearchScreen(IWindow^ parent, IBookings* bookings, IGuests* guests) : _parent(parent), _bookings(bookings), _guests(guests) {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~BookingSearchScreen()
        {
            if (components)
            {
                delete components;
            }
            if (_search_result != nullptr) {
                for (int i = 0; i < _search_result->size(); i++) {
                    delete(*_search_result)[i];
                }

                delete _search_result;
            }
        }
    private: System::Windows::Forms::TextBox^ guest_passport_text_box;
    private: System::Windows::Forms::Label^ result_label;
    private: System::Windows::Forms::Label^ room_number_label;
    private: System::Windows::Forms::FlowLayoutPanel^ search_result_panel;
    private: System::Windows::Forms::Button^ back_button;
    private: System::Windows::Forms::Button^ saerch_button;
    private: System::Windows::Forms::Label^ guest_passport_label;
    private: System::Windows::Forms::Label^ end_date_label;
    private: System::Windows::Forms::Label^ start_date_label;
    private: System::Windows::Forms::TextBox^ room_number_text_box;
    private: System::Windows::Forms::DateTimePicker^ start_date_time_picker;
    private: System::Windows::Forms::DateTimePicker^ end_date_time_picker;
           /// <summary> 
        /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->guest_passport_text_box = (gcnew System::Windows::Forms::TextBox());
            this->room_number_label = (gcnew System::Windows::Forms::Label());
            this->search_result_panel = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->saerch_button = (gcnew System::Windows::Forms::Button());
            this->guest_passport_label = (gcnew System::Windows::Forms::Label());
            this->end_date_label = (gcnew System::Windows::Forms::Label());
            this->start_date_label = (gcnew System::Windows::Forms::Label());
            this->room_number_text_box = (gcnew System::Windows::Forms::TextBox());
            this->start_date_time_picker = (gcnew System::Windows::Forms::DateTimePicker());
            this->end_date_time_picker = (gcnew System::Windows::Forms::DateTimePicker());
            this->result_label = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // guest_passport_text_box
            // 
            this->guest_passport_text_box->Location = System::Drawing::Point(371, 204);
            this->guest_passport_text_box->Name = L"guest_passport_text_box";
            this->guest_passport_text_box->Size = System::Drawing::Size(96, 20);
            this->guest_passport_text_box->TabIndex = 24;
            // 
            // room_number_label
            // 
            this->room_number_label->AutoSize = true;
            this->room_number_label->Location = System::Drawing::Point(286, 233);
            this->room_number_label->Name = L"room_number_label";
            this->room_number_label->Size = System::Drawing::Size(79, 13);
            this->room_number_label->TabIndex = 20;
            this->room_number_label->Text = L"Room number: ";
            // 
            // search_result_panel
            // 
            this->search_result_panel->AutoScroll = true;
            this->search_result_panel->Location = System::Drawing::Point(264, 344);
            this->search_result_panel->Name = L"search_result_panel";
            this->search_result_panel->Size = System::Drawing::Size(330, 120);
            this->search_result_panel->TabIndex = 19;
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(399, 271);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(100, 40);
            this->back_button->TabIndex = 18;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            this->back_button->Click += gcnew System::EventHandler(this, &BookingSearchScreen::back_button_Click);
            // 
            // saerch_button
            // 
            this->saerch_button->Location = System::Drawing::Point(262, 271);
            this->saerch_button->Name = L"saerch_button";
            this->saerch_button->Size = System::Drawing::Size(100, 40);
            this->saerch_button->TabIndex = 17;
            this->saerch_button->Text = L"Find";
            this->saerch_button->UseVisualStyleBackColor = true;
            this->saerch_button->Click += gcnew System::EventHandler(this, &BookingSearchScreen::saerch_button_Click);
            // 
            // guest_passport_label
            // 
            this->guest_passport_label->AutoSize = true;
            this->guest_passport_label->Location = System::Drawing::Point(284, 210);
            this->guest_passport_label->Name = L"guest_passport_label";
            this->guest_passport_label->Size = System::Drawing::Size(81, 13);
            this->guest_passport_label->TabIndex = 16;
            this->guest_passport_label->Text = L"Guest passport:";
            // 
            // end_date_label
            // 
            this->end_date_label->AutoSize = true;
            this->end_date_label->Location = System::Drawing::Point(309, 184);
            this->end_date_label->Name = L"end_date_label";
            this->end_date_label->Size = System::Drawing::Size(56, 13);
            this->end_date_label->TabIndex = 15;
            this->end_date_label->Text = L"End date: ";
            // 
            // start_date_label
            // 
            this->start_date_label->AutoSize = true;
            this->start_date_label->Location = System::Drawing::Point(309, 153);
            this->start_date_label->Name = L"start_date_label";
            this->start_date_label->Size = System::Drawing::Size(56, 13);
            this->start_date_label->TabIndex = 14;
            this->start_date_label->Text = L"Start date:";
            // 
            // room_number_text_box
            // 
            this->room_number_text_box->Location = System::Drawing::Point(371, 230);
            this->room_number_text_box->Name = L"room_number_text_box";
            this->room_number_text_box->Size = System::Drawing::Size(96, 20);
            this->room_number_text_box->TabIndex = 25;
            // 
            // start_date_time_picker
            // 
            this->start_date_time_picker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->start_date_time_picker->Location = System::Drawing::Point(371, 147);
            this->start_date_time_picker->Name = L"start_date_time_picker";
            this->start_date_time_picker->Size = System::Drawing::Size(96, 20);
            this->start_date_time_picker->TabIndex = 26;
            // 
            // end_date_time_picker
            // 
            this->end_date_time_picker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->end_date_time_picker->Location = System::Drawing::Point(371, 178);
            this->end_date_time_picker->Name = L"end_date_time_picker";
            this->end_date_time_picker->Size = System::Drawing::Size(96, 20);
            this->end_date_time_picker->TabIndex = 27;
            // 
            // result_label
            // 
            this->result_label->AutoSize = true;
            this->result_label->Location = System::Drawing::Point(261, 328);
            this->result_label->Name = L"result_label";
            this->result_label->Size = System::Drawing::Size(48, 13);
            this->result_label->TabIndex = 28;
            this->result_label->Text = L"Results: ";
            // 
            // BookingSearchScreen
            // 
            this->BackColor = System::Drawing::SystemColors::Control;
            this->Controls->Add(this->result_label);
            this->Controls->Add(this->end_date_time_picker);
            this->Controls->Add(this->start_date_time_picker);
            this->Controls->Add(this->room_number_text_box);
            this->Controls->Add(this->guest_passport_text_box);
            this->Controls->Add(this->room_number_label);
            this->Controls->Add(this->search_result_panel);
            this->Controls->Add(this->back_button);
            this->Controls->Add(this->saerch_button);
            this->Controls->Add(this->guest_passport_label);
            this->Controls->Add(this->end_date_label);
            this->Controls->Add(this->start_date_label);
            this->Name = L"BookingSearchScreen";
            this->Size = System::Drawing::Size(800, 600);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
    private: System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e) {
        _parent->GoBack();
    }
    private: System::Void saerch_button_Click(System::Object^ sender, System::EventArgs^ e);
    private:
        System::Void go_to_button_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void clear_screen(System::Object^ sender, System::EventArgs^ e) {
            result_label->Text = "Results:";
            start_date_time_picker->Value = DateTime::Today;
            end_date_time_picker->Value = DateTime::Today;
            room_number_text_box->Text = System::String::Empty;
            guest_passport_text_box->Text = System::String::Empty;
            search_result_panel->Controls->Clear();
        }
    };
}
