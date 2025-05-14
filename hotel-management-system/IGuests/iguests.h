#pragma once
#include <string>

#include "iguest.h"
#include "TVector.h"

class IGuests {
public:
    virtual IGuest* add(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&) = 0;
    virtual void remove(const std::string& id) = 0;
    virtual TVector<IGuest*>* find(const std::string& passport) = 0;
    virtual void clear() = 0;
    //virtual IGuest get(const std::string& id) = 0;

    virtual ~IGuests() = default;
};