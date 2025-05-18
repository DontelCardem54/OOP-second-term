#pragma once

#include "iroom.h"
#include "iwindow.h"

namespace CppCLRWinFormsProject
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class RoomScreen : UserControl
    {
    private:
        IWindow^ _parent;
        IRoom* _room;
    public:
        RoomScreen(IWindow^ parent) : _parent(parent) {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~RoomScreen()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ back_button;
    protected:
    private: System::Windows::Forms::Label^ staff_label;
    private: System::Windows::Forms::Label^ guest_label;
    private: System::Windows::Forms::Button^ book_room_button;
    private: System::Windows::Forms::Button^ remove_from_repair_button;
    private: System::Windows::Forms::Button^ close_for_repair_button;
    private: System::Windows::Forms::Label^ beds_count_label;
    private: System::Windows::Forms::Label^ room_number_label;
    private: System::Windows::Forms::Label^ category_label;
    private: System::Windows::Forms::Label^ state_label;
           /// <summary> 
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->back_button = (gcnew System::Windows::Forms::Button());
            this->staff_label = (gcnew System::Windows::Forms::Label());
            this->guest_label = (gcnew System::Windows::Forms::Label());
            this->book_room_button = (gcnew System::Windows::Forms::Button());
            this->remove_from_repair_button = (gcnew System::Windows::Forms::Button());
            this->close_for_repair_button = (gcnew System::Windows::Forms::Button());
            this->beds_count_label = (gcnew System::Windows::Forms::Label());
            this->room_number_label = (gcnew System::Windows::Forms::Label());
            this->category_label = (gcnew System::Windows::Forms::Label());
            this->state_label = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // back_button
            // 
            this->back_button->Location = System::Drawing::Point(339, 320);
            this->back_button->Name = L"back_button";
            this->back_button->Size = System::Drawing::Size(109, 43);
            this->back_button->TabIndex = 19;
            this->back_button->Text = L"Back";
            this->back_button->UseVisualStyleBackColor = true;
            this->back_button->Click += gcnew System::EventHandler(this, &RoomScreen::back_button_Click);
            // 
            // staff_label
            // 
            this->staff_label->AutoSize = true;
            this->staff_label->Location = System::Drawing::Point(217, 301);
            this->staff_label->Name = L"staff_label";
            this->staff_label->Size = System::Drawing::Size(108, 13);
            this->staff_label->TabIndex = 18;
            this->staff_label->Text = L"Staff: name, role, mail";
            // 
            // guest_label
            // 
            this->guest_label->AutoSize = true;
            this->guest_label->Location = System::Drawing::Point(217, 273);
            this->guest_label->Name = L"guest_label";
            this->guest_label->Size = System::Drawing::Size(91, 13);
            this->guest_label->TabIndex = 17;
            this->guest_label->Text = L"Guest: name, mail";
            // 
            // book_room_button
            // 
            this->book_room_button->Location = System::Drawing::Point(464, 367);
            this->book_room_button->Name = L"book_room_button";
            this->book_room_button->Size = System::Drawing::Size(100, 44);
            this->book_room_button->TabIndex = 16;
            this->book_room_button->Text = L"Забронировать";
            this->book_room_button->UseVisualStyleBackColor = true;
            // 
            // remove_from_repair_button
            // 
            this->remove_from_repair_button->Location = System::Drawing::Point(339, 369);
            this->remove_from_repair_button->Name = L"remove_from_repair_button";
            this->remove_from_repair_button->Size = System::Drawing::Size(109, 42);
            this->remove_from_repair_button->TabIndex = 15;
            this->remove_from_repair_button->Text = L"Снять с ремонта";
            this->remove_from_repair_button->UseVisualStyleBackColor = true;
            // 
            // close_for_repair_button
            // 
            this->close_for_repair_button->Location = System::Drawing::Point(220, 369);
            this->close_for_repair_button->Name = L"close_for_repair_button";
            this->close_for_repair_button->Size = System::Drawing::Size(100, 42);
            this->close_for_repair_button->TabIndex = 14;
            this->close_for_repair_button->Text = L"Закрыть на ремонт";
            this->close_for_repair_button->UseVisualStyleBackColor = true;
            // 
            // beds_count_label
            // 
            this->beds_count_label->AutoSize = true;
            this->beds_count_label->Location = System::Drawing::Point(217, 240);
            this->beds_count_label->Name = L"beds_count_label";
            this->beds_count_label->Size = System::Drawing::Size(67, 13);
            this->beds_count_label->TabIndex = 13;
            this->beds_count_label->Text = L"Beds count: ";
            // 
            // room_number_label
            // 
            this->room_number_label->AutoSize = true;
            this->room_number_label->Location = System::Drawing::Point(217, 215);
            this->room_number_label->Name = L"room_number_label";
            this->room_number_label->Size = System::Drawing::Size(50, 13);
            this->room_number_label->TabIndex = 12;
            this->room_number_label->Text = L"Number: ";
            // 
            // category_label
            // 
            this->category_label->AutoSize = true;
            this->category_label->Location = System::Drawing::Point(217, 190);
            this->category_label->Name = L"category_label";
            this->category_label->Size = System::Drawing::Size(55, 13);
            this->category_label->TabIndex = 11;
            this->category_label->Text = L"Category: ";
            // 
            // state_label
            // 
            this->state_label->AutoSize = true;
            this->state_label->Location = System::Drawing::Point(217, 162);
            this->state_label->Name = L"state_label";
            this->state_label->Size = System::Drawing::Size(38, 13);
            this->state_label->TabIndex = 10;
            this->state_label->Text = L"State: ";
            // 
            // RoomScreen
            // 
            this->BackColor = System::Drawing::SystemColors::Control;
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
            this->Name = L"RoomScreen";
            this->Size = System::Drawing::Size(800, 600);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
    private: System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e) {
        _parent->GoBack();
    }
    public:
        System::Void set_room(IRoom* room);
    private:
        System::Void fill_screen();
};
}
