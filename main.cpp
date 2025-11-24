#include <iostream>

#include "src/player.hpp"
#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"
#include "src/ansi_clear.hpp"
#include "src/lettuce.hpp"
#include "src/spinach.hpp"
#include "src/beet.hpp"
#include "src/brussel_sprout.hpp"

int main() {
    Player player(7, 8);
    Farm farm(7, 8, &player);
    FarmPrinter printer(&farm);
    int current_day = 1;
    bool game_in_progress = true;
    std::string player_input;

    while(game_in_progress) {
        ansi_clear();
        std::cout << "Day " << current_day << std::endl;
        std::cout << printer.pp() << std::endl;
        std::cin >> player_input;

        if(player_input == "q") {
            game_in_progress = false;
        } else if(player_input == "d") {
            player.move_right();
        } else if(player_input == "s") {
            player.move_down();
        } else if(player_input == "a") {
            player.move_left();
        } else if(player_input == "w") {
            player.move_up();
        } else if(player_input == "c") {
            Carrot *carrot = new Carrot();
            farm.plant(player.row(), player.column(), carrot);
        } else if(player_input == "h"){
            farm.harvest(player.row(), player.column());
        } else if(player_input == "e"){
            farm.end_day();
        } else if(player_input == "t"){
            farm.water(player.row(),player.column());
        } else if(player_input == "l"){
            Lettuce *lettuce = new Lettuce();
            farm.plant(player.row(), player.column(), lettuce);
        } else if(player_input == "u"){
            Spinach *spinach = new Spinach();
            farm.plant(player.row(), player.column(), spinach);
        } else if(player_input == "b"){
            Beet *beet = new Beet();
            farm.plant(player.row(), player.column(), beet);
        } else if(player_input == "n"){
            Brussel_Sprout *brussel_sprout = new Brussel_Sprout();
            farm.plant(player.row(), player.column(), brussel_sprout);
        }
    }
}
