#ifndef GAME_H
#define GAME_H



#include <utility>
#include <string>
#include <random>

namespace Zeta {

enum class Operation {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
};

class Game {

public:
    explicit Game(int min, int max, const std::vector<Operation>& operations);
    ~Game();
    void run_game(int time_limit);
    __attribute__((always_inline)) bool validate_answer(int input, int answer);


private:
    int min_range, max_range;
    std::mt19937 rng_seed;
    std::vector<Operation> operations;
    __attribute__((always_inline)) int generate_random_number();
    __attribute__((always_inline)) Operation get_operation(const std::vector<Operation>& avaliable_operations);
    std::pair<std::string, int> generate_question();


};
}






#endif // GAME_H