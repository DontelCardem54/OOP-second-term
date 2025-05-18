#pragma once
#include "iwindow.h"

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

    public:
        BookingSearchScreen(IWindow^ parent) : _parent(parent) {
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
        }
    private: System::Windows::Forms::TextBox^ guest_passport_text_box;
    protected:
    private: System::Windows::Forms::TextBox^ end_date_text_box;
    private: System::Windows::Forms::TextBox^ start_date_text_box;
    private: System::Windows::Forms::ComboBox^ room_number_combo_box;
    private: System::Windows::Forms::Label^ room_number_label;
    private: System::Windows::Forms::FlowLayoutPanel^ search_result_panel;
    private: System::Windows::Forms::Button^ back_button;
    private: System::Windows::Forms::Button^ saerch_button;
    private: System::Windows::Forms::Label^ guest_passport_label;
    private: System::Windows::Forms::Label^ end_date_label;
    private: System::Windows::Forms::Label^ start_date_label;
           /// <summary> 
        /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->guest_passport_text_box = (gcnew System::Windows::Forms::TextBox());
            this->end_date_text_box = (gcnew System::Windows::Forms::TextBox());
            this->start_date_text_box = (gcnew System::Windows::Forms::TextBox());
            this->room_number_combo_box = (gcnew System::Windows::Forms::ComboBox());
            this->room_number_label = (gcnew System::Windows::Forms::Label());
            this->search_result_panel = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->saerch_button = (gcnew System::Windows::Forms::Button());
            this->guest_passport_label = (gcnew System::Windows::Forms::Label());
            this->end_date_label = (gcnew System::Windows::Forms::Label());
            this->start_date_label = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // guest_passport_text_box
            // 
            this->guest_passport_text_box->Location = System::Drawing::Point(306, 213);
            this->guest_passport_text_box->Name = L"guest_passport_text_box";
            this->guest_passport_text_box->Size = System::Drawing::Size(53, 20);
            this->guest_passport_text_box->TabIndex = 24;
            // 
            // end_date_text_box
            // 
            this->end_date_text_box->Location = System::Drawing::Point(452, 176);
            this->end_date_text_box->Name = L"end_date_text_box";
            this->end_date_text_box->Size = System::Drawing::Size(86, 20);
            this->end_date_text_box->TabIndex = 23;
            // 
            // start_date_text_box
            // 
            this->start_date_text_box->Location = System::Drawing::Point(287, 174);
            this->start_date_text_box->Name = L"start_date_text_box";
            this->start_date_text_box->Size = System::Drawing::Size(72, 20);
            this->start_date_text_box->TabIndex = 22;
            // 
            // room_number_combo_box
            // 
            this->room_number_combo_box->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->room_number_combo_box->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->room_number_combo_box->FormattingEnabled = true;
            this->room_number_combo_box->Location = System::Drawing::Point(465, 213);
            this->room_number_combo_box->Name = L"room_number_combo_box";
            this->room_number_combo_box->Size = System::Drawing::Size(64, 21);
            this->room_number_combo_box->TabIndex = 21;
            // 
            // room_number_label
            // 
            this->room_number_label->AutoSize = true;
            this->room_number_label->Location = System::Drawing::Point(380, 216);
            this->room_number_label->Name = L"room_number_label";
            this->room_number_label->Size = System::Drawing::Size(79, 13);
            this->room_number_label->TabIndex = 20;
            this->room_number_label->Text = L"Room number: ";
            // 
            // search_result_panel
            // 
            this->search_result_panel->AutoScroll = true;
            this->search_result_panel->Location = System::Drawing::Point(224, 307);
            this->search_result_panel->Name = L"search_result_panel";
            this->search_result_panel->Size = System::Drawing::Size(357, 120);
            this->search_result_panel->TabIndex = 19;
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(359, 252);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(100, 40);
            this->back_button->TabIndex = 18;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            this->back_button->Click += gcnew System::EventHandler(this, &BookingSearchScreen::back_button_Click);
            // 
            // saerch_button
            // 
            this->saerch_button->Location = System::Drawing::Point(222, 252);
            this->saerch_button->Name = L"saerch_button";
            this->saerch_button->Size = System::Drawing::Size(100, 40);
            this->saerch_button->TabIndex = 17;
            this->saerch_button->Text = L"Find";
            this->saerch_button->UseVisualStyleBackColor = true;
            // 
            // guest_passport_label
            // 
            this->guest_passport_label->AutoSize = true;
            this->guest_passport_label->Location = System::Drawing::Point(219, 216);
            this->guest_passport_label->Name = L"guest_passport_label";
            this->guest_passport_label->Size = System::Drawing::Size(81, 13);
            this->guest_passport_label->TabIndex = 16;
            this->guest_passport_label->Text = L"Guest passport:";
            // 
            // end_date_label
            // 
            this->end_date_label->AutoSize = true;
            this->end_date_label->Location = System::Drawing::Point(392, 175);
            this->end_date_label->Name = L"end_date_label";
            this->end_date_label->Size = System::Drawing::Size(56, 13);
            this->end_date_label->TabIndex = 15;
            this->end_date_label->Text = L"End date: ";
            // 
            // start_date_label
            // 
            this->start_date_label->AutoSize = true;
            this->start_date_label->Location = System::Drawing::Point(219, 175);
            this->start_date_label->Name = L"start_date_label";
            this->start_date_label->Size = System::Drawing::Size(56, 13);
            this->start_date_label->TabIndex = 14;
            this->start_date_label->Text = L"Start date:";
            // 
            // BookingSearchScreen
            // 
            this->BackColor = System::Drawing::SystemColors::Control;
            this->Controls->Add(this->guest_passport_text_box);
            this->Controls->Add(this->end_date_text_box);
            this->Controls->Add(this->start_date_text_box);
            this->Controls->Add(this->room_number_combo_box);
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
};
}
