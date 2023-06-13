#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <string>
#include <Windows.h>

class Snake
{
private:
    std::vector<COORD> pos;
    int tamanho;
    int velocidade;
    char direcao;

public:
    Snake();
    Snake(COORD pos, int velocidade);
    void mudarDirecao(char direcao);
    void unrenderSnake();
    void moverCobra();
    std::vector<COORD> getPos();
    int getTamanho();
    bool comer(COORD posicaoComida);
    void crescer();
};

#endif
