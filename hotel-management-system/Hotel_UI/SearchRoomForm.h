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
    /// Summary for SearchRoomForm
    /// </summary>
    public ref class SearchRoomForm : public System::Windows::Forms::Form
    {
    private:
        Hotel* _hotel;

    public:
        SearchRoomForm(Hotel* hotel) : _hotel(hotel)
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
        ~SearchRoomForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ category_lable;
    private: System::Windows::Forms::Label^ beds_count_lable;
    private: System::Windows::Forms::Label^ state_lable;
    private: System::Windows::Forms::Button^ saerch_button;
    private: System::Windows::Forms::Button^ back_button;
    private: System::Windows::Forms::FlowLayoutPanel^ search_result_panel;
    private: System::Windows::Forms::ComboBox^ category_combo_box;
    private: System::Windows::Forms::ComboBox^ beds_count_combo_box;
    private: System::Windows::Forms::ComboBox^ state_combo_box;
    private: System::Windows::Forms::Label^ room_number_lable;
    private: System::Windows::Forms::ComboBox^ room_number_combo_box;

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
            this->category_lable = (gcnew System::Windows::Forms::Label());
            this->beds_count_lable = (gcnew System::Windows::Forms::Label());
            this->state_lable = (gcnew System::Windows::Forms::Label());
            this->saerch_button = (gcnew System::Windows::Forms::Button());
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->search_result_panel = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->category_combo_box = (gcnew System::Windows::Forms::ComboBox());
            this->beds_count_combo_box = (gcnew System::Windows::Forms::ComboBox());
            this->state_combo_box = (gcnew System::Windows::Forms::ComboBox());
            this->room_number_lable = (gcnew System::Windows::Forms::Label());
            this->room_number_combo_box = (gcnew System::Windows::Forms::ComboBox());
            this->SuspendLayout();
            // 
            // category_lable
            // 
            this->category_lable->AutoSize = true;
            this->category_lable->Location = System::Drawing::Point(28, 40);
            this->category_lable->Name = L"category_lable";
            this->category_lable->Size = System::Drawing::Size(66, 13);
            this->category_lable->TabIndex = 0;
            this->category_lable->Text = L"Категория: ";
            // 
            // beds_count_lable
            // 
            this->beds_count_lable->AutoSize = true;
            this->beds_count_lable->Location = System::Drawing::Point(201, 40);
            this->beds_count_lable->Name = L"beds_count_lable";
            this->beds_count_lable->Size = System::Drawing::Size(122, 13);
            this->beds_count_lable->TabIndex = 1;
            this->beds_count_lable->Text = L"Количество кроватей: ";
            // 
            // state_lable
            // 
            this->state_lable->AutoSize = true;
            this->state_lable->Location = System::Drawing::Point(28, 81);
            this->state_lable->Name = L"state_lable";
            this->state_lable->Size = System::Drawing::Size(47, 13);
            this->state_lable->TabIndex = 2;
            this->state_lable->Text = L"Статус: ";
            // 
            // saerch_button
            // 
            this->saerch_button->Location = System::Drawing::Point(31, 117);
            this->saerch_button->Name = L"saerch_button";
            this->saerch_button->Size = System::Drawing::Size(100, 40);
            this->saerch_button->TabIndex = 3;
            this->saerch_button->Text = L"Найти";
            this->saerch_button->UseVisualStyleBackColor = true;
            this->saerch_button->Click += gcnew System::EventHandler(this, &SearchRoomForm::saerch_button_Click);
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(168, 117);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(100, 40);
            this->back_button->TabIndex = 4;
            this->back_button->Text = L"Назад";
            this->back_button->UseVisualStyleBackColor = true;
            this->back_button->Click += gcnew System::EventHandler(this, &SearchRoomForm::back_button_Click);
            // 
            // search_result_panel
            // 
            this->search_result_panel->AutoScroll = true;
            this->search_result_panel->Location = System::Drawing::Point(33, 172);
            this->search_result_panel->Name = L"search_result_panel";
            this->search_result_panel->Size = System::Drawing::Size(357, 120);
            this->search_result_panel->TabIndex = 5;
            // 
            // category_combo_box
            // 
            this->category_combo_box->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->category_combo_box->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->category_combo_box->FormattingEnabled = true;
            this->category_combo_box->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Стандарт", L"Люкс", L"Президентский" });
            this->category_combo_box->Location = System::Drawing::Point(100, 37);
            this->category_combo_box->Name = L"category_combo_box";
            this->category_combo_box->Size = System::Drawing::Size(83, 21);
            this->category_combo_box->TabIndex = 6;
            // 
            // beds_count_combo_box
            // 
            this->beds_count_combo_box->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->beds_count_combo_box->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->beds_count_combo_box->FormattingEnabled = true;
            this->beds_count_combo_box->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"1", L"2", L"3" });
            this->beds_count_combo_box->Location = System::Drawing::Point(329, 37);
            this->beds_count_combo_box->Name = L"beds_count_combo_box";
            this->beds_count_combo_box->Size = System::Drawing::Size(61, 21);
            this->beds_count_combo_box->TabIndex = 7;
            // 
            // state_combo_box
            // 
            this->state_combo_box->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->state_combo_box->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->state_combo_box->FormattingEnabled = true;
            this->state_combo_box->Location = System::Drawing::Point(81, 76);
            this->state_combo_box->Name = L"state_combo_box";
            this->state_combo_box->Size = System::Drawing::Size(73, 21);
            this->state_combo_box->TabIndex = 8;
            // 
            // room_number_lable
            // 
            this->room_number_lable->AutoSize = true;
            this->room_number_lable->Location = System::Drawing::Point(186, 81);
            this->room_number_lable->Name = L"room_number_lable";
            this->room_number_lable->Size = System::Drawing::Size(47, 13);
            this->room_number_lable->TabIndex = 9;
            this->room_number_lable->Text = L"Номер: ";
            // 
            // room_number_combo_box
            // 
            this->room_number_combo_box->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->room_number_combo_box->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->room_number_combo_box->FormattingEnabled = true;
            this->room_number_combo_box->Location = System::Drawing::Point(239, 78);
            this->room_number_combo_box->Name = L"room_number_combo_box";
            this->room_number_combo_box->Size = System::Drawing::Size(64, 21);
            this->room_number_combo_box->TabIndex = 10;
            // 
            // SearchRoomForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(422, 304);
            this->Controls->Add(this->room_number_combo_box);
            this->Controls->Add(this->room_number_lable);
            this->Controls->Add(this->state_combo_box);
            this->Controls->Add(this->beds_count_combo_box);
            this->Controls->Add(this->category_combo_box);
            this->Controls->Add(this->search_result_panel);
            this->Controls->Add(this->back_button);
            this->Controls->Add(this->saerch_button);
            this->Controls->Add(this->state_lable);
            this->Controls->Add(this->beds_count_lable);
            this->Controls->Add(this->category_lable);
            this->Name = L"SearchRoomForm";
            this->Text = L"Поиск номера";
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
