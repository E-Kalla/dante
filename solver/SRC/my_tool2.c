/*
** EPITECH PROJECT, 2019
** tool
** File description:
** tooly
*/

#include "../include/my.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void cost_cmp(possibili_t *info)
{
    int i = 0;

    while (i < info->nbr_nei) {
        if (info->best_cost > info->cost[info->act_neigh[i]]) {
            info->best_cost = info->cost[info->act_neigh[i]];
            info->act_p = info->act_neigh[i];
        }
        i ++;
    }
    info->path[info->n_path] = info->rooms[info->act_p][0];
    info->best_cost = 1234567;
    check_roleback(info);
    clean_int(info, info->act_neigh);
    info->nbr_nei = 0;
    check_roleback(info);
}

void check_neigh2(possibili_t *info, int i)
{
    if (i + info->len <= (info->len * info->lines)) {
        if (info->rooms[i + info->len][1] != -1) {
            info->act_neigh[info->nbr_nei] = info->rooms[i + info->len][0];
            info->nbr_nei += 1;
        }
    }
    cost_cmp(info);
}

void check_neigh(possibili_t *info, int i)
{
    if ((i + 1) % info->len != 0) {
        if (info->rooms[i + 1][1] != -1) {
            info->act_neigh[info->nbr_nei] = info->rooms[i + 1][0];
            info->nbr_nei += 1;
        }
    }
    if (i - 1 >= 0 && (i % info->len != 0)) {
        if (info->rooms[i - 1][1] != -1) {
            info->act_neigh[info->nbr_nei] = info->rooms[i - 1][0];
            info->nbr_nei += 1;
        }
    }
    if (i - info->len >= 0) {
        if (info->rooms[i - info->len][1] != -1) {
            info->act_neigh[info->nbr_nei] = info->rooms[i - info->len][0];
            info->nbr_nei += 1;
        }
    }
    check_neigh2(info, i);
}

void path_loop(possibili_t *info)
{
    while (info->path[info->n_path - 1] != (info->len * info->lines - 1)) {
        if (info->path[info->n_path - 5] == info->path[info->n_path - 4] &&
            info->path[info->n_path - 3] == info->path[info->n_path - 2] &&
            info->path[info->n_path - 2] == info->path[info->n_path - 1] &&
            info->n_path > 0)
            no_solution();
        check_neigh(info, info->rooms[info->act_p][0]);
        info->n_path += 1;
    }
}

void init_int(possibili_t *info)
{
    int i = 0;

    info->len = strlen(info->read[0]);
    for (i = 0; info->read[i] != NULL; i ++);
    info->lines = i;
    i = 0;
    info->rooms = malloc(sizeof(int) * info->lines * info->len * 5);
    while (i < (info->lines * info->len)) {
        info->rooms[i] = malloc(sizeof(int) * 5);
        i ++;
    }
    info->path = malloc(sizeof(int) * info->lines * info->len);
    info->n_path = 0;
    info->act_p = 0;
    info->cost = malloc(sizeof(float) * info->lines * info->len);
    info->possib = malloc(sizeof(int) * info->lines * info->len);
}
