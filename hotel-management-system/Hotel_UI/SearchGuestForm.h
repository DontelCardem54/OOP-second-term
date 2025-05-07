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
    /// Summary for SearchGuestForm
    /// </summary>
    public ref class SearchGuestForm : public System::Windows::Forms::Form
    {
    private:
        Hotel* _hotel;

    public:
        SearchGuestForm(Hotel* hotel) : _hotel(hotel)
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
        ~SearchGuestForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ passport_label;
    protected:


    private: System::Windows::Forms::Label^ birth_date_label;

    private: System::Windows::Forms::Button^ saerch_button;
    private: System::Windows::Forms::Button^ back_button;
    private: System::Windows::Forms::FlowLayoutPanel^ search_result_panel;
    private: System::Windows::Forms::TextBox^ passport_text_box;
    private: System::Windows::Forms::TextBox^ birth_date_text_box;







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
            this->passport_label = (gcnew System::Windows::Forms::Label());
            this->birth_date_label = (gcnew System::Windows::Forms::Label());
            this->saerch_button = (gcnew System::Windows::Forms::Button());
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->search_result_panel = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->passport_text_box = (gcnew System::Windows::Forms::TextBox());
            this->birth_date_text_box = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            // 
            // passport_label
            // 
            this->passport_label->AutoSize = true;
            this->passport_label->Location = System::Drawing::Point(28, 40);
            this->passport_label->Name = L"passport_label";
            this->passport_label->Size = System::Drawing::Size(54, 13);
            this->passport_label->TabIndex = 0;
            this->passport_label->Text = L"Passport: ";
            // 
            // birth_date_label
            // 
            this->birth_date_label->AutoSize = true;
            this->birth_date_label->Location = System::Drawing::Point(28, 81);
            this->birth_date_label->Name = L"birth_date_label";
            this->birth_date_label->Size = System::Drawing::Size(52, 13);
            this->birth_date_label->TabIndex = 2;
            this->birth_date_label->Text = L"Birth date";
            // 
            // saerch_button
            // 
            this->saerch_button->Location = System::Drawing::Point(31, 117);
            this->saerch_button->Name = L"saerch_button";
            this->saerch_button->Size = System::Drawing::Size(100, 40);
            this->saerch_button->TabIndex = 3;
            this->saerch_button->Text = L"Найти";
            this->saerch_button->UseVisualStyleBackColor = true;
            this->saerch_button->Click += gcnew System::EventHandler(this, &SearchGuestForm::saerch_button_Click);
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(168, 117);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(100, 40);
            this->back_button->TabIndex = 4;
            this->back_button->Text = L"Назад";
            this->back_button->UseVisualStyleBackColor = true;
            this->back_button->Click += gcnew System::EventHandler(this, &SearchGuestForm::back_button_Click);
            // 
            // search_result_panel
            // 
            this->search_result_panel->AutoScroll = true;
            this->search_result_panel->Location = System::Drawing::Point(33, 172);
            this->search_result_panel->Name = L"search_result_panel";
            this->search_result_panel->Size = System::Drawing::Size(357, 120);
            this->search_result_panel->TabIndex = 5;
            // 
            // passport_text_box
            // 
            this->passport_text_box->Location = System::Drawing::Point(86, 37);
            this->passport_text_box->Name = L"passport_text_box";
            this->passport_text_box->Size = System::Drawing::Size(93, 20);
            this->passport_text_box->TabIndex = 6;
            // 
            // birth_date_text_box
            // 
            this->birth_date_text_box->Location = System::Drawing::Point(86, 78);
            this->birth_date_text_box->Name = L"birth_date_text_box";
            this->birth_date_text_box->Size = System::Drawing::Size(93, 20);
            this->birth_date_text_box->TabIndex = 7;
            // 
            // SearchGuestForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(422, 304);
            this->Controls->Add(this->birth_date_text_box);
            this->Controls->Add(this->passport_text_box);
            this->Controls->Add(this->search_result_panel);
            this->Controls->Add(this->back_button);
            this->Controls->Add(this->saerch_button);
            this->Controls->Add(this->birth_date_label);
            this->Controls->Add(this->passport_label);
            this->Name = L"SearchGuestForm";
            this->Text = L"Search guest";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void saerch_button_Click(System::Object^ sender, System::EventArgs^ e) {
        search_result_panel->Controls->Clear();

        // Пример результатов поиска (можно заменить на реальный запрос)
        array<String^>^ rooms = { "Guest-1", "Guest-2", "Guest-3" };

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
