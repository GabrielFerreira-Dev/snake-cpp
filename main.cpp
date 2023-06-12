#include <iostream>
#include <conio.h>
#include "snake.h"
#include "food.h"
#include <ctime>

using namespace std;
int largura = 75, altura = 25, pos_x_obstaculo, pos_y_obstaculo;
char dificuldade;

Snake snake({static_cast<SHORT>(largura / 2 - 20), static_cast<SHORT>(altura / 2)}, 1);
Food comida;

void alterarDificuldade()
{
    bool manter = true;
    while (manter)
    {
        cout << "Deseja jogar no:\n";
        cout << "1 - fácil\n";
        cout << "2 - difícil\n";
        char dif = getchar();
        if (dif == '1')
        {
            dificuldade = 'f';
            largura = 75;
            altura = 25;
            system("cls");
            manter = false;
        }
        else if (dif == '2')
        {
            dificuldade = 'd';
            largura = 80;
            altura = 25;
            pos_x_obstaculo = largura / 2;
            pos_y_obstaculo = altura / 2;
            system("cls");
            manter = false;
        }
        else
        {
            system("cls");
            cout << "Valor inválido. Digite novamente.\n";
        }
    }
}

void criarCampo()
{
    if (dificuldade != 'f' && dificuldade != 'd')
    {
        dificuldade = 'f';
        largura = 75;
        altura = 25;
    }

    COORD snakePos = snake.getPos();
    COORD comidaPos = comida.getPos();

    for (int i = 0; i < altura; i++)
    {
        cout << "#";
        for (int j = 0; j < largura - 2; j++)
        {
            if (i == 0 || i == altura - 1)
                cout << "#";
            else if (i == snakePos.Y && j == snakePos.X)
                cout << 'O';
            else if (i == comidaPos.Y && j == comidaPos.X)
                cout << '+';
            else
                cout << ' ';
        }
        cout << "#\n";
    }
}

int main()
{
    int opcao;
    std::cout << "Bem vindo ao Snake em C++. Escolha sua dificuldade para iniciar e bom jogo!" << std::endl;

    do
    {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Iniciar novo jogo" << std::endl;
        std::cout << "2. Alterar dificuldade" << std::endl;
        std::cout << "3. Sair do jogo" << std::endl;
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
            srand(time(NULL));
            while (true)
            {
                criarCampo();
                if (kbhit())
                {
                    switch (getch())
                    {
                    case 'w':
                        snake.mudarDirecao('c');
                        break;
                    case 'a':
                        snake.mudarDirecao('e');
                        break;
                    case 's':
                        snake.mudarDirecao('b');
                        break;
                    case 'd':
                        snake.mudarDirecao('d');
                        break;
                    }
                }
                snake.moverCobra();
                if (snake.comer(comida.getPos()))
                {
                    comida.gerarComida();
                    snake.crescer();
                }

                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
            }

            break;
        case 2:
            alterarDificuldade();
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
