#ifndef JOGO_H
#define JOGO_H

#include <string>
#include "snake.h"

class Jogo {
private:
    int largura;
    int altura;
    Snake cobra;

public:
    Jogo();

    void criarCampo(const std::string& dificuldade);
};

#endif
