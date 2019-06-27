/*
** EPITECH PROJECT, 2019
** my_tool
** File description:
** tooly
*/

#include "../include/my.h"
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void stock_in_struct(possibili_t *info, int i, int n)
{
    info->rooms[info->room_nbr][0] = info->room_nbr;
    if (info->read[i][n] == '*') {
        info->rooms[info->room_nbr][1] = info->star;
        info->star += 1;
    } else {
        info->rooms[info->room_nbr][1] = -1;
    }
    info->rooms[info->room_nbr][2] = n;
    info->rooms[info->room_nbr][3] = i;
    info->room_nbr += 1;
}

void where_room(possibili_t *info)
{
    int i = 0;
    int n = 0;

    for (i = 0; info->read[i] != NULL; i ++) {
        for (n = 0; info->read[i][n] != '\0'; n ++) {
            stock_in_struct(info, i, n);
        }
    }
}

void exit_error_map(possibili_t *info)
{
    write(2, "Error on your map !!!\n", 22);
    exit(84);
}

void error_map(possibili_t *info)
{
    int i = 0;
    int n = 0;
    int len = strlen(info->read[0]);

    init_int(info);
    for (i = 0; info->read[i] != NULL; i ++) {
        for (n = 0; info->read[i][n] != '\0'; n ++) {
            if (info->read[i][n] != '*' && info->read[i][n] != 'X')
                exit_error_map(info);
        }
        if (len != n && n != 0 && info->read[i][0] != '\0')
            exit_error_map(info);
    }
    if (info->read[0][0] == 'X' || info->read[i - 1][len] == 'X')
        no_solution();
    info->len = len;
    info->lines = i - 1;
}

void get_map(char **av, possibili_t *info)
{
    size_t buffsize = 1234;
    FILE *fd = fopen(av[1], "r");
    int i = 0;

    while (getline(&info->read[i], &buffsize, fd) != -1) {
        info->read[i + 1] = malloc(sizeof(char) * 12345);
        info->read[i][strlen(info->read[i]) - 1] = '\0';
        i ++;
    }
    info->read[i][0] = '\0';
    error_map(info);
    fclose(fd);
    where_room(info);
    path_calc(info);
}
