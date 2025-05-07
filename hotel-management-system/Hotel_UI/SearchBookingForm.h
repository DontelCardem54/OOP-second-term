#pragma once

//#include "AdminForm.h"
#include "hotel.h"

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for SearchBookingForm
    /// </summary>
    public ref class SearchBookingForm : public System::Windows::Forms::Form
    {
    private:
        Hotel* _hotel;

    public:
        SearchBookingForm(Hotel* hotel) : _hotel(hotel)
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
        ~SearchBookingForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ start_date_label;
    private: System::Windows::Forms::Label^ end_date_label;
    private: System::Windows::Forms::Label^ guest_passport_label;
    protected:



    protected:




    private: System::Windows::Forms::Button^ saerch_button;
    private: System::Windows::Forms::Button^ back_button;
    private: System::Windows::Forms::FlowLayoutPanel^ search_result_panel;



    private: System::Windows::Forms::Label^ room_number_label;

    private: System::Windows::Forms::ComboBox^ room_number_combo_box;
    private: System::Windows::Forms::TextBox^ start_date_text_box;
    private: System::Windows::Forms::TextBox^ end_date_text_box;
    private: System::Windows::Forms::TextBox^ guest_passport_text_box;

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
            this->guest_passport_label = (gcnew System::Windows::Forms::Label());
            this->saerch_button = (gcnew System::Windows::Forms::Button());
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->search_result_panel = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->room_number_label = (gcnew System::Windows::Forms::Label());
            this->room_number_combo_box = (gcnew System::Windows::Forms::ComboBox());
            this->start_date_text_box = (gcnew System::Windows::Forms::TextBox());
            this->end_date_text_box = (gcnew System::Windows::Forms::TextBox());
            this->guest_passport_text_box = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            // 
            // start_date_label
            // 
            this->start_date_label->AutoSize = true;
            this->start_date_label->Location = System::Drawing::Point(28, 40);
            this->start_date_label->Name = L"start_date_label";
            this->start_date_label->Size = System::Drawing::Size(56, 13);
            this->start_date_label->TabIndex = 0;
            this->start_date_label->Text = L"Start date:";
            // 
            // end_date_label
            // 
            this->end_date_label->AutoSize = true;
            this->end_date_label->Location = System::Drawing::Point(201, 40);
            this->end_date_label->Name = L"end_date_label";
            this->end_date_label->Size = System::Drawing::Size(56, 13);
            this->end_date_label->TabIndex = 1;
            this->end_date_label->Text = L"End date: ";
            // 
            // guest_passport_label
            // 
            this->guest_passport_label->AutoSize = true;
            this->guest_passport_label->Location = System::Drawing::Point(28, 81);
            this->guest_passport_label->Name = L"guest_passport_label";
            this->guest_passport_label->Size = System::Drawing::Size(81, 13);
            this->guest_passport_label->TabIndex = 2;
            this->guest_passport_label->Text = L"Guest passport:";
            // 
            // saerch_button
            // 
            this->saerch_button->Location = System::Drawing::Point(31, 117);
            this->saerch_button->Name = L"saerch_button";
            this->saerch_button->Size = System::Drawing::Size(100, 40);
            this->saerch_button->TabIndex = 3;
            this->saerch_button->Text = L"Найти";
            this->saerch_button->UseVisualStyleBackColor = true;
            this->saerch_button->Click += gcnew System::EventHandler(this, &SearchBookingForm::saerch_button_Click);
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(168, 117);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(100, 40);
            this->back_button->TabIndex = 4;
            this->back_button->Text = L"Назад";
            this->back_button->UseVisualStyleBackColor = true;
            this->back_button->Click += gcnew System::EventHandler(this, &SearchBookingForm::back_button_Click);
            // 
            // search_result_panel
            // 
            this->search_result_panel->AutoScroll = true;
            this->search_result_panel->Location = System::Drawing::Point(33, 172);
            this->search_result_panel->Name = L"search_result_panel";
            this->search_result_panel->Size = System::Drawing::Size(357, 120);
            this->search_result_panel->TabIndex = 5;
            // 
            // room_number_label
            // 
            this->room_number_label->AutoSize = true;
            this->room_number_label->Location = System::Drawing::Point(189, 81);
            this->room_number_label->Name = L"room_number_label";
            this->room_number_label->Size = System::Drawing::Size(79, 13);
            this->room_number_label->TabIndex = 9;
            this->room_number_label->Text = L"Room number: ";
            // 
            // room_number_combo_box
            // 
            this->room_number_combo_box->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->room_number_combo_box->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->room_number_combo_box->FormattingEnabled = true;
            this->room_number_combo_box->Location = System::Drawing::Point(274, 78);
            this->room_number_combo_box->Name = L"room_number_combo_box";
            this->room_number_combo_box->Size = System::Drawing::Size(64, 21);
            this->room_number_combo_box->TabIndex = 10;
            // 
            // start_date_text_box
            // 
            this->start_date_text_box->Location = System::Drawing::Point(96, 39);
            this->start_date_text_box->Name = L"start_date_text_box";
            this->start_date_text_box->Size = System::Drawing::Size(72, 20);
            this->start_date_text_box->TabIndex = 11;
            // 
            // end_date_text_box
            // 
            this->end_date_text_box->Location = System::Drawing::Point(261, 41);
            this->end_date_text_box->Name = L"end_date_text_box";
            this->end_date_text_box->Size = System::Drawing::Size(86, 20);
            this->end_date_text_box->TabIndex = 12;
            // 
            // guest_passport_text_box
            // 
            this->guest_passport_text_box->Location = System::Drawing::Point(115, 78);
            this->guest_passport_text_box->Name = L"guest_passport_text_box";
            this->guest_passport_text_box->Size = System::Drawing::Size(53, 20);
            this->guest_passport_text_box->TabIndex = 13;
            // 
            // SearchBookingForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(422, 304);
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
            this->Name = L"SearchBookingForm";
            this->Text = L"Search Booking";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void saerch_button_Click(System::Object^ sender, System::EventArgs^ e) {
        search_result_panel->Controls->Clear();

        // Пример результатов поиска (можно заменить на реальный запрос)
        array<String^>^ rooms = { "Номер 101", "Номер 102", "Номер 103" };

        // Добавляем результаты в панель
        for (int i = 0; i < rooms->Length; i++)
        {
            // Создаём новый Panel для группы Label и Button
            Panel^ roomPanel = gcnew Panel();
            roomPanel->Size = System::Drawing::Size(300, 35); // Устанавливаем размер для панели
            roomPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;


            // Создаём метку для каждого номера
            Label^ roomLabel = gcnew Label();
            roomLabel->Text = rooms[i];
            roomLabel->AutoSize = true;
            roomLabel->Location = System::Drawing::Point(10, 10); // Располагаем метку на панели

            // Создаём кнопку для перехода к номеру
            Button^ goButton = gcnew Button();
            goButton->Text = "Перейти";
            goButton->Location = System::Drawing::Point(200, 5); // Располагаем кнопку рядом с меткой
            //goButton->Click += gcnew EventHandler(this, &RoomSearchForm::GoButton_Click);

            // Добавляем метку и кнопку в панель
            roomPanel->Controls->Add(roomLabel);
            roomPanel->Controls->Add(goButton);

            // Добавляем панель в FlowLayoutPanel
            search_result_panel->Controls->Add(roomPanel);
        }
    }
    private: System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e);

    };
}
