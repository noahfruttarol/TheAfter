//
// Created by noahf on 11/04/2022.
//

#ifndef THEAFTER_PLAYER_HPP
#define THEAFTER_PLAYER_HPP
#include "item.hpp"
#include <string>
#include <vector>

class player {
    std::string name;
    std::vector<item> inventory;
    int heath;
    int rads;

public:
    player(std::string name);

    std::string get_name();

    std::vector<item> get_inventory();

    item get_item(std::string);

    bool has_item(item i);
    bool has_item(std::string item_name);
};


#endif //THEAFTER_PLAYER_HPP
