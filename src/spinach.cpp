#include "spinach.hpp"

std::string Spinach::symbol(){
    if(age < 2){
        return "#";
    }
    else if(age == 2){
        return "u";
    }
    else{
        return "U";
    }
}

void Spinach::end_day(){
    if(watered){
        age += 2;
    }
    else{
        age += 1;
    }
    watered = false;
}

bool Spinach::is_harvestable(){
    return age >= 3;
}

void Spinach::water(){
    watered = true;
}

int Spinach::get_days(){
    return age;
}