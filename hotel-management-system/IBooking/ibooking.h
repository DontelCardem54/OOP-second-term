#pragma once
#include <string>

class IBooking {
public:
    virtual std::string creation_time() = 0;
    virtual std::string start_date() = 0;
    virtual std::string end_date() = 0;
    virtual std::string guest_id() = 0;
    virtual std::string room_id() = 0;
    virtual std::string employe_id() = 0;
    virtual void remove() const = 0;

    //virtual void change_passport(const std::string& new_passport) = 0;

    virtual ~IBooking() = default;
};