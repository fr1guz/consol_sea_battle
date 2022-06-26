#include <iostream>

using namespace std;

#ifndef ATTACK_H
#define ATTACK_H

int Attack(bool choice, char playersField[12][12], char attackField[12][12], bool playerShips)
{
    int vertical, horizontal;
    for (int kok = 0;; kok++)
    {
        if ((playerShips == 0) && (choice == 1))
        {
            cout << "\t ИГРОК ПЕРВЫЙ\n";
            Show(::firstPlayer, ::attackField_1);
        }
        else if ((playerShips == 1) && (choice == 1))
        {
            cout << "\t ИГРОК ВТОРОЙ\n";
            Show(::secondPlayer, ::attackField_2);
        }
        for (int m = 0;; ++m)
        {
            if (choice == 1)
            {

                cout << "\nВведите координаты клетки, по которой будете бить\n";

                for (int i = 0;; ++i)
                {
                    cin >> vertical >> horizontal;

                    if ((vertical < 1) || (vertical > 10) || (horizontal < 1) || (horizontal > 10))
                    {
                        cout << "\nКакие-то координаты введены неверно, повторите ввод\n";
                        --m;
                    }
                    else break;
                }

            }
            else if (choice == 0)
            {
                vertical = rand() % 10 + 1;
                horizontal = rand() % 10 + 1;
            }

            if ((attackField[vertical][horizontal] == 'X') || (attackField[vertical][horizontal] == '0') || (attackField[vertical][horizontal] == '/'))
            {
                if (choice == 1)
                {
                    cout << "Вы уже туда стреляли";
                }
                --m;
            }
            else break;
        }

        if ((playersField[vertical][horizontal] == '0') || (playersField[vertical][horizontal] == '/'))
        {
            if (choice == 1)
            {
                cout << "\nВы не попали\n";
            }
            attackField[vertical][horizontal] = '0';
            break;
        }

        else if (playersField[vertical][horizontal] == ONE)
        {
            if (choice == 1) { cout << "\nКорабль уничтожен!\n"; }
            attackField[vertical][horizontal] = 'X';
            playersField[vertical][horizontal] = 'X';

            if (playerShips == 0)
            {
                if (::ships1_1_2[vertical][horizontal] == ONE) { ::ships1_1_2[vertical][horizontal] = 'X'; }
                if (::ships1_2_2[vertical][horizontal] == ONE) { ::ships1_2_2[vertical][horizontal] = 'X'; }
                if (::ships1_3_2[vertical][horizontal] == ONE) { ::ships1_3_2[vertical][horizontal] = 'X'; }
                if (::ships1_4_2[vertical][horizontal] == ONE) { ::ships1_4_2[vertical][horizontal] = 'X'; }
            }

            if (playerShips == 1)
            {
                if (::ships1_1_1[vertical][horizontal] == ONE) { ::ships1_1_1[vertical][horizontal] = 'X'; }
                if (::ships1_2_1[vertical][horizontal] == ONE) { ::ships1_2_1[vertical][horizontal] = 'X'; }
                if (::ships1_3_1[vertical][horizontal] == ONE) { ::ships1_3_1[vertical][horizontal] = 'X'; }
                if (::ships1_4_1[vertical][horizontal] == ONE) { ::ships1_4_1[vertical][horizontal] = 'X'; }
            }

            int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
            for (int i = 1; i < 11; ++i)
            {
                for (int j = 1; j < 11; ++j)
                {
                    if (playerShips == 0)
                    {
                        if (::ships1_1_2[vertical][horizontal] == 'X') { ++count1; }
                        if (::ships1_2_2[vertical][horizontal] == 'X') { ++count2; }
                        if (::ships1_3_2[vertical][horizontal] == 'X') { ++count3; }
                        if (::ships1_4_2[vertical][horizontal] == 'X') { ++count4; }
                    }

                    if (playerShips == 1)
                    {
                        if (::ships1_1_1[vertical][horizontal] == 'X') { ++count1; }
                        if (::ships1_2_1[vertical][horizontal] == 'X') { ++count2; }
                        if (::ships1_3_1[vertical][horizontal] == 'X') { ++count3; }
                        if (::ships1_4_1[vertical][horizontal] == 'X') { ++count4; }
                    }
                }
            }
            if (count1 > 0)
            {
                for (int i = 1; i < 11; ++i)
                {
                    for (int j = 1; j < 11; ++j)
                    {
                        if (playerShips == 0)
                        {
                            if (::ships1_1_2[i][j] == '/') { attackField[i][j] = '/'; }
                        }

                        if (playerShips == 1)
                        {
                            if (::ships1_1_1[i][j] == '/') { attackField[i][j] = '/'; }
                        }
                    }
                }
            }
            if (count2 > 0)
            {
                for (int i = 1; i < 11; ++i)
                {
                    for (int j = 1; j < 11; ++j)
                    {
                        if (playerShips == 0)
                        {
                            if (::ships1_2_2[i][j] == '/') { attackField[i][j] = '/'; }
                        }

                        if (playerShips == 1)
                        {
                            if (::ships1_2_1[i][j] == '/') { attackField[i][j] = '/'; }
                        }
                    }
                }
            }
            if (count3 > 0)
            {
                for (int i = 1; i < 11; ++i)
                {
                    for (int j = 1; j < 11; ++j)
                    {
                        if (playerShips == 0)
                        {
                            if (::ships1_3_2[i][j] == '/') { attackField[i][j] = '/'; }
                        }

                        if (playerShips == 1)
                        {
                            if (::ships1_3_1[i][j] == '/') { attackField[i][j] = '/'; }
                        }
                    }
                }
            }
            if (count4 > 0)
            {
                for (int i = 1; i < 11; ++i)
                {
                    for (int j = 1; j < 11; ++j)
                    {
                        if (playerShips == 0)
                        {
                            if (::ships1_4_2[i][j] == '/') { attackField[i][j] = '/'; }
                        }

                        if (playerShips == 1)
                        {
                            if (::ships1_4_1[i][j] == '/') { attackField[i][j] = '/'; }
                        }
                    }
                }
            }
        }
        else if (playersField[vertical][horizontal] == TWO)
        {
            if (choice == 1) { cout << "\nПопадание!\n"; }
            attackField[vertical][horizontal] = 'X';
            playersField[vertical][horizontal] = 'X';

            if (playerShips == 0)
            {
                if (::ships2_1_2[vertical][horizontal] == TWO) { ::ships2_1_2[vertical][horizontal] = 'X'; }
                if (::ships2_2_2[vertical][horizontal] == TWO) { ::ships2_2_2[vertical][horizontal] = 'X'; }
                if (::ships2_3_2[vertical][horizontal] == TWO) { ::ships2_3_2[vertical][horizontal] = 'X'; }
            }

            if (playerShips == 1)
            {
                if (::ships2_1_1[vertical][horizontal] == TWO) { ::ships2_1_1[vertical][horizontal] = 'X'; }
                if (::ships2_2_1[vertical][horizontal] == TWO) { ::ships2_2_1[vertical][horizontal] = 'X'; }
                if (::ships2_3_1[vertical][horizontal] == TWO) { ::ships2_3_1[vertical][horizontal] = 'X'; }
            }
            int count1 = 0, count2 = 0, count3 = 0;
            for (int i = 1; i < 11; ++i)
            {
                for (int j = 1; j < 11; ++j)
                {
                    if (playerShips == 1)
                    {
                        if (::ships2_1_1[i][j] == 'X') { count1++; }
                        if (::ships2_2_1[i][j] == 'X') { count2++; }
                        if (::ships2_3_1[i][j] == 'X') { count3++; }
                    }

                    if (playerShips == 0)
                    {
                        if (::ships2_1_2[i][j] == 'X') { count1++; }
                        if (::ships2_2_2[i][j] == 'X') { count2++; }
                        if (::ships2_3_2[i][j] == 'X') { count3++; }
                    }
                }
            }
            if (count1 == 2)
            {
                if (choice == 1) { cout << "\nКорабль уничтожен!\n"; }
                if (playerShips == 1)
                {
                    for (int i = 1; i < 11; ++i)
                    {
                        for (int j = 1; j < 11; ++j)
                        {
                            if (::ships2_1_1[i][j] == '/') { attackField[i][j] = '/'; }
                        }
                    }
                }
                else
                {
                    for (int i = 1; i < 11; ++i)
                    {
                        for (int j = 1; j < 11; ++j)
                        {
                            if (::ships2_1_2[i][j] == '/') { attackField[i][j] = '/'; }
                        }
                    }
                }
            }

            if (count2 == 2)
            {
                if (choice == 1) { cout << "\nКорабль уничтожен!\n"; }
                if (playerShips == 1)
                {
                    for (int i = 1; i < 11; ++i)
                    {
                        for (int j = 1; j < 11; ++j)
                        {
                            if (::ships2_2_1[i][j] == '/') { attackField[i][j] = '/'; }
                        }
                    }
                }
                else
                {
                    for (int i = 1; i < 11; ++i)
                    {
                        for (int j = 1; j < 11; ++j)
                        {
                            if (::ships2_2_2[i][j] == '/') { attackField[i][j] = '/'; }
                        }
                    }
                }
            }
            if (count3 == 2)
            {
                if (choice == 1) { cout << "\nКорабль уничтожен!\n"; }
                if (playerShips == 1)
                {
                    for (int i = 1; i < 11; ++i)
                    {
                        for (int j = 1; j < 11; ++j)
                        {
                            if (::ships2_3_1[i][j] == '/') { attackField[i][j] = '/'; }
                        }
                    }
                }
                else
                {
                    for (int i = 1; i < 11; ++i)
                    {
                        for (int j = 1; j < 11; ++j)
                        {
                            if (::ships2_3_2[i][j] == '/') { attackField[i][j] = '/'; }
                        }
                    }
                }
            }
        }
        else if (playersField[vertical][horizontal] == THREE)
        {
            if (choice == 1) { cout << "\nПопадание!\n"; }

            attackField[vertical][horizontal] = 'X';
            playersField[vertical][horizontal] = 'X';
            if (playerShips == 0)
            {
                if (::ships3_1_2[vertical][horizontal] == THREE) { ::ships3_1_2[vertical][horizontal] = 'X'; }
                if (::ships3_2_2[vertical][horizontal] == THREE) { ::ships3_2_2[vertical][horizontal] = 'X'; }
            }

            if (playerShips == 1)
            {
                if (::ships3_1_1[vertical][horizontal] == THREE) { ::ships3_1_1[vertical][horizontal] = 'X'; }
                if (::ships3_2_1[vertical][horizontal] == THREE) { ::ships3_2_1[vertical][horizontal] = 'X'; }
            }

            int count1 = 0, count2 = 0;
            for (int i = 1; i < 11; ++i)
            {
                for (int j = 1; j < 11; ++j)
                {
                    if (playerShips == 1)
                    {
                        if (::ships3_1_1[i][j] == 'X') { count1++; }
                        if (::ships3_2_1[i][j] == 'X') { count2++; }
                    }

                    if (playerShips == 0)
                    {
                        if (::ships3_1_2[i][j] == 'X') { count1++; }
                        if (::ships3_2_2[i][j] == 'X') { count2++; }
                    }
                }
            }
            if (count1 == 3)
            {
                if (choice == 1) { cout << "\nКорабль уничтожен!\n"; }
                if (playerShips == 1)
                {
                    for (int i = 1; i < 11; ++i)
                    {
                        for (int j = 1; j < 11; ++j)
                        {
                            if (::ships3_1_1[i][j] == '/') { attackField[i][j] = '/'; }
                        }
                    }
                }
                else
                {
                    for (int i = 1; i < 11; ++i)
                    {
                        for (int j = 1; j < 11; ++j)
                        {
                            if (::ships3_1_2[i][j] == '/') { attackField[i][j] = '/'; }
                        }
                    }
                }
            }

            if (count2 == 3)
            {
                if (choice == 1) { cout << "\nКорабль уничтожен!\n"; }
                if (playerShips == 1)
                {
                    for (int i = 1; i < 11; ++i)
                    {
                        for (int j = 1; j < 11; ++j)
                        {
                            if (::ships3_2_1[i][j] == '/') { attackField[i][j] = '/'; }
                        }
                    }
                }
                else
                {
                    for (int i = 1; i < 11; ++i)
                    {
                        for (int j = 1; j < 11; ++j)
                        {
                            if (::ships3_2_2[i][j] == '/') { attackField[i][j] = '/'; }
                        }
                    }
                }
            }
        }
        else if (playersField[vertical][horizontal] == FOUR)
        {
            if (choice == 1) { cout << "\nПопадание!\n"; }

            attackField[vertical][horizontal] = 'X';
            playersField[vertical][horizontal] = 'X';
            if (playerShips == 0) { if (::ships4_2[vertical][horizontal] == FOUR) { ::ships4_2[vertical][horizontal] = 'X'; } }

            if (playerShips == 1) { if (::ships4_1[vertical][horizontal] == FOUR) { ::ships4_1[vertical][horizontal] = 'X'; } }

            int count1 = 0;
            for (int i = 1; i < 11; ++i)
            {
                for (int j = 1; j < 11; ++j)
                {
                    if (playerShips == 1)
                    {
                        if (::ships4_1[i][j] == 'X') { count1++; }
                    }

                    if (playerShips == 0)
                    {
                        if (::ships4_2[i][j] == 'X') { count1++; }
                    }
                }
            }
            if (count1 == 4)
            {
                if (choice == 1) { cout << "\nКорабль уничтожен!\n"; }
                if (playerShips == 1)
                {
                    for (int i = 1; i < 11; ++i)
                    {
                        for (int j = 1; j < 11; ++j)
                        {
                            if (::ships4_1[i][j] == '/') { attackField[i][j] = '/'; }
                        }
                    }
                }
                else
                {
                    for (int i = 1; i < 11; ++i)
                    {
                        for (int j = 1; j < 11; ++j)
                        {
                            if (::ships4_2[i][j] == '/') { attackField[i][j] = '/'; }
                        }
                    }
                }
            }
        }
        int countField1 = 0, countField2 = 0;

        for (int j = 1; j < 11; ++j)
        {
            for (int h = 1; h < 11; ++h)
            {
                if ((::firstPlayer[j][h] != '0') && (::firstPlayer[j][h] != 'X') && (::firstPlayer[j][h] != '/')) { countField1++; }
                if ((::secondPlayer[j][h] != '0') && (::secondPlayer[j][h] != 'X') && (::secondPlayer[j][h] != '/')) { countField2++; }
            }
        }
        if (countField1 == 0)
        {
            cout << "Второй игрок победил!";
            return 0;
            break;
        }
        if (countField2 == 0)
        {
            cout << "Первый игрок победил!";
            return 0;
            break;
        }
    }
    return 1;
}
#endif // !ATTACK_H
