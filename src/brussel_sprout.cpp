#include "brussel_sprout.hpp"

std::string Brussel_Sprout::symbol(){
    if(age < 5){
        return "#";
    }
    else if(age >= 5 && age < 10){
        return "n";
    }
    else{
        return "N";
    }
}

void Brussel_Sprout::end_day(){
    if(watered){
        age += 2;
    }
    else{
        age += 1;
    }
    watered = false;
}

bool Brussel_Sprout::is_harvestable(){
    return age >= 10;
}

void Brussel_Sprout::water(){
    watered = true;
}

int Brussel_Sprout::get_days(){
    return age;
}