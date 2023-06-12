#ifndef FOOD_H
#define FOOD_H
#include <Windows.h>
#include <cstdlib>


class Food {
    private:
    COORD pos;

    public:
        Food();
        void gerarComida();
        COORD getPos();
};

#endif