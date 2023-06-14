#include "food.h"
#include <random>

Food::Food() {
    gerarComida();
}

void Food::gerarComida() {

    // Isso resolve o problema aparentemente!
    std::mt19937 mt(time(nullptr));
    std::uniform_int_distribution<short> randX(1, 74);
    std::uniform_int_distribution<short> randY(1, 24);

    pos.X = randX(mt);
    pos.Y = randY(mt);

    /*
    srand(time(nullptr));
    pos.X = rand() % 75;
    pos.Y = rand() % 25;
    */
}

COORD Food::getPos() {
    return pos;
}