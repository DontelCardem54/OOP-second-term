#pragma once
#include "iguest.h"
#include "iroom.h"
#include "ibooking.h"

public interface class IWindow
{
public:
    void ShowLoginScreen();
    void ShowAdminScreen();

    void ShowRoomScreen(IRoom*);
    void ShowRoomSearchScreen();

    void ShowGuestScreen(IGuest*);
    void ShowGuestsScreen();
    void ShowGuestSearchScreen();
    void ShowAddGuestScreen();

    void ShowBookingScreen(IBooking*);
    void ShowBookingsScreen();
    void ShowBookingSearchScreen();
    void ShowCreateBookingScreen();

    void GoBack();
};