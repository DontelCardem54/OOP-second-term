#include "csvbooking.h"
#include "TVector.h"
#include "csvroom.h"

#include <fstream>
#include <sstream>
#include <string>

CSVBooking::CSVBooking(const std::string& id) : _id(id) {}

CSVBooking::~CSVBooking() {
    delete _room;
}

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

void CSVBooking::remove() {
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
        throw std::runtime_error("Booking not found");
    }

    std::ofstream obookings_file(_path_to_bookings);
    if (!obookings_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для записи");
    }

    for (const auto& l : lines) {
        obookings_file << l << "\n";
    }

    if (_room == nullptr) {
        _room = new CSVRoom(_room_id);
    }

    _room->change_state(RoomState::Available);
}

void CSVBooking::change_start_date(const std::string& new_start_date) {
    TVector<std::string> lines;
    std::ifstream ipersons_file(_path_to_bookings);

    if (!ipersons_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading");
    }

    std::string line;
    bool found = false;

    while (std::getline(ipersons_file, line)) {
        std::istringstream ss(line);
        std::string current_id;
        std::string start_date;
        std::string end_date;
        std::string guest_id;
        std::string room_id;
        std::string employe_id;

        std::getline(ss, current_id, ',');
        std::getline(ss, start_date, ',');
        std::getline(ss, end_date, ',');
        std::getline(ss, guest_id, ',');
        std::getline(ss, room_id, ',');
        std::getline(ss, employe_id, ',');

        if (current_id == _id) {
            lines.push_back(current_id + ',' + new_start_date + ',' + end_date + ',' + guest_id + ',' + room_id + ',' + employe_id);
            found = true;
            continue;
        }

        lines.push_back(line);
    }

    if (!found) {
        throw std::runtime_error("Booking not found");
    }

    std::ofstream opersons_file(_path_to_bookings);
    if (!opersons_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для записи");
    }

    for (const auto& l : lines) {
        opersons_file << l << "\n";
    }

    _start_date = new_start_date;
}

void CSVBooking::change_end_date(const std::string& new_end_date) {
    TVector<std::string> lines;
    std::ifstream ipersons_file(_path_to_bookings);

    if (!ipersons_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading");
    }

    std::string line;
    bool found = false;

    while (std::getline(ipersons_file, line)) {
        std::istringstream ss(line);
        std::string current_id;
        std::string start_date;
        std::string end_date;
        std::string guest_id;
        std::string room_id;
        std::string employe_id;

        std::getline(ss, current_id, ',');
        std::getline(ss, start_date, ',');
        std::getline(ss, end_date, ',');
        std::getline(ss, guest_id, ',');
        std::getline(ss, room_id, ',');
        std::getline(ss, employe_id, ',');

        if (current_id == _id) {
            lines.push_back(current_id + ',' + start_date + ',' + new_end_date + ',' + guest_id + ',' + room_id + ',' + employe_id);
            found = true;
            continue;
        }

        lines.push_back(line);
    }

    if (!found) {
        throw std::runtime_error("Booking not found");
    }

    std::ofstream opersons_file(_path_to_bookings);
    if (!opersons_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для записи");
    }

    for (const auto& l : lines) {
        opersons_file << l << "\n";
    }

    _end_date = new_end_date;
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