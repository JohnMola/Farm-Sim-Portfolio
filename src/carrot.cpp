#include <string>

#include "carrot.hpp"

std::string Carrot::symbol() {
    if(age == 0){
        return "v";
    }else if(age >= 1){
        return "V";
    }
}
void Carrot::end_day(){
    if(watered){
        age += 2;
    }else{
        age += 1;
    }
    watered = false;
}

void Carrot::water() {
    watered = true;
}

bool Carrot::is_harvestable() {
    return age >= 1;
}

int Carrot::get_days() {
    return age;
}