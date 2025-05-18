#pragma once
#include "iwindow.h"
#include "irooms.h"
#include "iroom.h"
#include "TVector.h"

namespace CppCLRWinFormsProject
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class RoomSearchScreen : UserControl
    {
        IWindow^ _parent;
        IRooms* _rooms;
    private: System::Windows::Forms::Label^ result_label;
           TVector<IRoom*>* _search_result;
    public:
        RoomSearchScreen(IWindow^ parent, IRooms* rooms) : _parent(parent), _rooms(rooms) {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~RoomSearchScreen()
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

    protected:
    private: System::Windows::Forms::Label^ room_number_label;
    private: System::Windows::Forms::FlowLayoutPanel^ search_result_panel;
    private: System::Windows::Forms::Button^ back_button;
    private: System::Windows::Forms::Button^ saerch_button;
    private: System::Windows::Forms::Label^ state_label;
    private: System::Windows::Forms::Label^ beds_count_label;
    private: System::Windows::Forms::Label^ category_label;
    private: System::Windows::Forms::TextBox^ category_text_box;
    private: System::Windows::Forms::TextBox^ beds_count_text_box;
    private: System::Windows::Forms::TextBox^ state_text_box;
    private: System::Windows::Forms::TextBox^ number_text_box;

    protected:
        /// <summary> 
        /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->room_number_label = (gcnew System::Windows::Forms::Label());
            this->search_result_panel = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->saerch_button = (gcnew System::Windows::Forms::Button());
            this->state_label = (gcnew System::Windows::Forms::Label());
            this->beds_count_label = (gcnew System::Windows::Forms::Label());
            this->category_label = (gcnew System::Windows::Forms::Label());
            this->category_text_box = (gcnew System::Windows::Forms::TextBox());
            this->beds_count_text_box = (gcnew System::Windows::Forms::TextBox());
            this->state_text_box = (gcnew System::Windows::Forms::TextBox());
            this->number_text_box = (gcnew System::Windows::Forms::TextBox());
            this->result_label = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // room_number_label
            // 
            this->room_number_label->AutoSize = true;
            this->room_number_label->Location = System::Drawing::Point(274, 124);
            this->room_number_label->Name = L"room_number_label";
            this->room_number_label->Size = System::Drawing::Size(50, 13);
            this->room_number_label->TabIndex = 20;
            this->room_number_label->Text = L"Number: ";
            // 
            // search_result_panel
            // 
            this->search_result_panel->AutoScroll = true;
            this->search_result_panel->Location = System::Drawing::Point(277, 347);
            this->search_result_panel->Name = L"search_result_panel";
            this->search_result_panel->Size = System::Drawing::Size(237, 120);
            this->search_result_panel->TabIndex = 16;
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(414, 270);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(100, 40);
            this->back_button->TabIndex = 15;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            this->back_button->Click += gcnew System::EventHandler(this, &RoomSearchScreen::clear_screen);
            this->back_button->Click += gcnew System::EventHandler(this, &RoomSearchScreen::back_button_Click);
            // 
            // saerch_button
            // 
            this->saerch_button->Location = System::Drawing::Point(277, 270);
            this->saerch_button->Name = L"saerch_button";
            this->saerch_button->Size = System::Drawing::Size(100, 40);
            this->saerch_button->TabIndex = 14;
            this->saerch_button->Text = L"Find";
            this->saerch_button->UseVisualStyleBackColor = true;
            this->saerch_button->Click += gcnew System::EventHandler(this, &RoomSearchScreen::saerch_button_Click);
            // 
            // state_label
            // 
            this->state_label->AutoSize = true;
            this->state_label->Location = System::Drawing::Point(274, 234);
            this->state_label->Name = L"state_label";
            this->state_label->Size = System::Drawing::Size(38, 13);
            this->state_label->TabIndex = 13;
            this->state_label->Text = L"State: ";
            // 
            // beds_count_label
            // 
            this->beds_count_label->AutoSize = true;
            this->beds_count_label->Location = System::Drawing::Point(274, 155);
            this->beds_count_label->Name = L"beds_count_label";
            this->beds_count_label->Size = System::Drawing::Size(67, 13);
            this->beds_count_label->TabIndex = 12;
            this->beds_count_label->Text = L"Beds count: ";
            // 
            // category_label
            // 
            this->category_label->AutoSize = true;
            this->category_label->Location = System::Drawing::Point(274, 193);
            this->category_label->Name = L"category_label";
            this->category_label->Size = System::Drawing::Size(55, 13);
            this->category_label->TabIndex = 11;
            this->category_label->Text = L"Category: ";
            // 
            // category_text_box
            // 
            this->category_text_box->Location = System::Drawing::Point(347, 190);
            this->category_text_box->Name = L"category_text_box";
            this->category_text_box->Size = System::Drawing::Size(122, 20);
            this->category_text_box->TabIndex = 21;
            // 
            // beds_count_text_box
            // 
            this->beds_count_text_box->Location = System::Drawing::Point(347, 121);
            this->beds_count_text_box->Name = L"beds_count_text_box";
            this->beds_count_text_box->Size = System::Drawing::Size(122, 20);
            this->beds_count_text_box->TabIndex = 22;
            // 
            // state_text_box
            // 
            this->state_text_box->Location = System::Drawing::Point(347, 231);
            this->state_text_box->Name = L"state_text_box";
            this->state_text_box->Size = System::Drawing::Size(122, 20);
            this->state_text_box->TabIndex = 23;
            // 
            // number_text_box
            // 
            this->number_text_box->Location = System::Drawing::Point(347, 152);
            this->number_text_box->Name = L"number_text_box";
            this->number_text_box->Size = System::Drawing::Size(122, 20);
            this->number_text_box->TabIndex = 24;
            // 
            // result_label
            // 
            this->result_label->AutoSize = true;
            this->result_label->Location = System::Drawing::Point(282, 324);
            this->result_label->Name = L"result_label";
            this->result_label->Size = System::Drawing::Size(48, 13);
            this->result_label->TabIndex = 25;
            this->result_label->Text = L"Results: ";
            // 
            // RoomSearchScreen
            // 
            this->BackColor = System::Drawing::SystemColors::Control;
            this->Controls->Add(this->result_label);
            this->Controls->Add(this->number_text_box);
            this->Controls->Add(this->state_text_box);
            this->Controls->Add(this->beds_count_text_box);
            this->Controls->Add(this->category_text_box);
            this->Controls->Add(this->room_number_label);
            this->Controls->Add(this->search_result_panel);
            this->Controls->Add(this->back_button);
            this->Controls->Add(this->saerch_button);
            this->Controls->Add(this->state_label);
            this->Controls->Add(this->beds_count_label);
            this->Controls->Add(this->category_label);
            this->Name = L"RoomSearchScreen";
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
            number_text_box->Text = System::String::Empty;
            category_text_box->Text = System::String::Empty;
            state_text_box->Text = System::String::Empty;
            beds_count_text_box->Text = System::String::Empty;
            search_result_panel->Controls->Clear();
        }
};
}
