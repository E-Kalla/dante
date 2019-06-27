/*
** EPITECH PROJECT, 2019
** dante
** File description:
** build.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../my.h"
#include <time.h>

void     broke_wall(t_lab *lab)
{
    for (int i = 0; i < lab->height - 1 ; i += 1) {
        for (int j = 0; j < lab->width - 1; j += 1) {
            if (lab->tab[i][j] == 'X')
                if (rand() % 4 == 0)
                    lab->tab[i][j] = '*';
        }
    }
}

int		my_neighbor(t_lab *all)
{
    for (int a = 0; a < all->height ; a += 1) {
        for (int b = 0; b < all->width ; b += 1) {
            if (neighbor(all, a, b) != 1)
                return (0);
        }
    }
    return (1);
}

void     secure_exit(t_lab *lab)
{
    lab->tab[lab->height - 1][lab->width - 1] = '*';
    if (lab->tab[lab->height - 2][lab->width - 2] == '*' &&
        lab->tab[lab->height - 2][lab->width - 1] == 'X' &&
        lab->tab[lab->height - 1][lab->width - 2] == 'X')
        lab->tab[lab->height - 2][lab->width - 1] = '*';
}