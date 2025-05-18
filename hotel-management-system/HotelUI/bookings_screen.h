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

    public ref class BookingsScreen : UserControl
    {
    private:
        IWindow^ _parent;
    public:
        BookingsScreen(IWindow^ parent) : _parent(parent) {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~BookingsScreen()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ back_button;
    protected:
    private: System::Windows::Forms::Button^ search_booking_button;
    private: System::Windows::Forms::Button^ create_booking_button;
           /// <summary> 
        /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->search_booking_button = (gcnew System::Windows::Forms::Button());
            this->create_booking_button = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(346, 329);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(109, 39);
            this->back_button->TabIndex = 5;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            this->back_button->Click += gcnew System::EventHandler(this, &BookingsScreen::back_button_Click);
            // 
            // search_booking_button
            // 
            this->search_booking_button->Location = System::Drawing::Point(347, 280);
            this->search_booking_button->Name = L"search_booking_button";
            this->search_booking_button->Size = System::Drawing::Size(108, 43);
            this->search_booking_button->TabIndex = 4;
            this->search_booking_button->Text = L"Search Booking";
            this->search_booking_button->UseVisualStyleBackColor = true;
            this->search_booking_button->Click += gcnew System::EventHandler(this, &BookingsScreen::search_booking_button_Click);
            // 
            // create_booking_button
            // 
            this->create_booking_button->Location = System::Drawing::Point(347, 232);
            this->create_booking_button->Name = L"create_booking_button";
            this->create_booking_button->Size = System::Drawing::Size(108, 42);
            this->create_booking_button->TabIndex = 3;
            this->create_booking_button->Text = L"Create Booking";
            this->create_booking_button->UseVisualStyleBackColor = true;
            this->create_booking_button->Click += gcnew System::EventHandler(this, &BookingsScreen::create_booking_button_Click);
            // 
            // BookingsScreen
            // 
            this->BackColor = System::Drawing::SystemColors::Control;
            this->Controls->Add(this->back_button);
            this->Controls->Add(this->search_booking_button);
            this->Controls->Add(this->create_booking_button);
            this->Name = L"BookingsScreen";
            this->Size = System::Drawing::Size(800, 600);
            this->ResumeLayout(false);

        }
    private: System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e) {
        _parent->GoBack();
    }
    private: System::Void create_booking_button_Click(System::Object^ sender, System::EventArgs^ e) {
        _parent->ShowCreateBookingScreen();
    }
    private: System::Void search_booking_button_Click(System::Object^ sender, System::EventArgs^ e) {
        _parent->ShowBookingSearchScreen();
    }
    };
}
