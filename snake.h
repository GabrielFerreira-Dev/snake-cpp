#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <string>

class Snake {
private:
    std::vector<std::string> corpo;
    int tamanho;

public:
    Snake();
    void mover();
    void comer();
    void exibir();
};

#endif
