/*
** EPITECH PROJECT, 2019
** dante
** File description:
** look for
*/

#include "../my.h"

int     from_right(t_lab *lab, int *x, int *y)
{
    if (lab->tab[*y][(*x < lab->width - 1) ? *x + 2 : *x] == 'X') {
        lab->tab[*y][(*x < lab->width) ? *x + 1 : *x] = '*';
        lab->tab[*y][(*x < lab->width - 1) ? *x + 2 : *x] = '*';
        *x = *x + 2;
        return (0);
    }
    return (1);
}