#include "lettuce.hpp"

std::string Lettuce::symbol(){
    if(age < 1){
        return "#";
    } else if (age < 2) {
        return "l";
    }
    else{
        return "L";
    }
}

void Lettuce::end_day(){
    if(watered){
        age += 2;
    }
    else{
        age += 1;
    }
    watered = false;
}

bool Lettuce::is_harvestable(){
    return age >= 2;
}

void Lettuce::water(){
    watered = true;
}

int Lettuce::get_days(){
    return age;
}