#pragma once

#include <string>
#include "iroom.h"

class CSVRoom : public IRoom {
    bool is_fresh = false;
private:
    std::string _id;
    std::string _number;
    std::string _category_id;
    std::string _category_name;
    std::string _category_price;
    std::string _beds_count;
    std::string _state;
    std::string _path_to_rooms = "..\\rooms.csv";
    std::string _path_to_categories = "..\\room_categories.csv";
public:
    CSVRoom(const std::string& id);

    std::string id() override;
    std::string number() override;
    std::string category_name() override;
    std::string category_price() override;
    std::string beds_count() override;
    std::string state() override;
    bool is_available() override;
    bool is_occupied() override;
    void change_state(RoomState new_state) override;


private:
    void upload_data();
};
