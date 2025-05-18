#pragma once

#include <string>
#include "irooms.h"
#include "TVector.h"

class CSVRooms : public IRooms {
private:
    int _current_id;
    std::string _path_to_rooms = "..\\rooms.csv";
    std::string _path_to_categories = "..\\room_categories.csv";

public:
    CSVRooms();
    /*IGuest* add(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&) override;
    void remove(const std::string& id) override;*/
    TVector<IRoom*>* find(const std::string& number,
        const std::string& category,
        const std::string& beds_count,
        const std::string& state) override;
    void clear();
private:
    void update_id();
};