#include <fstream>
#include <sstream>

#include "csvguests.h"
#include "TVector.h"

CSVGuests::CSVGuests() : _current_id(0), _persons_file("..\\persons.csv") {
    update_id();
}

IGuest* CSVGuests::add(
    const std::string& passport,
    const std::string& name,
    const std::string& surname,
    const std::string& patronymic,
    const std::string& birth_date,
    const std::string& email) {
    if (!check_passport(passport)) {
        throw std::logic_error("Not correct passport");
    }

    if (!check_name(name) || !check_name(surname) || !check_name(patronymic)) {
        throw std::logic_error("Not correct name or surname or patronymic");
    }

    if (!check_date(birth_date)) {
        throw std::logic_error("Not correct birth date");
    }

    _current_id++;
    std::ostringstream oss;
    oss << _current_id << ","
        << passport << ","
        << name << ","
        << surname << ","
        << patronymic << ","
        << birth_date << ","
        << email << "\n";

    _persons_file.add_row(oss.str());

    return new CSVGuest(std::to_string(_current_id));
}

void CSVGuests::remove(const std::string& id) {
    _persons_file.remove(id);
}

TVector<IGuest*>* CSVGuests::find(const std::string& passport) {
    TVector<IGuest*>* guests = new TVector<IGuest*>();
    std::ifstream ipersons_file(_path_to_persons);

    if (!ipersons_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для чтения");
    }

    std::string line;

    while (std::getline(ipersons_file, line)) {
        std::istringstream ss(line);
        std::string current_passport;
        std::string id;

        std::getline(ss, id, ',');
        std::getline(ss, current_passport, ',');

        if (current_passport == passport) {
            guests->push_back(new CSVGuest(id));
        }
    }

    return guests;
}

void CSVGuests::clear() {
    _persons_file.clear();
    _current_id = 0;
}

IGuest* CSVGuests::get_by_passport(const std::string& passport) {
    std::string id;

    try {
        id = _persons_file.get_value_by_column(1, passport, 0);
        return new CSVGuest(id);
    }
    catch (const std::exception& ex) {
        return nullptr;
    }
}

IGuest* CSVGuests::get_by_id(const std::string& id) {
    if (_persons_file.has_row(id)) {
        return new CSVGuest(id);
    }

    return nullptr;
}

void CSVGuests::update_id() {
    std::ifstream file(_path_to_persons);
    std::string line, last_line;

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading");
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

bool CSVGuests::check_passport(const std::string& passport) {
    if (passport.length() != 10) {
        return false;
    }

    for (char c : passport) {
        if (!std::isdigit(c)) {
            return false;
        }
    }

    std::ifstream file(_path_to_persons);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open CSV file");
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::istringstream ss(line);
        std::string current_id, current_passport;

        std::getline(ss, current_id, ',');
        std::getline(ss, current_passport, ',');

        if (current_passport == passport) {
            return false;
        }
    }

    return true;
}

bool CSVGuests::check_name(const std::string& name){
    if (name.empty() || name.length() > 15) {
        return false;
    }

    for (char c : name) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
            return false;
        }
    }

    return true;
}

bool CSVGuests::check_date(const std::string& date) {
    if (date.length() != 10) return false;

    if (date[2] != '.' || date[5] != '.') return false;

    std::string day_str = date.substr(0, 2);
    std::string month_str = date.substr(3, 2);
    std::string year_str = date.substr(6, 4);

    for (char c : year_str + month_str + day_str) {
        if (!isdigit(c)) return false;
    }

    int year = stoi(year_str);
    int month = stoi(month_str);
    int day = stoi(day_str);

    if (year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    return true;
}
