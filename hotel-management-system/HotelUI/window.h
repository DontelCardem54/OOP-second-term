#pragma once

#include "login_screen.h"
#include "admin_screen.h"

#include "room_screen.h"
#include "room_search_screen.h"

#include "guest_screen.h"
#include "guests_screen.h"
#include "guest_search_screen.h"
#include "add_guest_screen.h"

#include "booking_screen.h"
#include "bookings_screen.h"
#include "booking_search_screen.h"
#include "create_booking_screen.h"

#include "iwindow.h"

#include "csvguests.h"


namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Window
	/// </summary>
    public ref class Window : public Form, public IWindow
	{
	public:
		Window(void)
		{
			InitializeComponent();
            InitializeScreens();
            ShowAdminScreen();
		}

	protected:
		~Window()
		{
			if (components)
			{
				delete components;
			}
		}
    private:
        System::Windows::Forms::Panel^ container_panel;

        LoginScreen^ login_screen;
        AdminScreen^ admin_screen;

        RoomScreen^ room_screen;
        RoomSearchScreen^ room_search_screen;

        GuestScreen^ guest_screen;
        GuestsScreen^ guests_screen;
        GuestSearchScreen^ guest_search_screen;
        AddGuestScreen^ add_guest_screen;

        BookingScreen^ booking_screen;
        BookingsScreen^ bookings_screen;
        BookingSearchScreen^ booking_search_screen;
        CreateBookingScreen^ create_booking_screen;

        CSVGuests* csvguests;

        System::Collections::Generic::Stack<UserControl^>^ panel_history;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
            csvguests = new CSVGuests();
            this->container_panel = (gcnew System::Windows::Forms::Panel());
            this->SuspendLayout();
            // 
            // container_panel
            // 
            this->container_panel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->container_panel->Location = System::Drawing::Point(0, 0);
            this->container_panel->Name = L"container_panel";
            this->container_panel->Size = System::Drawing::Size(784, 561);
            this->container_panel->TabIndex = 0;
            // 
            // Window
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(784, 561);
            this->Controls->Add(this->container_panel);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"Window";
            this->Text = L"Window";
            this->ResumeLayout(false);
        }
#pragma endregion
        void InitializeScreens();

    public:
        void ShowLoginScreen() override{}
        void ShowAdminScreen() override;

        void ShowRoomScreen() override{}
        void ShowRoomSearchScreen() override;

        void ShowGuestScreen() override{}
        void ShowGuestsScreen() override;
        void ShowGuestSearchScreen() override{}
        void ShowAddGuestScreen() override;

        void ShowBookingScreen() override{}
        void ShowBookingsScreen() override{}
        void ShowBookingSearchScreen() override{}
        void ShowCreateBookingScreen() override{}

        void GoBack() override;
	};
}
