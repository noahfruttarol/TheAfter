//
// Created by noahf on 11/04/2022.
//
#include "game_state.hpp"

game_state::game_state(std::string player_name, int diff): player_character{ player{player_name}}, difficulty(diff) {}

bool operator<(point a, point b){
    if(a.first < b.first){
        return true;
    }else if(a.first > b.first){
        return false;
    }else{
        return a.second < b.second;
    }
}

bool operator==(point a, point b){
    return a.first == b.first && a.second == b.second;
}

void game_state::gen_level(point size) {
    exit = std::make_pair(size.first - 1, size.second - 1);
    std::vector<std::vector<std::shared_ptr<room>>> map;
    for (int i = 0; i < size.first; ++i) {
        std::vector<std::shared_ptr<room>> row;
        for (int j = 0; j < size.second; ++j) {
            std::string temp_str{"room"};
            temp_str += std::to_string(i) + std::to_string(j);
            room temp{temp_str};
            row.push_back(std::make_shared<room>(temp));
        }
        map.push_back(row);
    }
    current_level = map;
    current_room = current_level[0][0];
    gen_doors(size);
}

bool is_valid_point(const point& size, point p){
        if(p.first >= size.first || p.first < 0) {
            //std::cout << "first" << p.first << p.second << std::endl;
            return false;
        }
        else if (p.second >= size.second || p.second < 0) {
            //std::cout << "second" << p.first << p.second << std::endl;
            return false;
        }

        return true;
    }

bool contains(const std::vector<point>& V, point p){
    for(point q: V){
        if(p.first == q.first && p.second == q.second)
            return true;
    }
    return false;
}

std::vector<point> game_state::get_adjacent(const std::vector<point>& finished, point current,const point& size){
    std::vector<point> adjacent {};
    current.first--;
    if(is_valid_point(size, current) && !contains(finished, current))
        adjacent.push_back(current);

    current.first++;
    current.second--;
    if(is_valid_point(size, current) && !contains(finished, current))
        adjacent.push_back(current);

    current.first++;
    current.second++;
    if(is_valid_point(size, current) && !contains(finished, current))
        adjacent.push_back(current);

    current.first--;
    current.second++;
    if(is_valid_point(size, current) && !contains(finished, current))
        adjacent.push_back(current);
    
    return adjacent;
}

void game_state::gen_doors(const point& size) {
    //maze generation
    srand(time(0));
    point current {0,0};
    std::vector<point> finished;
    finished.push_back(current);
    while(finished.size() != size.first*size.second) {
        //std::cout << "what is going on" << std::endl;

        int index = finished.size();
        std::vector<point> adjacent {};
        while(adjacent.size() == 0 && index > 0){
            index--;
            current = finished.at(index);
            adjacent = get_adjacent(finished, current, size);
            //std::cout << adjacent.size() << std::endl;
        }
        
        if(index < 0)return;

        index = rand() % adjacent.size();
        remove_wall(current, adjacent.at(index));
        finished.push_back(adjacent.at(index));
    }
}

void game_state::remove_wall(point p, point q) {
    switch (p.first - q.first + 2 * (p.second - q.second)) {
        case 1: //
            current_level.at(q.first).at(q.second)->is_path["down"] = true;
            current_level.at(p.first).at(p.second)->is_path["up"] = true;
            return;
        case -1:
            current_level.at(q.first).at(q.second)->is_path["up"] = true;
            current_level.at(p.first).at(p.second)->is_path["down"] = true;
            return;
        case 2:
            current_level.at(q.first).at(q.second)->is_path["right"] = true;
            current_level.at(p.first).at(p.second)->is_path["left"] = true;
            return;
        case -2:
            current_level.at(q.first).at(q.second)->is_path["left"] = true;
            current_level.at(p.first).at(p.second)->is_path["right"] = true;
            return;
        default:
            return;
    }
}

bool game_state::make_move(std::string move) {
    if (move == "right" && current_room->is_path["right"]) {
        location.second++;
    }else if (move == "left" && current_room->is_path["left"]){
        location.second--;
    }else if (move == "up" && current_room->is_path["up"]){
        location.first--;
    }else if (move == "down" && current_room->is_path["down"]){
        location.first++;
    }else{
        return false;
    }
    current_room = current_level.at(location.first).at(location.second);
    return true;
}

bool game_state::is_at_exit() {
    return location == exit;
}

void game_state::print_state() {
    current_room->print();
}

void game_state::print_level() {
    for (int i = 0; i < current_level.size(); ++i) {
        for (int j = 0; j < current_level.at(i).size(); ++j) {
            current_level.at(i).at(j)->print();
        }
    }
}