#include "food.h"

Food::Food() {
    gerarComida();
}

void Food::gerarComida() {
    srand(time(nullptr));
    pos.X = rand() % 75;
    pos.Y = rand() % 25;
}

COORD Food::getPos() {
    return pos;
}