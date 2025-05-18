#pragma once
#include <string>

class IRoom {
public:
    virtual std::string number() = 0;
    virtual std::string category_name() = 0;
    virtual std::string category_price() = 0;
    virtual std::string beds_count() = 0;
    virtual std::string state() = 0;

    virtual ~IRoom() = default;
};