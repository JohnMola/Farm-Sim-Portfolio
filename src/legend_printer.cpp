#include "legend_printer.hpp"

std::string LegendPrinter::pp() {
    std::string output = "";
    output += "      LEGEND      \n";
    output += "@  Player\n";
    output += ".  Soil\n";
    output += "#  Tilled soil\n";
    output += "\nVegetables\n";
    output += "Carrot:           C\n";
    output += "Lettuce:          L\n";
    output += "Spinach:          U\n";
    output += "Beet:             B\n";
    output += "Brussels Sprouts: N\n";
    output += "\n   CONTROLS    \n";
    output += "w  Move up\n";
    output += "a  Move left\n";
    output += "s  Move down\n";
    output += "d  Move right\n";
    output += "c  Plant carrot\n";
    output += "l  Plant lettuce\n";
    output += "u  Plant spinach\n";
    output += "b  Plant beet\n";
    output += "n  Plant brussel sprout\n";
    output += "h  Harvest\n";
    output += "t  Water\n";
    output += "e  End day\n";
    output += "?  Show legend\n";
    output += "q  Quit\n";
    return output;
}
