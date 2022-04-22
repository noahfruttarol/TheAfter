//
// Created by noahf on 11/04/2022.
//

#include "player.hpp"

player::player(std::string name): name(name), heath(100), rads(0) {}

std::string player::get_name() {return name;}

std::vector<item> player::get_inventory() {return inventory;}

item player::get_item(std::string) {}