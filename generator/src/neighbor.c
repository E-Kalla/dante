/*
** EPITECH PROJECT, 2019
** dante
** File description:
** huntt
*/

#include <stdio.h>
#include <stdlib.h>
#include "../my.h"

int     neighbor_left(t_lab *lab, int y, int x)
{
    int min = 0;

    lab->tab[y][(x > 0) ? x - 1 : x] = '*';
    lab->cursor_x = x;
    lab->cursor_y = y;
    lab->tab[y][x] = '*';
    return (0);
}

int     neighbor_right(t_lab *lab, int y, int x)
{
    int min = 0;

    lab->tab[y][(x < lab->width) ? x + 1 : x] = '*';
    lab->cursor_x = x;
    lab->cursor_y = y;
    lab->tab[y][x] = '*';
    return (0);
}

int	    neighbor_down(t_lab *lab, int y, int x)
{
    int min = 0;

    lab->tab[(y < lab->height) ? y + 1 : y][x] = '*';
    lab->cursor_x = x;
    lab->cursor_y = y;
    lab->tab[y][x] = '*';
    return (0);
}

int	    neighbor_up(t_lab *lab, int y, int x)
{
    int min = 0;

    lab->tab[(y > 0) ? y - 1 : y][x] = '*';
    lab->cursor_x = x;
    lab->cursor_y = y;
    lab->tab[y][x] = '*';
    return (0);
}