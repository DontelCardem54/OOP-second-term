#include "csvroom.h"
#include "iroom.h"
#include "TVector.h"

#include <fstream>
#include <sstream>
#include <string>

CSVRoom::CSVRoom(const std::string& id) : _id(id) {}

std::string CSVRoom::id() {
    return _id;
}

std::string CSVRoom::number() {
    if (!is_fresh) {
        upload_data();
    }

    return _number;
}

std::string CSVRoom::category_name() {
    if (!is_fresh) {
        upload_data();
    }

    return _category_name;
}

std::string CSVRoom::category_price() {
    if (!is_fresh) {
        upload_data();
    }

    return _category_price;
}

std::string CSVRoom::beds_count() {
    if (!is_fresh) {
        upload_data();
    }

    return _beds_count;
}

std::string CSVRoom::state() {
    if (!is_fresh) {
        upload_data();
    }

    return _state;
}

bool CSVRoom::is_available() {
    if (!is_fresh) {
        upload_data();
    }

    return _state == "available";
}

bool CSVRoom::is_occupied() {
    if (!is_fresh) {
        upload_data();
    }

    return _state == "occupied";
}

void CSVRoom::change_state(RoomState new_state) {
    std::string str_state;

    switch (new_state)
    {
    case RoomState::Available:
        str_state = "available";
        break;
    case RoomState::Occupied:
        str_state = "occupied";
        break;
    case RoomState::UnderMaintenance:
        str_state = "under_maintenance";
        break;
    default:
        throw std::logic_error("Unexpected state");
        break;
    }

    TVector<std::string> lines;
    std::ifstream ipersons_file(_path_to_rooms);

    if (!ipersons_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading");
    }

    std::string line;
    bool found = false;

    while (std::getline(ipersons_file, line)) {
        std::istringstream ss(line);
        std::string current_id;
        std::string room_number;
        std::string category_id;
        std::string beds_count;
        std::string state;

        std::getline(ss, current_id, ',');
        std::getline(ss, room_number, ',');
        std::getline(ss, category_id, ',');
        std::getline(ss, beds_count, ',');
        std::getline(ss, state, ',');

        if (current_id == _id) {
            lines.push_back(current_id + ',' + room_number + ',' + category_id + ',' + beds_count + ',' + str_state);
            found = true;
            continue;
        }

        lines.push_back(line);
    }

    if (!found) {
        throw std::runtime_error("Room not found");
    }

    std::ofstream opersons_file(_path_to_rooms);
    if (!opersons_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для записи");
    }

    for (const auto& l : lines) {
        opersons_file << l << "\n";
    }

    _state = str_state;
}

void CSVRoom::upload_data() {
    std::ifstream room_file(_path_to_rooms);

    if (!room_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading: " + _path_to_rooms);
    }

    std::string line;
    std::getline(room_file, line);
    std::string current_id;
    bool record_found = false;

    while (std::getline(room_file, line)) {
        std::stringstream ss(line);
        std::getline(ss, current_id, ',');

        if (current_id != _id)
            continue;

        std::getline(ss, _number, ',');
        std::getline(ss, _category_id, ',');
        std::getline(ss, _beds_count, ',');
        std::getline(ss, _state, ',');
        record_found = true;
        break;
    }

    if (!record_found) {
        throw std::runtime_error("Гость с " + _id + " не найден в таблице");
    }

    record_found = false;
    std::ifstream category_file(_path_to_categories);

    if (!room_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading: " + _path_to_rooms);
    }

    std::getline(category_file, line);

    while (std::getline(category_file, line)) {
        std::stringstream ss(line);
        std::getline(ss, current_id, ',');

        if (current_id != _category_id)
            continue;

        std::getline(ss, _category_name, ',');
        std::getline(ss, _category_price, ',');
        record_found = true;
        break;
    }

    if (!record_found) {
        throw std::runtime_error("Гость с " + _id + " не найден в таблице");
    }

    is_fresh = true;
}
