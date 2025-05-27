#pragma once
#include <string>

enum class RoomState {
    Available,
    Occupied,
    UnderMaintenance
};

class IRoom {
public:
    virtual std::string id() = 0;
    virtual std::string number() = 0;
    virtual std::string category_name() = 0;
    virtual std::string category_price() = 0;
    virtual std::string beds_count() = 0;
    virtual std::string state() = 0;
    virtual bool is_available() = 0;
    virtual bool is_occupied() = 0;
    virtual void change_state(RoomState) = 0;

    virtual ~IRoom() = default;
};