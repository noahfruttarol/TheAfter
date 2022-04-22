#include "game_state.hpp"
#include <iostream>
#include <string>
#include <utility>

void run(game_state game){
    game.gen_level(std::make_pair(5,4));

}

int main() {
    std::string Name = "The After";
    std::string Version = "0.1";
    std::string Author = "Noah Fruttarol";

    std::cout << Name << " " << Version << " by " << Author << std::endl << std::endl;

    std::cout << "What is your name" << std::endl;
    std::string player {};
    std::cin >> player;

    std::cout << "OK, generating game" << std::endl;
    game_state game {player, 1};


    return 0;
}
