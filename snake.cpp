#include "snake.h"
#include <iostream>

Snake::Snake() {}

Snake::Snake(COORD pos, int velocidade)
{
    this->pos = pos;
    this->velocidade = velocidade;
    tamanho = 1;
    direcao = 'n';
}

void Snake::mudarDirecao(char direcao)
{
    this->direcao = direcao;
}

void Snake::moverCobra()
{
    switch (direcao)
    {
    case 'c':
        pos.Y -= velocidade;
        break;
    case 'b':
        pos.Y += velocidade;
        break;
    case 'd':
        pos.X += velocidade;
        break;
    case 'e':
        pos.X -= velocidade;
        break;
    default:
        break;
    }
}

COORD Snake::getPos() {
    return pos;
}

bool Snake::comer(COORD posicaoComida) {
    if(posicaoComida.X == pos.X && posicaoComida.Y == pos.Y) return true;
    else return false;
}

void Snake::crescer() { tamanho++; }