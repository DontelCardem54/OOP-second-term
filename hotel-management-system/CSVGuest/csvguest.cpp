#include "csvguest.h"
#include "TVector.h"

#include <fstream>
#include <sstream>
#include <string>

CSVGuest::CSVGuest(const std::string& id) : _id(id) {
    _passport = "";
    _name = "";
    _surname = "";
    _patronymic = "";
    _birth_date = "";
    _email = "";
}

CSVGuest::CSVGuest(const std::string& id, 
    const std::string& passport,
    const std::string& name, 
    const std::string& surname, 
    const std::string& partonymic, 
    const std::string& birth_date, 
    const std::string& email) : 
    _id(id), 
    _passport(passport), 
    _name(name), 
    _surname(surname), 
    _patronymic(partonymic),
    _birth_date(birth_date), 
    _email(email) {}


std::string CSVGuest::name() {
    if (!is_fresh) {
        upload_data();
    }

    return _name;
}

std::string CSVGuest::surname() {
    if (!is_fresh) {
        upload_data();
    }

    return _surname;
}

std::string CSVGuest::patronymic() {
    if (!is_fresh) {
        upload_data();
    }

    return _patronymic;
}

std::string CSVGuest::passport() {
    if (!is_fresh) {
        upload_data();
    }

    return _passport;
}

std::string CSVGuest::birth_date() {
    if (!is_fresh) {
        upload_data();
    }

    return _birth_date;
}

std::string CSVGuest::email() {
    if (!is_fresh) {
        upload_data();
    }

    return _email;
}

