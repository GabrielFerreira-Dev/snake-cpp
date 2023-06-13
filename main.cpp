#include <conio.h>
#include <iostream>
#include "snake.h"
#include "food.h"
#include "common.h"

using namespace std;
int largura = 75, altura = 25, pos_x_obstaculo, pos_y_obstaculo;
char dificuldade = 'f';

Snake snake({static_cast<SHORT>(largura / 2 - 20), static_cast<SHORT>(altura / 2)}, 1);
Food comida;

void goToxy(short x, short y) {
    COORD coords {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);
}

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

void renderCampo(){
    system("cls");
    for(int x = 0; x < largura; x += 2){
        Common::goToxy(x, 0);
        cout << '#';

        Common::goToxy(x, altura);
        cout << '#';
    }

    for(int y = 0; y < altura; ++y){
        Common::goToxy(0, y);
        cout << '#';

        Common::goToxy(largura, y);
        cout << '#';
    }
}

void renderFood(){
    COORD comidaPos = comida.getPos();

    Common::goToxy(comidaPos.X, comidaPos.Y);
    cout << '+';
    
}

void renderSnake(){
    vector<COORD> snakePos = snake.getPos();

    Common::goToxy(snakePos.at(0).X, snakePos.at(0).Y);
    cout << '0';

    if(snake.getTamanho() > 1){
        COORD pos;
        for (int i = 1; i < snake.getTamanho(); ++i){
            pos = snakePos.at(i);
            Common::goToxy(pos.X, pos.Y);
            cout << '~';
        }
    }
}

bool detectCollision(){
    vector <COORD> snakePos = snake.getPos();

    if(snakePos.at(0).X == 0 || snakePos.at(0).X == largura) return true;
    if(snakePos.at(0).Y == 0 || snakePos.at(0).Y == altura) return true;

    return false;
}

int main()
{
    int opcao;
    cout << "Bem vindo ao Snake em C++. Escolha sua dificuldade para iniciar e bom jogo!" << endl;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Iniciar novo jogo" << endl;
        cout << "2. Alterar dificuldade" << endl;
        cout << "3. Sair do jogo" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            
            renderCampo();
            renderFood();
            while (true)
            {
                renderSnake();
                Sleep(100); // Função para teste! Alterar depois!
                
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
                if(detectCollision()){
                    system("cls");
                    cout << "GAME OVER!";
                    while(getchar() != '\n');
                    exit(1);
                }
                if (snake.comer(comida.getPos()))
                {
                    comida.gerarComida();
                    snake.crescer();
                    renderFood();
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
            cout << "Opcao invalida. Tente novamente." << endl;
            break;
        }

        cout << endl;
    } while (opcao != 3);

    return 0;
}
