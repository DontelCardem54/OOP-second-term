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
    /// Summary for RoomForm
    /// </summary>
    public ref class RoomForm : public System::Windows::Forms::Form
    {
    private:
        Hotel* _hotel;

    public:
        RoomForm(Hotel* hotel) : _hotel(hotel)
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
        ~RoomForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ state_label;
    private: System::Windows::Forms::Label^ category_label;
    private: System::Windows::Forms::Label^ room_number_label;
    private: System::Windows::Forms::Label^ beds_count_label;
    protected:

    protected:



    private: System::Windows::Forms::Button^ close_for_repair_button;
    private: System::Windows::Forms::Button^ remove_from_repair_button;
    private: System::Windows::Forms::Button^ book_room_button;
    private: System::Windows::Forms::Label^ guest_label;

    private: System::Windows::Forms::Label^ staff_label;

    private: System::Windows::Forms::Button^ back_button;


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
            this->state_label = (gcnew System::Windows::Forms::Label());
            this->category_label = (gcnew System::Windows::Forms::Label());
            this->room_number_label = (gcnew System::Windows::Forms::Label());
            this->beds_count_label = (gcnew System::Windows::Forms::Label());
            this->close_for_repair_button = (gcnew System::Windows::Forms::Button());
            this->remove_from_repair_button = (gcnew System::Windows::Forms::Button());
            this->book_room_button = (gcnew System::Windows::Forms::Button());
            this->guest_label = (gcnew System::Windows::Forms::Label());
            this->staff_label = (gcnew System::Windows::Forms::Label());
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // state_label
            // 
            this->state_label->AutoSize = true;
            this->state_label->Location = System::Drawing::Point(24, 28);
            this->state_label->Name = L"state_label";
            this->state_label->Size = System::Drawing::Size(47, 13);
            this->state_label->TabIndex = 0;
            this->state_label->Text = L"Статус: ";
            // 
            // category_label
            // 
            this->category_label->AutoSize = true;
            this->category_label->Location = System::Drawing::Point(103, 28);
            this->category_label->Name = L"category_label";
            this->category_label->Size = System::Drawing::Size(66, 13);
            this->category_label->TabIndex = 1;
            this->category_label->Text = L"Категория: ";
            // 
            // room_number_label
            // 
            this->room_number_label->AutoSize = true;
            this->room_number_label->Location = System::Drawing::Point(195, 28);
            this->room_number_label->Name = L"room_number_label";
            this->room_number_label->Size = System::Drawing::Size(47, 13);
            this->room_number_label->TabIndex = 2;
            this->room_number_label->Text = L"Номер: ";
            // 
            // beds_count_label
            // 
            this->beds_count_label->AutoSize = true;
            this->beds_count_label->Location = System::Drawing::Point(259, 28);
            this->beds_count_label->Name = L"beds_count_label";
            this->beds_count_label->Size = System::Drawing::Size(122, 13);
            this->beds_count_label->TabIndex = 3;
            this->beds_count_label->Text = L"Количество кроватей: ";
            // 
            // close_for_repair_button
            // 
            this->close_for_repair_button->Location = System::Drawing::Point(27, 207);
            this->close_for_repair_button->Name = L"close_for_repair_button";
            this->close_for_repair_button->Size = System::Drawing::Size(100, 42);
            this->close_for_repair_button->TabIndex = 4;
            this->close_for_repair_button->Text = L"Закрыть на ремонт";
            this->close_for_repair_button->UseVisualStyleBackColor = true;
            // 
            // remove_from_repair_button
            // 
            this->remove_from_repair_button->Location = System::Drawing::Point(146, 207);
            this->remove_from_repair_button->Name = L"remove_from_repair_button";
            this->remove_from_repair_button->Size = System::Drawing::Size(109, 42);
            this->remove_from_repair_button->TabIndex = 5;
            this->remove_from_repair_button->Text = L"Снять с ремонта";
            this->remove_from_repair_button->UseVisualStyleBackColor = true;
            // 
            // book_room_button
            // 
            this->book_room_button->Location = System::Drawing::Point(271, 205);
            this->book_room_button->Name = L"book_room_button";
            this->book_room_button->Size = System::Drawing::Size(119, 44);
            this->book_room_button->TabIndex = 6;
            this->book_room_button->Text = L"Забронировать";
            this->book_room_button->UseVisualStyleBackColor = true;
            // 
            // guest_label
            // 
            this->guest_label->AutoSize = true;
            this->guest_label->Location = System::Drawing::Point(24, 102);
            this->guest_label->Name = L"guest_label";
            this->guest_label->Size = System::Drawing::Size(91, 13);
            this->guest_label->TabIndex = 7;
            this->guest_label->Text = L"Guest: name, mail";
            // 
            // staff_label
            // 
            this->staff_label->AutoSize = true;
            this->staff_label->Location = System::Drawing::Point(24, 146);
            this->staff_label->Name = L"staff_label";
            this->staff_label->Size = System::Drawing::Size(108, 13);
            this->staff_label->TabIndex = 8;
            this->staff_label->Text = L"Staff: name, role, mail";
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(274, 155);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(116, 32);
            this->back_button->TabIndex = 9;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            // 
            // RoomForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(427, 282);
            this->Controls->Add(this->back_button);
            this->Controls->Add(this->staff_label);
            this->Controls->Add(this->guest_label);
            this->Controls->Add(this->book_room_button);
            this->Controls->Add(this->remove_from_repair_button);
            this->Controls->Add(this->close_for_repair_button);
            this->Controls->Add(this->beds_count_label);
            this->Controls->Add(this->room_number_label);
            this->Controls->Add(this->category_label);
            this->Controls->Add(this->state_label);
            this->Name = L"RoomForm";
            this->Text = L"Комната";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion


};
}