/*
** EPITECH PROJECT, 2019
** dante
** File description:
** all the nighbor
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../my.h"

int	    neighbor(t_lab *lab, int y, int x)
{
    if (lab->tab[y][x] == 'X') {
        if (lab->tab[y][(x > 0) ? x - 1 : x] == '*' ||
            lab->tab[y][(x > 0) ? x + 1 : x] == '*' ||
            lab->tab[(y > 0) ? y - 1 : y][x] == '*' ||
            lab->tab[(y < lab->height - 1) ? y + 1 : y][x] == '*')
            return (1);
        if (lab->tab[y][(x > 1) ? x - 2 : x] == '*')
            return (neighbor_left(lab, y, x));
        if (lab->tab[y][(x < lab->width - 2) ? x + 2 : x] == '*')
            return (neighbor_right(lab, y, x));
        if (lab->tab[(y < lab->height - 2) ? y + 2 : y][x] == '*')
            return (neighbor_down(lab, y, x));
        if (lab->tab[(y > 1) ? y - 2 : y][x] == '*')
            return (neighbor_up(lab, y, x));
    }
    return (1);
}