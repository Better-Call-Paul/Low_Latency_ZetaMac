#include "game.h"

#include <thread>
#include <iostream>

int main() {

    Zeta::Game game(1, 10, {Zeta::Operation::ADDITION, Zeta::Operation::SUBTRACTION, Zeta::Operation::MULTIPLICATION, Zeta::Operation::DIVISION});
    int time_limit = 60;
    game.run_game(time_limit);
    std::cout << "Hello World" << "\n";

    return 0;
}