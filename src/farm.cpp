#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <ctime>

#include "farm.hpp"
#include "soil.hpp"
#include "bunny.hpp"

Farm::Farm(int rows, int columns, Player *player) : rows(rows), columns(columns), player(player) {
    if(player == nullptr) {
        throw std::invalid_argument("Player pointer cannot be 0");
    }
    if(rows <= 0 || columns <= 0) {
        throw std::invalid_argument("Farm dimensions have to be be positive");
    }
    srand(time(nullptr));
    for(int i = 0; i < rows; i++) {
        std::vector<Plot *> row;
        for(int j = 0; j < columns; j++) {
            Soil *soil = new Soil();
            row.push_back(soil);
        }
        plots.push_back(row);
    }
}

int Farm::number_of_rows() {
    return rows;
}

int Farm::number_of_columns() {
    return columns;
}

std::string Farm::get_symbol(int row, int column) {
    if(player->row() == row && player->column() == column) {
        return "@";
    }
    for(Bunny *bunny : bunnies) {
        if(bunny->get_row() == row && bunny->get_column() == column) {
            return bunny->get_symbol();
        }
    }
    return plots.at(row).at(column)->symbol();
}

void Farm::plant(int row, int column, Plot *plot) {
    Plot *current_plot = plots.at(row).at(column);
    if(current_plot->symbol() == ".") {
        plots.at(row).at(column) = plot;
        delete current_plot;
    } else {
        delete plot;
    }
}

void Farm::water(int row, int column) {
    Plot *current_plot = plots.at(row).at(column);
    current_plot->water();
}

void Farm::harvest(int row, int column){
    Plot *current_plot = plots.at(row).at(column);
    if (current_plot->is_harvestable()){
        Plot *new_plot = new Soil();
        plots.at(row).at(column) = new_plot;
        delete current_plot;
    }
}

void Farm::start_day() {
  if(bunny_spawn) {
    int spawn_chance = rand() % 100;
    if(spawn_chance < 30) {
      spawn_bunny();
    }
  }

  for(Bunny *bunny : bunnies) {
    int bunny_row = bunny->get_row();
    int bunny_col = bunny->get_column();
    if(is_valid_position(bunny_row, bunny_col)) {
      Plot *current_plot = plots.at(bunny_row).at(bunny_col);
      if(current_plot->symbol() != ".") {
        plots.at(bunny_row).at(bunny_col) = new Soil();
        delete current_plot;
      }
    }
  }

  std::vector<Bunny *> bunnies_to_remove;
  for(Bunny *bunny : bunnies) {
    int old_row = bunny->get_row();
    int old_col = bunny->get_column();

    bunny->move();

    int new_row = bunny->get_row();
    int new_col = bunny->get_column();

    if(new_row == player->row() && new_col == player->column()) {
      bool adjusted = false;
      if(old_row < player->row() && is_valid_position(player->row() - 1, player->column())) {
        bunny->set_position(player->row() - 1, player->column());
        adjusted = true;
      } else if(old_row > player->row() && is_valid_position(player->row() + 1, player->column())) {
        bunny->set_position(player->row() + 1, player->column());
        adjusted = true;
      } else if(old_col < player->column() && is_valid_position(player->row(), player->column() - 1)) {
        bunny->set_position(player->row(), player->column() - 1);
        adjusted = true;
      } else if(old_col > player->column() && is_valid_position(player->row(), player->column() + 1)) {
        bunny->set_position(player->row(), player->column() + 1);
        adjusted = true;
      }
      if(!adjusted) {
        bunnies_to_remove.push_back(bunny);
      }
    }
  }

  for(int i = bunnies.size() - 1; i >= 0; i--) {
    Bunny *bunny = bunnies[i];
    bool should_remove = false;

    for(Bunny *marked : bunnies_to_remove) {
      if(marked == bunny) {
        should_remove = true;
        break;
      }
    }

    if(!should_remove && (!is_valid_position(bunny->get_row(), bunny->get_column()) ||
       (bunny->get_row() == player->row() && bunny->get_column() == player->column()))) {
      should_remove = true;
    }

    if(should_remove) {
      delete bunny;
      bunnies.erase(bunnies.begin() + i);
    }
  }

  check_player_proximity();
}

void Farm::end_day() {
  day++;
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      plots.at(i).at(j)->end_day();
    }
  }
  start_day();
}

bool Farm::is_valid_position(int row, int column) {
  return row >= 0 && row < rows && column >= 0 && column < columns;
}

bool Farm::has_bunny_at(int row, int column) {
  for(Bunny *bunny : bunnies) {
    if(bunny->get_row() == row && bunny->get_column() == column) {
      return true;
    }
  }
  return false;
}

int Farm::get_day() {
  return day;
}

void Farm::spawn_bunny() {
  int edge = rand() % 4;
  int spawn_row = -1;
  int spawn_col = -1;
  int dir_row, dir_col;

  switch(edge) {
    case 0:
      spawn_row = 0;
      spawn_col = rand() % columns;
      dir_row = 1;
      dir_col = 0;
      break;
    case 1:
      spawn_row = rows - 1;
      spawn_col = rand() % columns;
      dir_row = -1;
      dir_col = 0;
      break;
    case 2:
      spawn_row = rand() % rows;
      spawn_col = 0;
      dir_row = 0;
      dir_col = 1;
      break;
    case 3:
      spawn_row = rand() % rows;
      spawn_col = columns - 1;
      dir_row = 0;
      dir_col = -1;
      break;
  }

  bool is_on_edge = (spawn_row == 0 || spawn_row == rows - 1 || spawn_col == 0 || spawn_col == columns - 1);
  if(!is_on_edge || spawn_row < 0 || spawn_col < 0) {
    return;
  }

  if(spawn_row == player->row() && spawn_col == player->column()) {
    return;
  }

  Bunny *bunny = new Bunny(spawn_row, spawn_col, dir_row, dir_col);
  bunnies.push_back(bunny);
}

void Farm::check_player_proximity() {
  int player_row = player->row();
  int player_col = player->column();

  for(Bunny *bunny : bunnies) {
    int bunny_row = bunny->get_row();
    int bunny_col = bunny->get_column();
    int row_diff = (bunny_row > player_row) ? (bunny_row - player_row) : (player_row - bunny_row);
    int col_diff = (bunny_col > player_col) ? (bunny_col - player_col) : (player_col - bunny_col);

    bool is_adjacent = (row_diff == 1 && col_diff == 0) || (row_diff == 0 && col_diff == 1);

    if(is_adjacent) {
      bunny->set_scared(player_row, player_col);
    }
  }
}

int Farm::get_bunny_count() {
  return bunnies.size();
}

bool Farm::get_bunny_spawn() {
  return bunny_spawn;
}

void Farm::set_bunny_spawn(bool enabled) {
  bunny_spawn = enabled;
}

Farm::~Farm() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            delete plots.at(i).at(j);
        }
    }
  for(Bunny *bunny : bunnies) {
    delete bunny;
  }
}

