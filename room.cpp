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

void room::print() {
    std::cout << "You are in " << name << std::endl;
    std::cout << "There is: " << std::endl;
    int k {0};
    for (auto i: items) {
        k++;
        std::cout << i.get_name() << ", ";
        if(!k%3)
            std::cout << std::endl;
    }
}
