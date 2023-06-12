#include "food.h"

Food::Food() {
    gerarComida();
}

void Food::gerarComida() {
    pos.X = rand() % 75 + 1;
    pos.Y = rand() % 25 + 1;
}

COORD Food::getPos() {
    return pos;
}