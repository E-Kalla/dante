/*
** EPITECH PROJECT, 2019
** path_calc.c
** File description:
** path_calc
*/

#include "../include/my.h"
#include <math.h>
#include <stdio.h>

void check_roleback(possibili_t *info)
{
    if (info->path[info->n_path] == info->path[info->n_path - 2]) {
        info->rooms[info->path[info->n_path - 1]][1] = -1;
    }
}

void clean_int(possibili_t *info, int *innt)
{
    long i = 0;

    while (innt[i]) {
        if (innt[i] == info->act_p) {
            innt[i] = 0;
        }
        i ++;
    }
}

void path_calc(possibili_t *info)
{
    int i = 0;
    int x = 0;
    int y = 0;
    int x2 = 0;
    int y2 = 0;
    float vector = 0;

    while (i < info->room_nbr) {
        x = (info->len) - (info->rooms[i][2]) - 1;
        y = (info->lines) - (info->rooms[i][3]) - 1;
        x2 = x * x;
        y2 = y * y;
        vector = sqrt((x2 + y2));
        info->cost[i] = vector;
        i ++;
    }
}
