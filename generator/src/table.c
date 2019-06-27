/*
** EPITECH PROJECT, 2019
** dante
** File description:
** table
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../my.h"

void	random_direction(int *num)
{
    int a = rand() % 4;
    int b = rand() % 4;
    int tmp = 0;

    num[0] = UP;
    num[1] = LEFT;
    num[2] = RIGHT;
    num[3] = DOWN;
    tmp = num[a];
    num[a] = num[b];
    num[b] = tmp;
}

int     random_choice(t_lab *lab, int *x, int *y)
{
    int	num[4];

    random_direction(num);
    for (int i = 0; i < 4; i += 1) {
        if (num[i] == UP) {
            if (!from_up(lab, x, y))
                return (0);
        }
        else if (num[i] == LEFT) {
            if (!from_left(lab, x, y))
                return (0);
        }
        else if (num[i] == RIGHT) {
            if (!from_right(lab, x, y))
                return (0);
        }
        else if (num[i] == DOWN) {
            if (!from_down(lab, x, y))
                return (0);
        }
    }
    return (0);
}

void     build(t_lab *lab)
{
    int	x = lab->cursor_x;
    int	y = lab->cursor_y;

    while (end(lab, x, y) != 0)
        random_choice(lab, &x, &y);
}