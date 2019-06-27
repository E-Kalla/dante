/*
** EPITECH PROJECT, 2019
** dante
** File description:
** take
*/

#include "../my.h"

void     secure_lab(t_lab *lab)
{
    if (lab->tab[lab->height - 1][lab->width - 1] == 'X')
        secure_exit(lab);
    if (lab->perfect != 1) {
        broke_wall(lab);
    }
}