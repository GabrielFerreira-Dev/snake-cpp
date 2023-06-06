#include <iostream>
#include "jogo.h"

int main() {
    Jogo jogo;
    int opcao;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Iniciar novo jogo" << std::endl;
        std::cout << "2. Alterar dificuldade" << std::endl;
        std::cout << "3. Sair do jogo" << std::endl;
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                jogo.criarCampo("facil");
                
                break;
            case 2:
                
                break;
            case 3:
              
              
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (opcao != 3);

    return 0;
}
