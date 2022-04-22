//
// Created by noahf on 11/04/2022.
//

#ifndef THEAFTER_ROOM_HPP
#define THEAFTER_ROOM_HPP
#include "item.hpp"
#include "enemy.hpp"
#include <vector>
#include <string>
#include <random>
#include <map>

class room {
    std::string name;
    std::vector<item> items;
    std::vector<enemy> enemies;
    unsigned rads;

public:
    std::map<std::string, bool> is_path;

    room(int type, int level, int level_type, int diff);

    explicit room(std::string s);
};


#endif //THEAFTER_ROOM_HPP
