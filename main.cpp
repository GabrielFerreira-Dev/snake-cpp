#include <conio.h>
#include <iostream>
#include "snake.h"
#include "food.h"
#include "common.h"

using namespace std;
int largura = 75, altura = 25, pos_x_obstaculo, pos_y_obstaculo;
char dificuldade;
int velocidade;

// Snake snake({static_cast<SHORT>(largura / 2 - 20), static_cast<SHORT>(altura / 2)}, 1);

Snake snake;
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
            velocidade = 0;
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
            velocidade = 70;
        }
        else
        {
            system("cls");
            cout << "Valor inválido. Digite novamente.\n";
        }
    }
    snake.criarCobra(velocidade);
}

void renderCampo(){
    system("cls");
    for(int x = 0; x <= largura; x++){
        Common::goToxy(x, 0);
        cout << static_cast<CHAR>(219);
        //cout << '#';

        Common::goToxy(x, altura);
        cout << static_cast<CHAR>(219);
        //cout << '#';
    }

    for(int y = 0; y <= altura; ++y){
        Common::goToxy(0, y);
        cout << static_cast<CHAR>(219);
        //cout << '#';

        Common::goToxy(largura, y);
        cout << static_cast<CHAR>(219);
        //cout << '#';
    }
}

void renderFood(){
    COORD comidaPos = comida.getPos();

    Common::goToxy(comidaPos.X, comidaPos.Y);
    cout << '+';
    
}

void renderSnake(){
    vector<COORD> snakePos = snake.getPos();
    int snakeSize = snake.getTamanho();

    Common::goToxy(snakePos[0].X, snakePos[0].Y);
    cout << 'O';

    if(snakeSize > 1){
        Common::goToxy(snakePos[1].X, snakePos[1].Y);
        cout << '#';
    }
}

void renderPontuacao(int pontos){
    Common::goToxy(2, altura + 2);
    cout << "Pontos: ";
    cout << pontos;
}

bool detectCollision(){
    vector <COORD> snakePos = snake.getPos();

    if(snakePos.at(0).X == 0 || snakePos.at(0).X == largura) return true;
    if(snakePos.at(0).Y == 0 || snakePos.at(0).Y == altura) return true;
    for(int i = 1; i < snakePos.size(); ++i){
        if(snakePos.at(0).X == snakePos.at(i).X && snakePos.at(0).Y == snakePos.at(i).Y) return true;
    }

    return false;
}

void playGame(){
    int pontos = 0;
    alterarDificuldade();
    renderCampo();
    Common::goToxy(22, altura + 2);
    cout << "Devs: Gabriel Ferreira \\ Guilherme Henrique \\ Luan Pozzobon";
    while (!detectCollision())
    {
        renderPontuacao(pontos);
        renderFood();
        renderSnake();
        
        
        if (kbhit())
        {
            switch (tolower(getch()))
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
        
        if (snake.comer(comida.getPos()))
        {
            comida.gerarComida(largura);
            snake.crescer();

            if(dificuldade == 'f'){
                pontos += 5;
            } else{
                pontos += 10;
            }

        }

        Sleep(150 - snake.getVelocidade()); // Função para teste! Alterar depois!
        snake.moverCobra();
             
    }
    system("cls");
    cout << "GAME OVER!";
}

void showHighscores(){

}

int main()
{
    int opcao;
    cout << "Bem vindo ao Snake em C++. Escolha sua dificuldade para iniciar e bom jogo!" << endl;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Iniciar novo jogo" << endl;
        // cout << "2. Alterar dificuldade" << endl;
        cout << "2. HighScores" << endl;
        cout << "3. Sair do jogo" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            playGame();
            break;
        case 2:
            showHighscores();
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
