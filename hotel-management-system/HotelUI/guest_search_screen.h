#pragma once

#include "iwindow.h"
#include "iguests.h"
#include "iguest.h"
#include "TVector.h"

namespace CppCLRWinFormsProject
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class GuestSearchScreen : UserControl
    {
    private:
        IWindow^ _parent;
        IGuests* _guests;
        TVector<IGuest*>* _search_result;

    private: System::Windows::Forms::Label^ result_label;
           

    public:
        GuestSearchScreen(IWindow^ parent, IGuests* guests) : _parent(parent), _guests(guests), _search_result(nullptr) {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~GuestSearchScreen()
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

    private: System::Windows::Forms::TextBox^ passport_text_box;
    private: System::Windows::Forms::FlowLayoutPanel^ search_result_panel;
    private: System::Windows::Forms::Button^ back_button;
    private: System::Windows::Forms::Button^ saerch_button;

    private: System::Windows::Forms::Label^ passport_label;
    protected:

        /// <summary> 
        /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
    private:
        System::ComponentModel::Container^ components;
        void InitializeComponent(void)
        {
            this->passport_text_box = (gcnew System::Windows::Forms::TextBox());
            this->search_result_panel = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->saerch_button = (gcnew System::Windows::Forms::Button());
            this->passport_label = (gcnew System::Windows::Forms::Label());
            this->result_label = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // passport_text_box
            // 
            this->passport_text_box->Location = System::Drawing::Point(335, 211);
            this->passport_text_box->Name = L"passport_text_box";
            this->passport_text_box->Size = System::Drawing::Size(93, 20);
            this->passport_text_box->TabIndex = 13;
            // 
            // search_result_panel
            // 
            this->search_result_panel->AutoScroll = true;
            this->search_result_panel->Location = System::Drawing::Point(278, 328);
            this->search_result_panel->Name = L"search_result_panel";
            this->search_result_panel->Size = System::Drawing::Size(237, 120);
            this->search_result_panel->TabIndex = 12;
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(415, 254);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(100, 40);
            this->back_button->TabIndex = 11;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            this->back_button->Click += gcnew System::EventHandler(this, &GuestSearchScreen::back_button_Click);
            // 
            // saerch_button
            // 
            this->saerch_button->Location = System::Drawing::Point(278, 254);
            this->saerch_button->Name = L"saerch_button";
            this->saerch_button->Size = System::Drawing::Size(100, 40);
            this->saerch_button->TabIndex = 10;
            this->saerch_button->Text = L"Find";
            this->saerch_button->UseVisualStyleBackColor = true;
            this->saerch_button->Click += gcnew System::EventHandler(this, &GuestSearchScreen::saerch_button_Click);
            // 
            // passport_label
            // 
            this->passport_label->AutoSize = true;
            this->passport_label->Location = System::Drawing::Point(277, 214);
            this->passport_label->Name = L"passport_label";
            this->passport_label->Size = System::Drawing::Size(54, 13);
            this->passport_label->TabIndex = 8;
            this->passport_label->Text = L"Passport: ";
            // 
            // result_label
            // 
            this->result_label->AutoSize = true;
            this->result_label->Location = System::Drawing::Point(282, 312);
            this->result_label->Name = L"result_label";
            this->result_label->Size = System::Drawing::Size(45, 13);
            this->result_label->TabIndex = 15;
            this->result_label->Text = L"Results:";
            // 
            // GuestSearchScreen
            // 
            this->BackColor = System::Drawing::SystemColors::Control;
            this->Controls->Add(this->result_label);
            this->Controls->Add(this->passport_text_box);
            this->Controls->Add(this->search_result_panel);
            this->Controls->Add(this->back_button);
            this->Controls->Add(this->saerch_button);
            this->Controls->Add(this->passport_label);
            this->Name = L"GuestSearchScreen";
            this->Size = System::Drawing::Size(800, 600);
            this->ResumeLayout(false);
            this->PerformLayout();

        }


    private: System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e) {
        result_label->Text = "Results:";
        passport_text_box->Text = System::String::Empty;
        search_result_panel->Controls->Clear();
        _parent->GoBack();
    }

    private: System::Void saerch_button_Click(System::Object^ sender, System::EventArgs^ e);

    private:
        System::Void go_to_button_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void clear_screen(System::Object^ sender, System::EventArgs^ e) {
            result_label->Text = "Results:";
            passport_text_box->Text = System::String::Empty;
            search_result_panel->Controls->Clear();
        }
        System::Void add_guest_button_Click(System::Object^ sender, System::EventArgs^ e) {
            _parent->ShowAddGuestScreen();
        }
};
}