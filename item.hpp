//
// Created by noahf on 11/04/2022.
//

#ifndef THEAFTER_ITEM_HPP
#define THEAFTER_ITEM_HPP
#include <string>

class item {
    std::string name;
    int id;
    bool player_use;

public:
    item(std::string name, int id);

    std::string get_name();

    int get_id();

    bool operator==(std::string name);
    bool operator==(item other_item);
    bool operator!=(item other_item);
};


#endif //THEAFTER_ITEM_HPP
