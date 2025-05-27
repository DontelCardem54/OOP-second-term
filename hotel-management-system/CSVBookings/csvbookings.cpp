#include "csvbookings.h"
#include "csvbooking.h"
#include "csvguest.h"
#include "csvroom.h"

#include <fstream>
#include <sstream>

CSVBookings::CSVBookings() : _current_id(0) {
    update_id();
}

IBooking* CSVBookings::add(
    const std::string& start_date,
    const std::string& end_date,
    const std::string& guest_passport,
    const std::string& room_number,
    const std::string& employe_passport) {
    std::ofstream bookings_file(_path_to_bookings, std::ios::app);

    if (!bookings_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для записи");
    }

    _current_id++;
    bookings_file << _current_id << ","
        << start_date << ","
        << end_date << ","
        << guest_passport << ","
        << room_number << ","
        << employe_passport << "\n";

    return new CSVBooking(std::to_string(_current_id));
}

TVector<IBooking*>* CSVBookings::find(
    const std::string& start_date,
    const std::string& end_date,
    const std::string& guest_passport,
    const std::string& room_number) {

    TVector<IBooking*>* bookings = new TVector<IBooking*>();
    std::ifstream irooms_file(_path_to_bookings);

    if (!irooms_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading");
    }

    std::string line;
    std::getline(irooms_file, line);

    while (std::getline(irooms_file, line)) {
        std::istringstream ss(line);
        std::string current_id, current_start_date, current_end_date, current_guest_id, current_room_id;

        std::getline(ss, current_id, ',');
        std::getline(ss, current_start_date, ',');
        std::getline(ss, current_end_date, ',');
        std::getline(ss, current_guest_id, ',');
        std::getline(ss, current_room_id, ',');

        CSVGuest guest(current_guest_id);
        CSVRoom room(current_room_id);

        bool start_date_match = (start_date.empty() || current_start_date == start_date);
        bool end_date_match = (end_date.empty() || current_end_date == end_date);
        bool guest_passport_match = (guest_passport.empty() || guest.passport() == guest_passport);
        bool room_number_match = (room_number.empty() || room.number() == room_number);

        if (start_date_match && end_date_match && guest_passport_match && room_number_match) {
            bookings->push_back(new CSVBooking(current_id));
        }
    }

    return bookings;
}

void CSVBookings::update_id() {
    std::ifstream file(_path_to_bookings);
    std::string line, last_line;

    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл");
    }

    while (std::getline(file, line)) {
        if (!line.empty()) {
            last_line = line;
        }
    }

    std::istringstream ss(last_line);
    std::string id;
    std::getline(ss, id, ',');

    try {
        _current_id = std::stoi(id);
    }
    catch (std::invalid_argument& e) {
        _current_id = 0;
    }
}
