#include <fstream>
#include <sstream>

#include "csvguests.h"
#include "TVector.h"
#include "csvguest.h"

CSVGuests::CSVGuests() : _current_id(0) {
    update_id();
}

IGuest* CSVGuests::add(
    const std::string& passport,
    const std::string& name,
    const std::string& surname,
    const std::string& patronymic,
    const std::string& birth_date,
    const std::string& email) {
    std::ofstream persons_file(_path_to_persons, std::ios::app);

    if (!persons_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для записи");
    }

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
    persons_file << _current_id << ","
        << passport << ","
        << name << ","
        << surname << ","
        << patronymic << ","
        << birth_date << ","
        << email << "\n";

    return new CSVGuest(std::to_string(_current_id));
}

void CSVGuests::remove(const std::string& id) {
    TVector<std::string> lines;
    std::ifstream ipersons_file(_path_to_persons);

    if (!ipersons_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для чтения");
    }

    std::string line;
    bool found = false;

    while (std::getline(ipersons_file, line)) {
        std::istringstream ss(line);
        std::string current_id;

        std::getline(ss, current_id, ',');
        if (current_id == id) {
            found = true;
            continue;
        }

        lines.push_back(line);
    }

    if (!found) {
        throw std::runtime_error("Гость с таким ID не найден");
    }

    std::ofstream opersons_file(_path_to_persons);
    if (!opersons_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для записи");
    }

    for (const auto& l : lines) {
        opersons_file << l << "\n";
    }
}

TVector<IGuest*> CSVGuests::find(const std::string& passport) {
    TVector<IGuest*> guests;
    std::ifstream ipersons_file(_path_to_persons);

    if (!ipersons_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для чтения");
    }

    std::string line;
    bool found = false;

    while (std::getline(ipersons_file, line)) {
        std::istringstream ss(line);
        std::string current_passport;
        std::string id;

        std::getline(ss, id, ',');
        std::getline(ss, current_passport, ',');

        if (current_passport == passport) {
            guests.push_back(new CSVGuest(id));
            found = true;
        }
    }

    if (!found) {
        throw std::runtime_error("Гость с таким passport не найден");
    }

    return guests;
}

void CSVGuests::clear() {
    std::ifstream ipersons_file(_path_to_persons);

    if (!ipersons_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для чтения");
    }

    std::string line;
    std::getline(ipersons_file, line);
    std::ofstream opersons_file(_path_to_persons);

    if (!opersons_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для записи");
    }

    opersons_file << line << "\n";
    _current_id = 0;
}

void CSVGuests::update_id() {
    std::ifstream file(_path_to_persons);
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
    if (id == "id") {
        _current_id = 0;
    }
    else {
        _current_id = std::stoi(id);
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

    if (date[4] != '-' || date[7] != '-') return false;

    std::string year_str = date.substr(0, 4);
    std::string month_str = date.substr(5, 2);
    std::string day_str = date.substr(8, 2);

    for (char c : year_str + month_str + day_str) {
        if (!isdigit(c)) return false;
    }

    int year = stoi(year_str);
    int month = stoi(month_str);
    int day = stoi(day_str);

    if (year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
}
