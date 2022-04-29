//
// Created by noahf on 11/04/2022.
//

#ifndef THEAFTER_GAME_STATE_HPP
#define THEAFTER_GAME_STATE_HPP
#include "player.hpp"
#include "room.hpp"
#include "item.hpp"
#include <string>
#include <vector>
#include <utility>
#include <memory>
#include <cstdlib>
#include <ctime>

using point = std::pair<int,int>;


class game_state {
    player player_character;
    unsigned int difficulty;
    std::shared_ptr<room> current_room;
    point location;
    std::vector<std::vector<std::shared_ptr<room>>> current_level;
    int level;
    int level_type;
    point exit;

public:
    //constructor
    game_state(std::string player_name, int diff);

    std::vector<point> get_adjacent(const std::vector<point>& finished, point current,const point& size);

    void gen_doors(const point& size);

    void remove_wall(point p, point q);

    void gen_level(point size);

    bool make_move(std::string move);

    bool is_at_exit();

    void print_state();

    void print_level();
};


#endif //THEAFTER_GAME_STATE_HPP
