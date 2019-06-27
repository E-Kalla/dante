/*
** EPITECH PROJECT, 2019
** solv_map
** File description:
** solv any solvable map
*/

#include "../include/my.h"
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void change_read(possibili_t *info)
{
    int i = 0;
    int n = 0;
    int n2 = 0;

    info->read[0][0] = 'o';
    while (i < info->n_path) {
        if (info->rooms[info->path[i]][1] != -1) {
            n = info->path[i] % info->len;
            n2 = (info->path[i] - n) / info->len;
            info->read[n2][n] = 'o';
        }
        i ++;
    }
}
