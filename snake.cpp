#include "snake.h"
#include "common.h"

Snake::Snake() {}

Snake::Snake(COORD pos, int velocidade)
{
    this->pos.push_back(pos);
    this->velocidade = velocidade;
    tamanho = 1;
    direcao = 'd';
}

void Snake::criarCobra(int velocidade){
    this->pos.clear();
    this->pos.push_back({12, 17});
    this->velocidade = velocidade;
    tamanho = 1;
    direcao = 'd';
}

void Snake::mudarDirecao(char direcao)
{
    if(this->direcao == 'c' && direcao == 'b') return;
    if(this->direcao == 'b' && direcao == 'c') return;
    if(this->direcao == 'd' && direcao == 'e') return;
    if(this->direcao == 'e' && direcao == 'd') return;
    this->direcao = direcao;
}

void Snake::unrenderSnake(){
    Common::goToxy(pos.at(0).X, pos.at(0).Y);
    std::cout << ' ';

    Common::goToxy(pos.at(tamanho - 1).X, pos.at(tamanho - 1).Y);
    std::cout << ' ';

/*
    for(COORD pos : this->pos){
        Common::goToxy(pos.X, pos.Y);
        std::cout << ' ';
    }
*/
}

void Snake::moverCobra()
{
    unrenderSnake();
    for(int i = tamanho - 1; i > 0; --i){
        pos.at(i) = pos.at(i - 1);
    }
    switch (direcao)
    {
    case 'c':
        pos.at(0).Y--;
        break;
    case 'b':
        pos.at(0).Y++;
        break;
    case 'd':
        pos.at(0).X++;
        break;
    case 'e':
        pos.at(0).X--;
        break;
    default:
        break;
    }
}

std::vector<COORD> Snake::getPos() {
    return pos;
}

int Snake::getTamanho(){
    return tamanho;
}

int Snake::getVelocidade(){
    return velocidade;
}

bool Snake::comer(COORD posicaoComida) {
    if(posicaoComida.X == pos.at(0).X && posicaoComida.Y == pos.at(0).Y) return true;
    else return false;
}

void Snake::crescer() {   
    pos.push_back(pos.at(tamanho - 1));

    switch(direcao){
        case 'c':
            pos.at(tamanho).Y++;
            break;
        case 'b':
            pos.at(tamanho).Y--;
            break;
        case 'e':
            pos.at(tamanho).X++;
            break;
        case 'd':
            pos.at(tamanho).X--;
            break;
    }
    tamanho++;
}
