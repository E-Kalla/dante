/*
** EPITECH PROJECT, 2019
** dante
** File description:
** main.c
*/

#include "../my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int	    init_lab(t_lab *lab)
{
    int	i = 0;
    int	j = 0;

    lab->tab = malloc(sizeof(char *) * (lab->height + 1));
    lab->tab[lab->height] = NULL;
    while (i < lab->height) {
        j = 0;
        lab->tab[i] = malloc(sizeof(char) * (lab->width + 1));
        while (j < lab->width) {
            lab->tab[i][j] = 'X';
            j += 1;
        }
        i += 1;
    }
    lab->tab[0][0] = '*';
    return (0);
}

void	display_tab(t_lab *lab)
{
    int	i = 0;
    int	j = 0;

    while (i < lab->height) {
        j = 0;
        while (j < lab->width) {
            my_putchar(lab->tab[i][j]);
            j += 1;
        }
        if (i != lab->height - 1)
            my_putchar('\n');
        i += 1;
    }
}

void    init_value(int ac, char **av, t_lab *lab)
{
    lab->width = atoi(av[1]);
    lab->height = atoi(av[2]);
    lab->cursor_x = 0;
    lab->cursor_y = 0;
    if (ac == 4 && strcmp(av[3],"perfect") == 0)
        lab->perfect = 1;
    else
        lab->perfect = 0; 
}

void    free_all(t_lab *lab)
{
    for (int i = 0; lab->tab[i] != NULL; i += 1) {
        free(lab->tab[i]);
    }
    free(lab->tab);
}

int     main(int ac, char **av)
{
    t_lab lab;

    error_manager(ac,av);
    srand(time(NULL));
    init_value(ac,av,&lab);
    init_lab(&lab);
    while (my_neighbor(&lab) == 0)
        build(&lab);
    secure_lab(&lab);
    display_tab(&lab);
    free_all(&lab);
    return (0);
}