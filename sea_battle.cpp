#include <iostream>

using namespace std;
enum ships
{
    ONE = '1',
    TWO = '2',
    THREE = '3',
    FOUR = '4'
};

enum sides
{
    RIGHT = 1,
    DOWN
};

static char ships4_1[12][12], ships3_1_1[12][12], ships3_2_1[12][12], ships2_1_1[12][12], ships2_2_1[12][12], ships2_3_1[12][12], ships1_1_1[12][12], ships1_2_1[12][12], ships1_3_1[12][12], ships1_4_1[12][12], ships4_2[12][12], ships3_1_2[12][12], ships3_2_2[12][12], ships2_1_2[12][12], ships2_2_2[12][12], ships2_3_2[12][12], ships1_1_2[12][12], ships1_2_2[12][12], ships1_3_2[12][12], ships1_4_2[12][12];

static char firstPlayer[12][12], secondPlayer[12][12];
static char attackField_1[12][12], attackField_2[12][12];

#include "ShowAndSet.h"
#include "Attack.h"

int main()
{

    srand(time(NULL));
    setlocale(LC_ALL, "rus");

    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            ::attackField_1[i][j] = '?';
            ::attackField_2[i][j] = '?';
        }
    }

    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            ships4_1[i][j] = '0';
            ships3_1_1[i][j] = '0';
            ships3_2_1[i][j] = '0';
            ships2_1_1[i][j] = '0';
            ships2_2_1[i][j] = '0';
            ships2_3_1[i][j] = '0';
            ships1_1_1[i][j] = '0';
            ships1_2_1[i][j] = '0';
            ships1_3_1[i][j] = '0';
            ships1_4_1[i][j] = '0';
            ships4_2[i][j] = '0';
            ships3_1_2[i][j] = '0';
            ships3_2_2[i][j] = '0';
            ships2_1_2[i][j] = '0';
            ships2_2_2[i][j] = '0';
            ships2_3_2[i][j] = '0';
            ships1_1_2[i][j] = '0';
            ships1_2_2[i][j] = '0';
            ships1_3_2[i][j] = '0';
            ships1_4_2[i][j] = '0';
        }
    }

    bool choice1, choice2 = 0; // Выбор режима игры два раза (с ботом или человек vs человек)

    cout << "Введите, кто сейчас будет расставлять корабли (бот - 0 или человек - 1)";
    cin >> choice1;
    
    bool question = 0;
    if (choice1 == 1)
    {
        cout << "Сам будешь расставлять или что? (0 - да, 1 - нет)"; cin >> question;
        if (question == 0)
            choice1 = 1;
        else
            choice1 = 0;
    }

    bool playerShips = false;
    if ((question == 1) && (choice1 == 0))
    {
        while (true) 
        {
            Set(choice1, ::firstPlayer, ::attackField_1, playerShips);
            Show(::firstPlayer, ::attackField_1);
            cout << endl;
            bool question2;
            cout << "Вам нравится расстановка? (0 - да, 1 - нет) "; cin >> question2;
            if (question2 == 0)
            {
                choice1 = 0; //////
                break;
            }
            else 
            {
                for (int i = 0; i < 12; ++i)
                {
                    for (int j = 0; j < 12; ++j)
                    {
                        ships4_1[i][j] = '0';
                        ships3_1_1[i][j] = '0';
                        ships3_2_1[i][j] = '0';
                        ships2_1_1[i][j] = '0';
                        ships2_2_1[i][j] = '0';
                        ships2_3_1[i][j] = '0';
                        ships1_1_1[i][j] = '0';
                        ships1_2_1[i][j] = '0';
                        ships1_3_1[i][j] = '0';
                        ships1_4_1[i][j] = '0';
                    }
                }
            }
        }
    }

    else
    {
        Set(choice1, ::firstPlayer, ::attackField_1, playerShips);
        Show(::firstPlayer, ::attackField_1);
    }

    playerShips = true;

    

    Set(choice2, ::secondPlayer, ::attackField_2, playerShips);
    Show(::secondPlayer, ::attackField_2);

    cout << endl << endl;

    for (int i = 2;; ++i)
    {

        if (i % 2 == 0)
        {
            playerShips = false;

            if (Attack(choice1, ::secondPlayer, ::attackField_1, playerShips) == 0)
            {
                break;
            }
        }
        else
        {
            playerShips = true;

            if (Attack(choice2, ::firstPlayer, ::attackField_2, playerShips) == 0)
            {
                break;
            }

        }
    }
    cout << endl << endl;
    cout << "\tПоле первого игрока\n";
    Show(::firstPlayer, ::attackField_1);
    cout << endl;
    cout << "\tПоле второго игрока\n";
    Show(::secondPlayer, ::attackField_2);
}
