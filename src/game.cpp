#include "game.h"
#include <iostream>
#include <time.h>

namespace Zeta {

Game::Game(int min, int max, const std::vector<Operation>& selected_operations) :
min_range(min), max_range(max), operations(selected_operations) {
    std::random_device rd;
    rng_seed = std::mt19937(rd());
}

Game::~Game() {

}
void Game::run_game(int time_limit) {
    using clock = std::chrono::steady_clock;
    auto start_time = clock::now();
    int score = 0;

    while (std::chrono::duration_cast<std::chrono::seconds>(clock::now() - start_time).count() < time_limit) {
        auto [question, correct_answer] = generate_question();
        std::cout << question << " = ?" << std::endl;

        int user_answer;
        std::cin >> user_answer;

        if (validate_answer(user_answer, correct_answer)) {
            std::cout << "Correct!" << std::endl;
            score++;
        } else {
            std::cout << "Wrong! The correct answer was " << correct_answer << std::endl;
        }
    }

    std::cout << "Time's up! Your score: " << score << std::endl;
}

std::pair<std::string, int> Game::generate_question() {
    int num1 = generate_random_number();
    int num2 = generate_random_number();
    Operation op = get_operation(operations);

    int answer;
    std::string question;
    
    switch (op) {
        case Operation::ADDITION:
            answer = num1 + num2;
            question = std::to_string(num1) + " + " + std::to_string(num2);
            break;
        case Operation::SUBTRACTION:
            answer = num1 - num2;
            question = std::to_string(num1) + " - " + std::to_string(num2);
            break;
        case Operation::MULTIPLICATION:
            answer = num1 * num2;
            question = std::to_string(num1) + " * " + std::to_string(num2);
            break;
        case Operation::DIVISION:
            // Ensure no division by zero
            num2 = num2 == 0 ? 1 : num2;
            answer = num1 / num2;
            question = std::to_string(num1) + " / " + std::to_string(num2);
            break;
        default:
            throw std::runtime_error("Unknown operation");
    }

    return {question, answer};
}

__attribute__((always_inline)) bool Game::validate_answer(int input, int answer) {
    return input == answer;
}

__attribute__((always_inline)) int Game::generate_random_number() {
    std::uniform_int_distribution<int> distr(min_range, max_range);
    return distr(rng_seed);
}

__attribute__((always_inline)) Operation Game::get_operation(const std::vector<Operation>& avaliable_operations) {
    int n = avaliable_operations.size() - 1;
    std::uniform_int_distribution<int> distr(0, n);
    return avaliable_operations[distr(rng_seed)];
}






}