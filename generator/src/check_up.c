/*
** EPITECH PROJECT, 2019
** dante
** File description:
** look for
*/

#include "../my.h"

int     from_up(t_lab *lab, int *x, int *y)
{
    if (lab->tab[(*y > 1) ? *y - 2 : *y][*x] == 'X') {
        lab->tab[(*y > 0) ? *y - 1 : *y][*x] = '*';
        lab->tab[(*y > 1) ? *y - 2 : *y][*x] = '*';
        *y = *y - 2;
        return (0);
    }
    return (1);
}