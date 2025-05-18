#pragma once

#include <string>
#include "TVector.h"
#include "ibookings.h"

class CSVBookings : public IBookings {
private:
    int _current_id;
    std::string _path_to_bookings = "..\\bookings.csv";

public:
    CSVBookings();
    IBooking* add(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&) override;
    /*void remove(const std::string& id) override {};
    TVector<IBooking*>* find(const std::string&, const std::string&, const std::string&, const std::string&) override {};
    void clear() override {};*/
private:
    void update_id();
};