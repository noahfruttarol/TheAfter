//
// Created by noahf on 11/04/2022.
//

#include "room.hpp"

room::room(int type, int level, int level_type, int diff) {
    name = "place";
    is_path["right"] = false;
    is_path["left"] = false;
    is_path["up"] = false;
    is_path["down"] = false;
}

room::room(std::string s) {
    name = s;
    is_path["right"] = false;
    is_path["left"] = false;
    is_path["up"] = false;
    is_path["down"] = false;
}

