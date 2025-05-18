#include "csvbooking.h"
#include "TVector.h"

#include <fstream>
#include <sstream>
#include <string>

CSVBooking::CSVBooking(const std::string& id) : _id(id) {}

std::string CSVBooking::creation_time() {
    if (!is_fresh) {
        upload_data();
    }

    return _creation_time;
}

std::string CSVBooking::start_date() {
    if (!is_fresh) {
        upload_data();
    }

    return _start_date;
}

std::string CSVBooking::end_date() {
    if (!is_fresh) {
        upload_data();
    }

    return _end_date;
}

std::string CSVBooking::guest_id() {
    if (!is_fresh) {
        upload_data();
    }

    return _guest_id;
}

std::string CSVBooking::room_id() {
    if (!is_fresh) {
        upload_data();
    }

    return _room_id;
}

std::string CSVBooking::employe_id() {
    if (!is_fresh) {
        upload_data();
    }

    return _employe_id;
}

void CSVBooking::remove() const {
    TVector<std::string> lines;
    std::ifstream ibookings_file(_path_to_bookings);

    if (!ibookings_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading");
    }

    std::string line;
    bool found = false;

    while (std::getline(ibookings_file, line)) {
        std::istringstream ss(line);
        std::string current_id;

        std::getline(ss, current_id, ',');
        if (current_id == _id) {
            found = true;
            continue;
        }

        lines.push_back(line);
    }

    if (!found) {
        throw std::runtime_error("Гость с таким ID не найден");
    }

    std::ofstream obookings_file(_path_to_bookings);
    if (!obookings_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для записи");
    }

    for (const auto& l : lines) {
        obookings_file << l << "\n";
    }
}

void CSVBooking::upload_data() {
    std::ifstream ibookings_file(_path_to_bookings);

    if (!ibookings_file.is_open())
        throw std::runtime_error("Couldn't open the file for reading: " + _path_to_bookings);

    std::string line;
    std::getline(ibookings_file, line);
    std::string current_id;
    bool record_found = false;

    while (std::getline(ibookings_file, line)) {
        std::stringstream ss(line);
        std::getline(ss, current_id, ',');

        if (current_id != _id)
            continue;

        std::getline(ss, _start_date, ',');
        std::getline(ss, _end_date, ',');
        std::getline(ss, _guest_id, ',');
        std::getline(ss, _room_id, ',');
        std::getline(ss, _employe_id, ',');
        record_found = true;
        is_fresh = true;
        break;
    }

    if (!record_found) {
        throw std::runtime_error("Booking not found");
    }
}