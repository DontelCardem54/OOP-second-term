#pragma once
#include "iguest.h"

public interface class IWindow
{
public:
    void ShowLoginScreen();
    void ShowAdminScreen();

    void ShowRoomScreen();
    void ShowRoomSearchScreen();

    void ShowGuestScreen(IGuest*);
    void ShowGuestsScreen();
    void ShowGuestSearchScreen();
    void ShowAddGuestScreen();

    void ShowBookingScreen();
    void ShowBookingsScreen();
    void ShowBookingSearchScreen();
    void ShowCreateBookingScreen();

    void GoBack();
};