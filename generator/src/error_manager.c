/*
** EPITECH PROJECT, 2019
** dante
** File description:
** error_manager
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int     check_perfect(char *str)
{
    if (strcmp(str,"perfect") != 0) {
        write(2,"Third argument is wrong\n",25);
        exit (84);
    }
    return (0);
}

int     checklen(char *x, char *y)
{
    if (atoi(x) <= 1 || atoi(y) <= 1) {
        write(2,"Bad x/y\n",8);
        exit(84);
    }
    return (0);
}
int     error_manager(int ac, char **av)
{
    if (ac != 3 && ac != 4) {
        write(2,"Bad number of argument\n",23);
        exit(84);
    }
    checklen(av[1],av[2]);
    if (ac == 4)
        check_perfect(av[3]);
    return (0);
}