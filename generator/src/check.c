/*
** EPITECH PROJECT, 2019
** dante
** File description:
** check
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../my.h"

int     end(t_lab *lab, int x, int y)
{
    if (lab->tab[y][(x > 1) ? x - 2 : x] == 'X' ||
        lab->tab[y][(x < lab->width - 1) ? x + 2 : x] == 'X' ||
        lab->tab[(y > 1) ? y - 2 : y][x] == 'X' ||
        lab->tab[(y < lab->height - 2) ? y + 2 : y][x] == 'X')
        return (1);
    return (0);
}