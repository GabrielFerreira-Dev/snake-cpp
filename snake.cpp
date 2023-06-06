#include "snake.h"
#include <iostream>

Snake::Snake() {
    corpo.push_back("~~O");
    tamanho = 1;
}

void Snake::mover() {
    // TODO: Lógica para mover a cobra
}

void Snake::comer() {
    corpo.insert(corpo.begin(), "~");
    ++tamanho;
}

void Snake::exibir() {
    for (const auto& segmento : corpo) {
        std::cout << segmento;
    }
    std::cout << std::endl;
}
