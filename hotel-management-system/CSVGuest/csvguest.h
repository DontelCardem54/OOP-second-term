#pragma once

#include <string>

#include "iguest.h"

class CSVGuest : public IGuest {
private:
    bool is_fresh = false;
    std::string _id;
    std::string _passport;
    std::string _name;
    std::string _surname;
    std::string _patronymic;
    std::string _birth_date;
    std::string _email;
    std::string _path_to_persons = "..\\persons.csv";
    std::string _path_to_guests = "..\\guests.csv";

public:
    CSVGuest(const CSVGuest&) = delete;
    CSVGuest& operator=(const CSVGuest&) = delete;

    CSVGuest(const std::string&);
    CSVGuest(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
    
    std::string id() override;
    std::string name() override;
    std::string surname() override;
    std::string patronymic() override;
    std::string passport() override;
    std::string birth_date() override;
    std::string email() override;

    void change_passport(const std::string& new_passport) override;
    void change_name(const std::string& new_name) override;
    void change_surname(const std::string& new_surname) override;
    void change_patronymic(const std::string& new_patronymic) override;
    void change_birth_date(const std::string& new_birth_date) override;
    void change_email(const std::string& new_email) override;

    void remove() const override;

private:
    void upload_data();
    bool check_passport(const std::string&);
    bool check_name(const std::string&);
    bool check_date(const std::string&);
};