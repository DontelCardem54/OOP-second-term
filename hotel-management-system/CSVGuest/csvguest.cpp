#include "csvguest.h"
#include "TVector.h"
#include <fstream>
#include <sstream>
#include <string>

CSVGuest::CSVGuest(const std::string& passport)  : _passport(passport) {
    upload_data();
}

void CSVGuest::remove() const {
    std::ifstream file(_path_to_table);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string current_id;
        std::getline(ss, current_id, ',');

        if (current_id == _passport) {
            
        }
    }

    file.close();
}

void CSVGuest::save() const{

}

void CSVGuest::upload_data() {
    std::ifstream file(_path_to_table);

    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + _path_to_table);
    }

    std::string line;
    std::getline(file, line);
    std::string current_id;
    bool record_found = false;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, current_id, ',');

        if (current_id != _passport)
            continue;

        std::getline(ss, _name, ',');
        std::getline(ss, _surname, ',');
        std::getline(ss, _patronymic, ',');
        std::getline(ss, _birth_date, ',');
        std::getline(ss, _email, ',');
        bool record_found = true;
        break;
    }

    file.close();

    if (!record_found) {
        throw std::runtime_error("Гость с passport_id " + _passport + " не найден в таблице");
    }
}
