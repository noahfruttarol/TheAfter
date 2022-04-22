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
#include <set>
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

    void gen_level(point size);

    void gen_doors(point size);

    void remove_wall(point p, point q);

    bool make_move(std::string move);
};


#endif //THEAFTER_GAME_STATE_HPP
