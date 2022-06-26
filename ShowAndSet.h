#include <iostream>

using namespace std;

#ifndef SHOWANDSET_H
#define SHOWANDSET_H

void Show(char player[12][12], char attackPlayer[12][12])
{
    cout << endl;
    cout << "    1 2 3 4 5 6 7 8 9 10  |  1 2 3 4 5 6 7 8 9 10\n";
    cout << "    --------------------  |  --------------------\n";

    for (int i = 1; i < 11; ++i)
    {
        if (i < 10) cout << i << " | ";
        else cout << i << "| ";
        for (int j = 1; j < 11; ++j)
        {
            cout << player[i][j] << ' ';
        }
        cout << "  |  ";
        for (int j = 1; j < 11; ++j)
        {
            cout << attackPlayer[i][j] << ' ';
        }

        cout << " |" << i;

        cout << endl;
    }
}

void Set(bool choice, char player[12][12], char attackField[12][12], bool playerShips)
{
    for (int i = 1; i < 11; ++i)
    {
        for (int j = 1; j < 11; ++j)
        {
            player[i][j] = '0';
        }
    }

    if (choice == 1) { cout << "\nСначала расставьте четырёхпалубный корабль (он 1)\n"; }

    for (int i = 0; i < 1; ++i)
    {
        if (choice == 1) { Show(player, attackField); }
        int vertical, horizontal, side;

        if (choice == 0)
        {
            vertical = rand() % 10 + 1;
            horizontal = rand() % 10 + 1;
            side = rand() % 2 + 1;
        }
        else
        {
            for (int j = 0;; ++j)
            {
                cout << "\nВведите сначала куда поставить корабль по вертикали, потом по горизонтали\n";
                cin >> vertical >> horizontal >> side;

                if ((vertical < 1) || (vertical > 10) || (horizontal < 1) || (horizontal > 10) || (side < 1) || (side > 2))
                {
                    cout << "\nКакие-то координаты или сторону Вы ввели неправильно, повторите попытку\n";
                }
                else break;
            }

        }

        if (side == RIGHT)
        {
            int countPlace = 0;
            for (int j = horizontal; j < (horizontal + 4); ++j)
            {
                if (player[vertical][j] != '0') { ++countPlace; }
            }
            if (countPlace != 0)
            {
                if (choice == 1) { cout << "\nКакая-то из клеток занята другим кораблём, или корабль выходит из поля\n"; }
                --i;
            }
            else
            {
                for (int j = horizontal; j < (horizontal + 4); ++j)
                {
                    player[vertical][j] = FOUR;
                    if (playerShips == 0) { ::ships4_1[vertical][j] = FOUR; }
                    else if (playerShips == 1) { ::ships4_2[vertical][j] = FOUR; }
                }
            }
        }

        else if (side == DOWN)
        {
            int countPlace = 0;
            for (int j = vertical; j < (vertical + 4); ++j)
            {
                if (player[j][horizontal] != '0')
                    ++countPlace;
            }
            if (countPlace != 0)
            {
                if (choice == 1) { cout << "\nКакая-то из клеток занята другим кораблём, или корабль выходит из поля\n"; }
                --i;
            }
            else
            {
                for (int j = vertical; j < (vertical + 4); ++j)
                {
                    player[j][horizontal] = FOUR;
                    if (playerShips == 0) { ::ships4_1[j][horizontal] = FOUR; }
                    else if (playerShips == 1) { ::ships4_2[j][horizontal] = FOUR; }
                }
            }
        }

        for (int l = 1; l < 11; ++l)
        {
            for (int j = 1; j < 11; ++j)
            {
                if ((player[l][j] == '0') || (player[l][j] == '/'))
                {
                    if ((player[l][j] == FOUR) || (player[l][j + 1] == FOUR) || (player[l + 1][j] == FOUR) || (player[l + 1][j + 1] == FOUR) || (player[l - 1][j] == FOUR) || (player[l][j - 1] == FOUR) || (player[l - 1][j - 1] == FOUR) || (player[l + 1][j - 1] == FOUR) || (player[l - 1][j + 1] == FOUR))
                    {
                        player[l][j] = '/';
                        if (playerShips == 0)
                        {
                            if ((::ships4_1[l][j] == FOUR) || (::ships4_1[l][j + 1] == FOUR) || (::ships4_1[l + 1][j] == FOUR) || (::ships4_1[l + 1][j + 1] == FOUR) || (::ships4_1[l - 1][j] == FOUR) || (::ships4_1[l][j - 1] == FOUR) || (::ships4_1[l - 1][j - 1] == FOUR) || (::ships4_1[l + 1][j - 1] == FOUR) || (::ships4_1[l - 1][j + 1] == FOUR))
                            {
                                ::ships4_1[l][j] = '/';
                            }
                        }
                        else
                        {
                            if ((::ships4_2[l][j] == FOUR) || (::ships4_2[l][j + 1] == FOUR) || (::ships4_2[l + 1][j] == FOUR) || (::ships4_2[l + 1][j + 1] == FOUR) || (::ships4_2[l - 1][j] == FOUR) || (::ships4_2[l][j - 1] == FOUR) || (::ships4_2[l - 1][j - 1] == FOUR) || (::ships4_2[l + 1][j - 1] == FOUR) || (::ships4_2[l - 1][j + 1] == FOUR))
                            {
                                ::ships4_2[l][j] = '/';
                            }
                        }
                    }
                }
            }
        }
    }

    if (choice == 1) { cout << "\nТеперь расставьте трёхпалубные корабли (их 2)\n"; }

    for (int i = 0; i < 2; ++i)
    {
        if (choice == 1) { Show(player, attackField); }
        int vertical, horizontal, side;

        if (choice == 0)
        {
            vertical = rand() % 10 + 1;
            horizontal = rand() % 10 + 1;
            side = rand() % 2 + 1;
        }
        else
        {
            for (int j = 0;; ++j)
            {
                cout << "\nВведите сначала куда поставить корабль по вертикали, потом по горизонтали\n";
                cin >> vertical >> horizontal >> side;

                if ((vertical < 1) || (vertical > 10) || (horizontal < 1) || (horizontal > 10) || (side < 1) || (side > 2))
                {
                    cout << "\nКакие-то координаты или сторону Вы ввели неправильно, повторите попытку\n";
                }
                else break;
            }
        }

        if (side == RIGHT)
        {
            int countPlace = 0;
            for (int j = horizontal; j < (horizontal + 3); ++j)
            {
                if (player[vertical][j] != '0') { ++countPlace; }
            }
            if (countPlace != 0)
            {
                if (choice == 1) { cout << "\nКакая-то из клеток занята другим кораблём\n"; }
                --i;
            }
            else
            {
                for (int j = horizontal; j < (horizontal + 3); ++j)
                {
                    player[vertical][j] = THREE;
                    if (i == 0)
                    {

                        if (playerShips == 0)
                        {
                            ::ships3_1_1[vertical][j] = THREE;
                        }
                        else if (playerShips == 1)
                        {
                            ::ships3_1_2[vertical][j] = THREE;
                        }
                    }
                    if (i == 1)
                    {
                        if (playerShips == 0)
                        {
                            ::ships3_2_1[vertical][j] = THREE;
                        }
                        if (playerShips == 1)
                        {
                            ::ships3_2_2[vertical][j] = THREE;
                        }
                    }
                }
            }
        }
        else if (side == DOWN)
        {
            int countPlace = 0;
            for (int j = vertical; j < (vertical + 3); ++j)
            {
                if (player[j][horizontal] != '0') { ++countPlace; }
            }
            if (countPlace != 0)
            {
                if (choice == 1) { cout << "\nКакая-то из клеток занята другим кораблём\n"; }
                --i;
            }
            else
            {
                for (int j = vertical; j < (vertical + 3); ++j)
                {
                    player[j][horizontal] = THREE;
                    if (i == 0)
                    {

                        if (playerShips == 0)
                        {
                            ::ships3_1_1[j][horizontal] = THREE;
                        }
                        else if (playerShips == 1)
                        {
                            ::ships3_1_2[j][horizontal] = THREE;
                        }
                    }
                    if (i == 1)
                    {
                        if (playerShips == 0)
                        {
                            ::ships3_2_1[j][horizontal] = THREE;
                        }
                        if (playerShips == 1)
                        {
                            ::ships3_2_2[j][horizontal] = THREE;
                        }
                    }
                }
            }
        }

        for (int l = 1; l < 11; ++l)
        {
            for (int j = 1; j < 11; ++j)
            {
                if ((player[l][j] == '0') || (player[l][j] == '/'))
                {
                    if ((player[l][j] == THREE) || (player[l][j + 1] == THREE) || (player[l + 1][j] == THREE) || (player[l + 1][j + 1] == THREE) || (player[l - 1][j] == THREE) || (player[l][j - 1] == THREE) || (player[l - 1][j - 1] == THREE) || (player[l + 1][j - 1] == THREE) || (player[l - 1][j + 1] == THREE))
                    {
                        player[l][j] = '/';
                        if (i == 0)
                        {
                            if (playerShips == 0)
                            {
                                if ((::ships3_1_1[l][j] == THREE) || (::ships3_1_1[l][j + 1] == THREE) || (::ships3_1_1[l + 1][j] == THREE) || (::ships3_1_1[l + 1][j + 1] == THREE) || (::ships3_1_1[l - 1][j] == THREE) || (::ships3_1_1[l][j - 1] == THREE) || (::ships3_1_1[l - 1][j - 1] == THREE) || (::ships3_1_1[l + 1][j - 1] == THREE) || (::ships3_1_1[l - 1][j + 1] == THREE))
                                {
                                    ::ships3_1_1[l][j] = '/';
                                }
                            }
                            else
                            {
                                if ((::ships3_1_2[l][j] == THREE) || (::ships3_1_2[l][j + 1] == THREE) || (::ships3_1_2[l + 1][j] == THREE) || (::ships3_1_2[l + 1][j + 1] == THREE) || (::ships3_1_2[l - 1][j] == THREE) || (::ships3_1_2[l][j - 1] == THREE) || (::ships3_1_2[l - 1][j - 1] == THREE) || (::ships3_1_2[l + 1][j - 1] == THREE) || (::ships3_1_2[l - 1][j + 1] == THREE))
                                {
                                    ::ships3_1_2[l][j] = '/';
                                }
                            }
                        }
                        if (i == 1)
                        {
                            if (playerShips == 0)
                            {
                                if ((::ships3_2_1[l][j] == THREE) || (::ships3_2_1[l][j + 1] == THREE) || (::ships3_2_1[l + 1][j] == THREE) || (::ships3_2_1[l + 1][j + 1] == THREE) || (::ships3_2_1[l - 1][j] == THREE) || (::ships3_2_1[l][j - 1] == THREE) || (::ships3_2_1[l - 1][j - 1] == THREE) || (::ships3_2_1[l + 1][j - 1] == THREE) || (::ships3_2_1[l - 1][j + 1] == THREE))
                                {
                                    ::ships3_2_1[l][j] = '/';
                                }
                            }
                            else
                            {
                                if ((::ships3_2_2[l][j] == THREE) || (::ships3_2_2[l][j + 1] == THREE) || (::ships3_2_2[l + 1][j] == THREE) || (::ships3_2_2[l + 1][j + 1] == THREE) || (::ships3_2_2[l - 1][j] == THREE) || (::ships3_2_2[l][j - 1] == THREE) || (::ships3_2_2[l - 1][j - 1] == THREE) || (::ships3_2_2[l + 1][j - 1] == THREE) || (::ships3_2_2[l - 1][j + 1] == THREE))
                                {
                                    ::ships3_2_2[l][j] = '/';
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (choice == 1) { cout << "\nТеперь расставьте двухпалубные корабли (их 3)\n"; }

    for (int i = 0; i < 3; ++i)
    {
        if (choice == 1) { Show(player, attackField); }
        int vertical, horizontal, side;

        if (choice == 0)
        {
            vertical = rand() % 10 + 1;
            horizontal = rand() % 10 + 1;
            side = rand() % 2 + 1;
        }
        else
        {
            for (int j = 0;; ++j)
            {
                cout << "\nВведите сначала куда поставить корабль по вертикали, потом по горизонтали\n";
                cin >> vertical >> horizontal >> side;

                if ((vertical < 1) || (vertical > 10) || (horizontal < 1) || (horizontal > 10) || (side < 1) || (side > 2))
                {
                    cout << "\nКакие-то координаты или сторону Вы ввели неправильно, повторите попытку\n";
                }
                else break;
            }
        }

        if (side == RIGHT)
        {
            int countPlace = 0;
            for (int j = horizontal; j < (horizontal + 2); ++j)
            {
                if (player[vertical][j] != '0') { ++countPlace; }
            }
            if (countPlace != 0)
            {
                if (choice == 1) { cout << "\nКакая-то из клеток занята другим кораблём\n"; }
                --i;
            }
            else
            {
                for (int j = horizontal; j < (horizontal + 2); ++j)
                {
                    player[vertical][j] = TWO;
                    if (i == 0)
                    {
                        if (playerShips == 0) { ::ships2_1_1[vertical][j] = TWO; }
                        else if (playerShips == 1) { ::ships2_1_2[vertical][j] = TWO; }
                    }
                    if (i == 1)
                    {
                        if (playerShips == 0) { ::ships2_2_1[vertical][j] = TWO; }
                        else if (playerShips == 1) { ::ships2_2_2[vertical][j] = TWO; }
                    }
                    if (i == 2)
                    {
                        if (playerShips == 0) { ::ships2_3_1[vertical][j] = TWO; }
                        else if (playerShips == 1) { ::ships2_3_2[vertical][j] = TWO; }
                    }
                }
            }
        }

        else if (side == DOWN)
        {
            int countPlace = 0;
            for (int j = vertical; j < (vertical + 2); ++j)
            {
                if (player[j][horizontal] != '0') { ++countPlace; }
            }
            if (countPlace != 0)
            {
                if (choice == 1) { cout << "\nКакая-то из клеток занята другим кораблём\n"; }
                --i;
            }
            else
            {
                for (int j = vertical; j < (vertical + 2); ++j)
                {
                    player[j][horizontal] = TWO;
                    if (i == 0)
                    {
                        if (playerShips == 0) { ::ships2_1_1[j][horizontal] = TWO; }
                        else if (playerShips == 1) { ::ships2_1_2[j][horizontal] = TWO; }
                    }
                    if (i == 1)
                    {
                        if (playerShips == 0) { ::ships2_2_1[j][horizontal] = TWO; }
                        else if (playerShips == 1) { ::ships2_2_2[j][horizontal] = TWO; }
                    }
                    if (i == 2)
                    {
                        if (playerShips == 0) { ::ships2_3_1[j][horizontal] = TWO; }
                        else if (playerShips == 1) { ::ships2_3_2[j][horizontal] = TWO; }
                    }
                }
            }
        }
        for (int l = 1; l < 11; ++l)
        {
            for (int j = 1; j < 11; ++j)
            {
                if ((player[l][j] == '0') || (player[l][j] == '/'))
                {
                    if ((player[l][j] == TWO) || (player[l][j + 1] == TWO) || (player[l + 1][j] == TWO) || (player[l + 1][j + 1] == TWO) || (player[l - 1][j] == TWO) || (player[l][j - 1] == TWO) || (player[l - 1][j - 1] == TWO) || (player[l + 1][j - 1] == TWO) || (player[l - 1][j + 1] == TWO))
                    {
                        player[l][j] = '/';
                        if (i == 0)
                        {
                            if (playerShips == 0)
                            {
                                if ((::ships2_1_1[l][j] == TWO) || (::ships2_1_1[l][j + 1] == TWO) || (::ships2_1_1[l + 1][j] == TWO) || (::ships2_1_1[l + 1][j + 1] == TWO) || (::ships2_1_1[l - 1][j] == TWO) || (::ships2_1_1[l][j - 1] == TWO) || (::ships2_1_1[l - 1][j - 1] == TWO) || (::ships2_1_1[l + 1][j - 1] == TWO) || (::ships2_1_1[l - 1][j + 1] == TWO))
                                {
                                    ::ships2_1_1[l][j] = '/';
                                }
                            }
                            else
                            {
                                if ((::ships2_1_2[l][j] == TWO) || (::ships2_1_2[l][j + 1] == TWO) || (::ships2_1_2[l + 1][j] == TWO) || (::ships2_1_2[l + 1][j + 1] == TWO) || (::ships2_1_2[l - 1][j] == TWO) || (::ships2_1_2[l][j - 1] == TWO) || (::ships2_1_2[l - 1][j - 1] == TWO) || (::ships2_1_2[l + 1][j - 1] == TWO) || (::ships2_1_2[l - 1][j + 1] == TWO))
                                {
                                    ::ships2_1_2[l][j] = '/';
                                }
                            }
                        }
                        if (i == 1)
                        {
                            if (playerShips == 0)
                            {
                                if ((::ships2_2_1[l][j] == TWO) || (::ships2_2_1[l][j + 1] == TWO) || (::ships2_2_1[l + 1][j] == TWO) || (::ships2_2_1[l + 1][j + 1] == TWO) || (::ships2_2_1[l - 1][j] == TWO) || (::ships2_2_1[l][j - 1] == TWO) || (::ships2_2_1[l - 1][j - 1] == TWO) || (::ships2_2_1[l + 1][j - 1] == TWO) || (::ships2_2_1[l - 1][j + 1] == TWO))
                                {
                                    ::ships2_2_1[l][j] = '/';
                                }
                            }
                            else
                            {
                                if ((::ships2_2_2[l][j] == TWO) || (::ships2_2_2[l][j + 1] == TWO) || (::ships2_2_2[l + 1][j] == TWO) || (::ships2_2_2[l + 1][j + 1] == TWO) || (::ships2_2_2[l - 1][j] == TWO) || (::ships2_2_2[l][j - 1] == TWO) || (::ships2_2_2[l - 1][j - 1] == TWO) || (::ships2_2_2[l + 1][j - 1] == TWO) || (::ships2_2_2[l - 1][j + 1] == TWO))
                                {
                                    ::ships2_2_2[l][j] = '/';
                                }
                            }
                        }
                        if (i == 2)
                        {
                            if (playerShips == 0)
                            {
                                if ((::ships2_3_1[l][j] == TWO) || (::ships2_3_1[l][j + 1] == TWO) || (::ships2_3_1[l + 1][j] == TWO) || (::ships2_3_1[l + 1][j + 1] == TWO) || (::ships2_3_1[l - 1][j] == TWO) || (::ships2_3_1[l][j - 1] == TWO) || (::ships2_3_1[l - 1][j - 1] == TWO) || (::ships2_3_1[l + 1][j - 1] == TWO) || (::ships2_3_1[l - 1][j + 1] == TWO))
                                {
                                    ::ships2_3_1[l][j] = '/';
                                }
                            }
                            else
                            {
                                if ((::ships2_3_2[l][j] == TWO) || (::ships2_3_2[l][j + 1] == TWO) || (::ships2_3_2[l + 1][j] == TWO) || (::ships2_3_2[l + 1][j + 1] == TWO) || (::ships2_3_2[l - 1][j] == TWO) || (::ships2_3_2[l][j - 1] == TWO) || (::ships2_3_2[l - 1][j - 1] == TWO) || (::ships2_3_2[l + 1][j - 1] == TWO) || (::ships2_3_2[l - 1][j + 1] == TWO))
                                {
                                    ::ships2_3_2[l][j] = '/';
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (choice == 1) { cout << "Теперь расставьте однопалубные корабли (их 4)"; }

    for (int i = 0; i < 4; ++i)
    {
        if (choice == 1) { Show(player, attackField); }
        int vertical, horizontal;

        if (choice == 0)
        {
            vertical = rand() % 10 + 1;
            horizontal = rand() % 10 + 1;
        }
        else
        {
            for (int j = 0;; ++j)
            {
                cout << "\nВведите сначала куда поставить корабль по вертикали, потом по горизонтали\n";
                cin >> vertical >> horizontal;

                if ((vertical < 1) || (vertical > 10) || (horizontal < 1) || (horizontal > 10))
                {
                    cout << "\nКакие-то координаты или сторону Вы ввели неправильно, повторите попытку\n";
                }
                else break;
            }
        }
        if (player[vertical][horizontal] != '0')
        {
            if (choice == 1) { cout << "\nКлетка уже занята\n"; }
            --i;
        }
        else
        {
            player[vertical][horizontal] = ONE;
            if (i == 0)
            {
                if (playerShips == 0) { ::ships1_1_1[vertical][horizontal] = ONE; }
                if (playerShips == 1) { ::ships1_1_2[vertical][horizontal] = ONE; }
            }
            if (i == 1)
            {
                if (playerShips == 0) { ::ships1_2_1[vertical][horizontal] = ONE; }
                if (playerShips == 1) { ::ships1_2_2[vertical][horizontal] = ONE; }
            }
            if (i == 2)
            {
                if (playerShips == 0) { ::ships1_3_1[vertical][horizontal] = ONE; }
                if (playerShips == 1) { ::ships1_3_2[vertical][horizontal] = ONE; }
            }
            if (i == 3)
            {
                if (playerShips == 0) { ::ships1_4_1[vertical][horizontal] = ONE; }
                if (playerShips == 1) { ::ships1_4_2[vertical][horizontal] = ONE; }
            }
        }

        for (int l = 1; l < 11; ++l)
        {
            for (int j = 1; j < 11; ++j)
            {
                if ((player[l][j] == '0') || (player[l][j] == '/'))
                {
                    if ((player[l][j] == ONE) || (player[l][j + 1] == ONE) || (player[l + 1][j] == ONE) || (player[l + 1][j + 1] == ONE) || (player[l - 1][j] == ONE) || (player[l][j - 1] == ONE) || (player[l - 1][j - 1] == ONE) || (player[l + 1][j - 1] == ONE) || (player[l - 1][j + 1] == ONE))
                    {
                        player[l][j] = '/';
                        if (i == 0)
                        {
                            if (playerShips == 0)
                            {
                                if ((::ships1_1_1[l][j] == ONE) || (::ships1_1_1[l][j + 1] == ONE) || (::ships1_1_1[l + 1][j] == ONE) || (::ships1_1_1[l + 1][j + 1] == ONE) || (::ships1_1_1[l - 1][j] == ONE) || (::ships1_1_1[l][j - 1] == ONE) || (::ships1_1_1[l - 1][j - 1] == ONE) || (::ships1_1_1[l + 1][j - 1] == ONE) || (::ships1_1_1[l - 1][j + 1] == ONE))
                                {
                                    ::ships1_1_1[l][j] = '/';
                                }
                            }
                            else
                            {
                                if ((::ships1_1_2[l][j] == ONE) || (::ships1_1_2[l][j + 1] == ONE) || (::ships1_1_2[l + 1][j] == ONE) || (::ships1_1_2[l + 1][j + 1] == ONE) || (::ships1_1_2[l - 1][j] == ONE) || (::ships1_1_2[l][j - 1] == ONE) || (::ships1_1_2[l - 1][j - 1] == ONE) || (::ships1_1_2[l + 1][j - 1] == ONE) || (::ships1_1_2[l - 1][j + 1] == ONE))
                                {
                                    ::ships1_1_2[l][j] = '/';
                                }
                            }
                        }
                        if (i == 1)
                        {
                            if (playerShips == 0)
                            {
                                if ((::ships1_2_1[l][j] == ONE) || (::ships1_2_1[l][j + 1] == ONE) || (::ships1_2_1[l + 1][j] == ONE) || (::ships1_2_1[l + 1][j + 1] == ONE) || (::ships1_2_1[l - 1][j] == ONE) || (::ships1_2_1[l][j - 1] == ONE) || (::ships1_2_1[l - 1][j - 1] == ONE) || (::ships1_2_1[l + 1][j - 1] == ONE) || (::ships1_2_1[l - 1][j + 1] == ONE))
                                {
                                    ::ships1_2_1[l][j] = '/';
                                }
                            }
                            else
                            {
                                if ((::ships1_2_2[l][j] == ONE) || (::ships1_2_2[l][j + 1] == ONE) || (::ships1_2_2[l + 1][j] == ONE) || (::ships1_2_2[l + 1][j + 1] == ONE) || (::ships1_2_2[l - 1][j] == ONE) || (::ships1_2_2[l][j - 1] == ONE) || (::ships1_2_2[l - 1][j - 1] == ONE) || (::ships1_2_2[l + 1][j - 1] == ONE) || (::ships1_2_2[l - 1][j + 1] == ONE))
                                {
                                    ::ships1_2_2[l][j] = '/';
                                }
                            }
                        }
                        if (i == 2)
                        {
                            if (playerShips == 0)
                            {
                                if ((::ships1_3_1[l][j] == ONE) || (::ships1_3_1[l][j + 1] == ONE) || (::ships1_3_1[l + 1][j] == ONE) || (::ships1_3_1[l + 1][j + 1] == ONE) || (::ships1_3_1[l - 1][j] == ONE) || (::ships1_3_1[l][j - 1] == ONE) || (::ships1_3_1[l - 1][j - 1] == ONE) || (::ships1_3_1[l + 1][j - 1] == ONE) || (::ships1_3_1[l - 1][j + 1] == ONE))
                                {
                                    ::ships1_3_1[l][j] = '/';
                                }
                            }
                            else
                            {
                                if ((::ships1_3_2[l][j] == ONE) || (::ships1_3_2[l][j + 1] == ONE) || (::ships1_3_2[l + 1][j] == ONE) || (::ships1_3_2[l + 1][j + 1] == ONE) || (::ships1_3_2[l - 1][j] == ONE) || (::ships1_3_2[l][j - 1] == ONE) || (::ships1_3_2[l - 1][j - 1] == ONE) || (::ships1_3_2[l + 1][j - 1] == ONE) || (::ships1_3_2[l - 1][j + 1] == ONE))
                                {
                                    ::ships1_3_2[l][j] = '/';
                                }
                            }
                        }
                        if (i == 3)
                        {
                            if (playerShips == 0)
                            {
                                if ((::ships1_4_1[l][j] == ONE) || (::ships1_4_1[l][j + 1] == ONE) || (::ships1_4_1[l + 1][j] == ONE) || (::ships1_4_1[l + 1][j + 1] == ONE) || (::ships1_4_1[l - 1][j] == ONE) || (::ships1_4_1[l][j - 1] == ONE) || (::ships1_4_1[l - 1][j - 1] == ONE) || (::ships1_4_1[l + 1][j - 1] == ONE) || (::ships1_4_1[l - 1][j + 1] == ONE))
                                {
                                    ::ships1_4_1[l][j] = '/';
                                }
                            }
                            else
                            {
                                if ((::ships1_4_2[l][j] == ONE) || (::ships1_4_2[l][j + 1] == ONE) || (::ships1_4_2[l + 1][j] == ONE) || (::ships1_4_2[l + 1][j + 1] == ONE) || (::ships1_4_2[l - 1][j] == ONE) || (::ships1_4_2[l][j - 1] == ONE) || (::ships1_4_2[l - 1][j - 1] == ONE) || (::ships1_4_2[l + 1][j - 1] == ONE) || (::ships1_4_2[l - 1][j + 1] == ONE))
                                {
                                    ::ships1_4_2[l][j] = '/';
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

#endif // !SHOWANDSET_H;
