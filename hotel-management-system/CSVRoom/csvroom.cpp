#include "csvroom.h"

#include <fstream>
#include <sstream>
#include <string>

CSVRoom::CSVRoom(const std::string& id) : _id(id) {}

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
