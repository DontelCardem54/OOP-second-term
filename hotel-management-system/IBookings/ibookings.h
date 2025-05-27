#pragma once
#include <string>

#include "ibooking.h"
#include "TVector.h"

class IBookings {
public:
    virtual IBooking* add(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&) = 0;
    virtual TVector<IBooking*>* find(const std::string&, const std::string&, const std::string&, const std::string&) = 0;
   /* virtual void remove(const std::string& id) = 0;
    virtual void clear() = 0;*/
    //virtual IGuest get(const std::string& id) = 0;

    virtual ~IBookings() = default;
};