#include "jogo.h"
#include <iostream>

Jogo::Jogo() {
    // Configuração inicial para dificuldade fácil
    largura = 40;
    altura = 40;
}

void Jogo::criarCampo(const std::string& dificuldade) {
    if (dificuldade == "dificil") {
        largura = 30;
        altura = 30;
    }

    std::vector<std::vector<char>> campo(altura, std::vector<char>(largura, ' '));

    for (int col = 0; col < largura; ++col) {
        campo[0][col] = '-';
        campo[altura - 1][col] = '-';
    }

    for (int row = 0; row < altura; ++row) {
        campo[row][0] = 'I';
        campo[row][largura - 1] = 'I';
    }

    for (int row = 0; row < altura; ++row) {
        for (int col = 0; col < largura; ++col) {
            if (row == 0 || row == altura - 1 || col == 0 || col == largura - 1) {
                std::cout << campo[row][col] << ' ';
            } else {
                if (row == 1 && col == 1) {
                    cobra.exibir();
                } else {
                    std::cout << campo[row][col] << ' ';
                }
            }
        }
        std::cout << std::endl;
    }
}
