#include "csvbookings.h"
#include "csvbooking.h"

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
