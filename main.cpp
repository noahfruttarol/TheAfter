#include "game_state.hpp"
#include <iostream>
#include <string>
#include <utility>

void run(game_state& game){
    std::pair<int, int> p {5,4};
    game.game_state::gen_level(p);
    while (!game.is_at_exit()){
        std::string input {};
        std::cout << "make move" << std::endl;
        std::cin >> input;
        game.make_move(input);
        game.print_state();
    }
    std::cout << "You made it to the exit!";

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

    run(game);

    return 0;
}
