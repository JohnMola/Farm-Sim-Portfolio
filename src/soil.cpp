#include "soil.hpp"

std::string Soil::symbol() {
    return ".";
}

void Soil::end_day() {
    // skip
}

bool Soil::is_soil() {
    return true;
}

bool Soil::is_harvestable() {
    return false;
}