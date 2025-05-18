#include "csvrooms.h"
#include "csvroom.h"
#include "TVector.h"
#include <fstream>
#include <sstream>

CSVRooms::CSVRooms() : _current_id(0) {}

TVector<IRoom*>* CSVRooms::find(
    const std::string& number,
    const std::string& category_id,
    const std::string& beds_count,
    const std::string& state) {
    TVector<IRoom*>* rooms = new TVector<IRoom*>();
    std::ifstream irooms_file(_path_to_rooms);

    if (!irooms_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading");
    }

    std::string line;
    std::getline(irooms_file, line);

    while (std::getline(irooms_file, line)) {
        std::istringstream ss(line);
        std::string current_id, current_number, current_category_id, current_beds_count, current_state;

        std::getline(ss, current_id, ',');
        std::getline(ss, current_number, ',');
        std::getline(ss, current_category_id, ',');
        std::getline(ss, current_beds_count, ',');
        std::getline(ss, current_state, ',');

        bool number_match = (number.empty() || current_number == state);
        bool category_match = (category_id.empty() || current_category_id == category_id);
        bool beds_match = (beds_count.empty() || current_beds_count == beds_count);
        bool state_match = (state.empty() || current_state == state);

        if (number_match && category_match && beds_match && state_match) {
            rooms->push_back(new CSVRoom(current_id));
        }
    }

    return rooms;
}

IRoom* CSVRooms::get_by_room_number(const std::string& number)
{
    std::ifstream irooms_file(_path_to_rooms);

    if (!irooms_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для чтения");
    }

    std::string line;

    while (std::getline(irooms_file, line)) {
        std::istringstream ss(line);
        std::string current_number;
        std::string id;

        std::getline(ss, id, ',');
        std::getline(ss, current_number, ',');

        if (current_number == number) {
            return new CSVRoom(id);
        }
    }

    return nullptr;
}
