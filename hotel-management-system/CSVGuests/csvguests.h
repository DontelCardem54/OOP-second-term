#pragma once

#include <string>
#include "TVector.h"
#include "iguests.h"
#include "csvguest.h"
#include "csvfile.h"

class CSVGuests : public IGuests {
private:
    int _current_id;
    CSVFile _persons_file;
    std::string _path_to_persons = "..\\persons.csv";
    std::string _path_to_guests = "..\\guests.csv";

public:
    CSVGuests();
    IGuest* add(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&) override;
    void remove(const std::string& id) override;
    TVector<IGuest*>* find(const std::string& passport) override;
    void clear() override;
    IGuest* get_by_passport(const std::string& passport) override;
    IGuest* get_by_id(const std::string& id) override;
private:
    void update_id();
    bool check_passport(const std::string&);
    bool check_name(const std::string&);
    bool check_date(const std::string&);
};