#pragma once

#include "hotel.h"

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for BookingsForm
    /// </summary>
    public ref class BookingsForm : public System::Windows::Forms::Form
    {
    private:
        Hotel* _hotel;

    public:
        BookingsForm(Hotel* hotel) : _hotel(hotel)
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
        ~BookingsForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ create_booking_button;
    private: System::Windows::Forms::Button^ search_booking_button;
    protected:


    private: System::Windows::Forms::Button^ back_button;
    protected:

    protected:
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
            this->create_booking_button = (gcnew System::Windows::Forms::Button());
            this->search_booking_button = (gcnew System::Windows::Forms::Button());
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // create_booking_button
            // 
            this->create_booking_button->Location = System::Drawing::Point(41, 35);
            this->create_booking_button->Name = L"create_booking_button";
            this->create_booking_button->Size = System::Drawing::Size(108, 42);
            this->create_booking_button->TabIndex = 0;
            this->create_booking_button->Text = L"Create Booking";
            this->create_booking_button->UseVisualStyleBackColor = true;
            // 
            // search_booking_button
            // 
            this->search_booking_button->Location = System::Drawing::Point(41, 83);
            this->search_booking_button->Name = L"search_booking_button";
            this->search_booking_button->Size = System::Drawing::Size(108, 43);
            this->search_booking_button->TabIndex = 1;
            this->search_booking_button->Text = L"Search Booking";
            this->search_booking_button->UseVisualStyleBackColor = true;
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(40, 132);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(109, 39);
            this->back_button->TabIndex = 2;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            // 
            // BookingsForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(203, 201);
            this->Controls->Add(this->back_button);
            this->Controls->Add(this->search_booking_button);
            this->Controls->Add(this->create_booking_button);
            this->Name = L"BookingsForm";
            this->Text = L"Bookings";
            this->ResumeLayout(false);

        }
#pragma endregion
    };
}