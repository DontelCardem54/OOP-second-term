#pragma once

#include <string>

#include "iguest.h"

class CSVGuest : public IGuest {
private:
    std::string _name;
    std::string _surname;
    std::string _patronymic;
    std::string _passport;
    std::string _birth_date;
    std::string _email;
    std::string _path_to_table = "../Data/persons.csv";

public:
    CSVGuest(const std::string& passport);
    std::string name() const override { return _name; }
    std::string surname() const override { return _surname; }
    std::string patronymic() const override { return _patronymic; }
    std::string passport() const override { return _passport; }
    std::string birth_date() const override { return _birth_date; }
    std::string email() const override { return _email; }
    void remove() const override;
    void save() const override;

private:
    void upload_data();
};