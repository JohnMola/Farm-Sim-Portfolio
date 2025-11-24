#pragma once

#include <string>

#include "plot.hpp"

class Brussel_Sprout : public Plot{
private:
    int age = 0;
    bool watered = false;
public:
    std::string symbol() override;
    void end_day() override;
    bool is_harvestable() override;
    int get_days();
    void water() override;
};