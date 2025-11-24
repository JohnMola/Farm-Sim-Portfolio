#include <string>

#include "carrot.hpp"

std::string Carrot::symbol() {
    if(age == 0) {
        return "v";
    } else if (age == days_to_sprout) {
        return "V";
    } else {
        return "W";
    }
}

void Carrot::end_day() {
    if(watered){
        age += 2;
    }else{
        age += 1;
    }
    watered = false;
}

bool Carrot::water() {
    watered = true;
}

bool Carrot::is_harvestable() {
    return age >= 1;
}

int Carrot::get_days() {
    return age;
}