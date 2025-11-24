#include "soil.hpp"

std::string Soil::symbol() {
    return ".";
}

void Soil::end_day() {
    // no-op
}

bool Soil::water() {
    return true;
}

bool Soil::is_harvestable() {
    return false;
}