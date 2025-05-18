#pragma once

#include <string>

#include "ibooking.h"

class CSVBooking : public IBooking {
private:
    bool is_fresh = false;
    std::string _id;
    std::string _creation_time;
    std::string _start_date;
    std::string _end_date;
    std::string _guest_id;
    std::string _room_id;
    std::string _employe_id;
    std::string _path_to_bookings = "..\\bookings.csv";

public:
    CSVBooking(const CSVBooking&) = delete;
    CSVBooking& operator=(const CSVBooking&) = delete;

    CSVBooking(const std::string&);

    std::string creation_time() override;
    std::string start_date() override;
    std::string end_date() override;
    std::string guest_id() override;
    std::string room_id() override;
    std::string employe_id()  override;
    void remove() const override;

private:
    void upload_data();
};