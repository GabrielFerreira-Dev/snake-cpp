#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <string>
#include <Windows.h>

class Snake
{
private:
    COORD pos;
    int tamanho;
    int velocidade;
    char direcao;

public:
    Snake();
    Snake(COORD pos, int velocidade);
    void mudarDirecao(char direcao);
    void moverCobra();
    COORD getPos();
    bool comer(COORD posicaoComida);
    void crescer();
};

#endif
