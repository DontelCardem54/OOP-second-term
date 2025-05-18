#pragma once
#include <string>

#include "iroom.h"
#include "TVector.h"
//
//class IGuests {
//public:
//    virtual IGuest* add(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&) = 0;
//    virtual void remove(const std::string& id) = 0;
//    virtual TVector<IGuest*>* find(const std::string& passport) = 0;
//    virtual void clear() = 0;
//    //virtual IGuest get(const std::string& id) = 0;
//
//    virtual ~IGuests() = default;
//};

class IRooms {
public:
    virtual TVector<IRoom*>* find(const std::string& number,
        const std::string& category,
        const std::string& beds_count,
        const std::string& state) = 0;
    virtual IRoom* get_by_room_number(const std::string& number) = 0;

    virtual ~IRooms() = default;
};