void CSVGuest::change_passport(const std::string& new_passport) {
    if (!check_passport(new_passport)) {
        throw std::logic_error("Not correct passport");
    }

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
        std::string passport;
        std::string name;
        std::string surname;
        std::string patronymic;
        std::string birth_date;
        std::string email;

        std::getline(ss, current_id, ',');
        std::getline(ss, passport, ',');
        std::getline(ss, name, ',');
        std::getline(ss, surname, ',');
        std::getline(ss, patronymic, ',');
        std::getline(ss, birth_date, ',');
        std::getline(ss, email, ',');

        if (current_id == _id) {
            lines.push_back(current_id + ',' + new_passport + ',' + name + ',' + surname + ',' + patronymic + ',' + birth_date + ',' + email);
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

    _passport = new_passport;
}

void CSVGuest::change_name(const std::string& new_name) {
    if (!check_name(new_name)) {
        throw std::logic_error("Not correct name");
    }

    TVector<std::string> lines;
    std::ifstream ipersons_file(_path_to_persons);

    if (!ipersons_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading");
    }

    std::string line;
    bool found = false;

    while (std::getline(ipersons_file, line)) {
        std::istringstream ss(line);
        std::string current_id;
        std::string passport;
        std::string name;
        std::string surname;
        std::string patronymic;
        std::string birth_date ;
        std::string email;

        std::getline(ss, current_id, ',');
        std::getline(ss, passport, ',');
        std::getline(ss, name, ',');
        std::getline(ss, surname, ',');
        std::getline(ss, patronymic, ',');
        std::getline(ss, birth_date, ',');
        std::getline(ss, email, ',');

        if (current_id == _id) {
            lines.push_back(current_id + ',' + passport + ',' + new_name + ',' + surname + ',' + patronymic + ',' + birth_date + ',' + email);
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

    _name = new_name;
}

void CSVGuest::change_surname(const std::string& new_surname) {
    if (!check_name(new_surname)) {
        throw std::logic_error("Not correct surname");
    }

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
        std::string passport;
        std::string name;
        std::string surname;
        std::string patronymic;
        std::string birth_date;
        std::string email;

        std::getline(ss, current_id, ',');
        std::getline(ss, passport, ',');
        std::getline(ss, name, ',');
        std::getline(ss, surname, ',');
        std::getline(ss, patronymic, ',');
        std::getline(ss, birth_date, ',');
        std::getline(ss, email, ',');

        if (current_id == _id) {
            lines.push_back(current_id + ',' + passport + ',' + name + ',' + new_surname + ',' + patronymic + ',' + birth_date + ',' + email);
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

    _surname = new_surname;
}

void CSVGuest::change_patronymic(const std::string& new_patronymic) {
    if (!check_name(new_patronymic)) {
        throw std::logic_error("Not correct patronymic");
    }

    TVector<std::string> lines;
    std::ifstream ipersons_file(_path_to_persons);

    if (!ipersons_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading");
    }

    std::string line;
    bool found = false;

    while (std::getline(ipersons_file, line)) {
        std::istringstream ss(line);
        std::string current_id;
        std::string passport;
        std::string name;
        std::string surname;
        std::string patronymic;
        std::string birth_date;
        std::string email;

        std::getline(ss, current_id, ',');
        std::getline(ss, passport, ',');
        std::getline(ss, name, ',');
        std::getline(ss, surname, ',');
        std::getline(ss, patronymic, ',');
        std::getline(ss, birth_date, ',');
        std::getline(ss, email, ',');

        if (current_id == _id) {
            lines.push_back(current_id + ',' + passport + ',' + name + ',' + surname + ',' + new_patronymic + ',' + birth_date + ',' + email);
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

    _patronymic = new_patronymic;
}

void CSVGuest::change_birth_date(const std::string& new_birth_date) {
    if (!check_date(new_birth_date)) {
        throw std::logic_error("Not correct birth date");
    }

    TVector<std::string> lines;
    std::ifstream ipersons_file(_path_to_persons);

    if (!ipersons_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading");
    }

    std::string line;
    bool found = false;

    while (std::getline(ipersons_file, line)) {
        std::istringstream ss(line);
        std::string current_id;
        std::string passport;
        std::string name;
        std::string surname;
        std::string patronymic;
        std::string birth_date;
        std::string email;

        std::getline(ss, current_id, ',');
        std::getline(ss, passport, ',');
        std::getline(ss, name, ',');
        std::getline(ss, surname, ',');
        std::getline(ss, patronymic, ',');
        std::getline(ss, birth_date, ',');
        std::getline(ss, email, ',');

        if (current_id == _id) {
            lines.push_back(current_id + ',' + passport + ',' + name + ',' + surname + ',' + patronymic + ',' + new_birth_date + ',' + email);
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

    _birth_date = new_birth_date;
}

void CSVGuest::change_email(const std::string& new_email) {
    TVector<std::string> lines;
    std::ifstream ipersons_file(_path_to_persons);

    if (!ipersons_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading");
    }

    std::string line;
    bool found = false;

    while (std::getline(ipersons_file, line)) {
        std::istringstream ss(line);
        std::string current_id;
        std::string passport;
        std::string name;
        std::string surname;
        std::string patronymic;
        std::string birth_date;
        std::string email;

        std::getline(ss, current_id, ',');
        std::getline(ss, passport, ',');
        std::getline(ss, name, ',');
        std::getline(ss, surname, ',');
        std::getline(ss, patronymic, ',');
        std::getline(ss, birth_date, ',');
        std::getline(ss, email, ',');

        if (current_id == _id) {
            lines.push_back(current_id + ',' + passport + ',' + name + ',' + surname + ',' + patronymic + ',' + birth_date + ',' + new_email);
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

    _email = new_email;
}

void CSVGuest::remove() const {
    TVector<std::string> lines;
    std::ifstream ipersons_file(_path_to_persons);

    if (!ipersons_file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading");
    }

    std::string line;
    bool found = false;

    while (std::getline(ipersons_file, line)) {
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

    std::ofstream opersons_file(_path_to_persons);
    if (!opersons_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для записи");
    }

    for (const auto& l : lines) {
        opersons_file << l << "\n";
    }
}

void CSVGuest::upload_data() {
    std::ifstream file(_path_to_persons);

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open the file for reading: " + _path_to_persons);
    }

    std::string line;
    std::getline(file, line);
    std::string current_id;
    bool record_found = false;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, current_id, ',');

        if (current_id != _id)
            continue;

        std::getline(ss, _passport, ',');
        std::getline(ss, _name, ',');
        std::getline(ss, _surname, ',');
        std::getline(ss, _patronymic, ',');
        std::getline(ss, _birth_date, ',');
        std::getline(ss, _email, ',');
        record_found = true;
        is_fresh = true;
        break;
    }

    if (!record_found) {
        throw std::runtime_error("Гость с passport " + _id + " не найден в таблице");
    }
}

bool CSVGuest::check_passport(const std::string& passport) {
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
        throw std::runtime_error("Couldn't open the file for reading" + _path_to_persons);
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

bool CSVGuest::check_name(const std::string& name) {
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

bool CSVGuest::check_date(const std::string& date) {
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
