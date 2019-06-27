/*
** EPITECH PROJECT, 2019
** main
** File description:
** main solver
*/

#include "../include/my.h"
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    no_solution(void)
{
    write(1, "no solution found\n", 18);
    exit (0);
}

void init_struct(possibili_t *info)
{
    info->best_cost = 1234567;
    info->room_nbr = 0;
    info->star = 0;
    info->nbr_nei = 0;
    info->act_neigh = malloc(sizeof(int) * 5);
    info->read = malloc(sizeof(char) * 123456);
    info->read[0] = malloc(sizeof(char) * 12345);
}

int solver(char **av)
{
    possibili_t *info = malloc(sizeof(possibili_t));
    int i = 0;

    init_struct(info);
    get_map(av, info);
    path_loop(info);
    change_read(info);
    i = 0;
    while (i < info->lines) {
        printf("%s\n", info->read[i]);
        i ++;
    }
    return (0);
}

int error_manager(char **argv)
{
    char const *fd = argv[1];
    struct stat st;

    if (stat(fd, &st) == -1) {
        write(2, "There is something wrong with your data\n", 40);
        exit(84);
    }
    if (st.st_size == 0) {
        write(2, "Nothing in your file !\n", 23);
        exit(84);
    }
    if (!(solver(argv)))
        exit(0);
    return (0);
}

int main(int ac, char **argv)
{
    if (ac == 2) {
        error_manager(argv);
    } else {
        write(2, "bad input !!\n", 13);
        return (84);
    }
    return (0);
}
