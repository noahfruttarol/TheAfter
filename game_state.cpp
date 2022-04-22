//
// Created by noahf on 11/04/2022.
//
#include "game_state.hpp"

game_state::game_state(std::string player_name, int diff): player_character{ player{player_name}}, difficulty(diff) {}

bool operator<(std::pair<int, int> a, std::pair<int, int> b){
    if(a.first < b.first){
        return true;
    }else if(a.first > b.first){
        return false;
    }else{
        return a.second < b.second;
    }
}

void game_state::gen_level(point size) {
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

void game_state::gen_doors(point size) {
    auto is_valid_point = [&](point q){
        if(q.first >= size.first || q.first < 0)
            return false;
        else if (q.second >= size.second || q.second < 0)
            return false;
        return true;
    };
    //maze generation
    srand(time(0));
    point current {0,0};
    point p;
    int done_before = 1;
    std::set<point> finished {current};
    while(finished.size() < size.first*size.second) {
        std::vector<point> adjacent {};

        if(is_valid_point(std::make_pair(current.first + 1, current.second)) && !finished.contains(std::make_pair(current.first + 1, current.second)))
            adjacent.push_back(std::make_pair(current.first + 1, current.second));

        if(is_valid_point(std::make_pair(current.first - 1, current.second)) && !finished.contains(std::make_pair(current.first - 1, current.second)))
            adjacent.push_back(std::make_pair(current.first - 1, current.second));

        if(is_valid_point(std::make_pair(current.first, current.second + 1)) && !finished.contains(std::make_pair(current.first, current.second + 1)))
            adjacent.push_back(std::make_pair(current.first, current.second + 1));

        if(is_valid_point(std::make_pair(current.first, current.second - 1)) && !finished.contains(std::make_pair(current.first, current.second - 1)))
            adjacent.push_back(std::make_pair(current.first, current.second - 1));

        if(adjacent.size() == 0){
            auto scuffed = finished.begin();
            for (int i = 0; i < done_before && scuffed != finished.end(); ++i) {
                current = *scuffed;
                scuffed++;
            }
            continue;
        }

        int edges = rand()%(adjacent.size()+2);
        switch (edges) {
            case 4:
                edges = 2;
                break;
            default:
                edges = 1;
        }

        point p = current;
        for (int i = 0; i < edges; ++i) {
            int j = rand()%adjacent.size();
            p = adjacent.at(j);
            adjacent.at(j) = adjacent.back();
            adjacent.pop_back();
            remove_wall(current, p);
            finished.insert(p);
        }
        current = p;
    }
}

void game_state::remove_wall(point p, point q) {
    switch (p.first - q.first + 2 * (p.second - p.first)) {
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