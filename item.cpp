//
// Created by noahf on 11/04/2022.
//

#include "item.hpp"

item::item(std::string name, int id): name(name), id(id){}

std::string item::get_name() {return name;}

int item::get_id() {return id;}

bool item::operator!=(item other_item) {
    return get_id() != other_item.get_id();
}

bool  item::operator==(item other_item) {
    return !(*this != other_item);
}

