#pragma once

#include <string>
#include <regex>

class GuestValidator {
public:
    bool check_passport(const std::string& passport) {
        if (passport.length() != 10) {
            return false;
        }

        for (char c : passport) {
            if (!std::isdigit(c)) {
                return false;
            }
        }

        return true;
    }

    bool isNameValid(const std::string& name) {
        return !name.empty() &&
            name.length() <= 15 &&
            std::all_of(name.begin(), name.end(), ::isalpha);
    }

    bool isBirthDateValid(const std::string& date) {
        std::regex pattern(R"(^\d{4}-\d{2}-\d{2}$)");
        return std::regex_match(date, pattern);
    }

    bool isEmailValid(const std::string& email) {
        std::regex pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
        return std::regex_match(email, pattern);
    }

    bool validateAll(const std::string& passport,
        const std::string& name,
        const std::string& birthDate,
        const std::string& email) {
        return isPassportValid(passport) &&
            isNameValid(name) &&
            isBirthDateValid(birthDate) &&
            isEmailValid(email);
    }
};