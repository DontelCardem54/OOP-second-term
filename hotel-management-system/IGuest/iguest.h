#pragma once
#include <string>

class IGuest {
public:
    virtual std::string passport() = 0;
    virtual std::string name() = 0;
    virtual std::string surname() = 0;
    virtual std::string patronymic() = 0;
    virtual std::string birth_date() = 0;
    virtual std::string email() = 0;
    virtual void remove() const = 0;

    virtual void change_passport(const std::string& new_passport) = 0;
    virtual void change_name(const std::string& new_name) = 0;
    virtual void change_surname(const std::string& new_surname) = 0;
    virtual void change_patronymic(const std::string& new_patronymic) = 0;
    virtual void change_birth_date(const std::string& new_birth_date) = 0;
    virtual void change_email(const std::string& new_email) = 0;

    virtual ~IGuest() = default;
};