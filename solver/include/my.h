/*
** EPITECH PROJECT, 2018
** mylist.h
** File description:
** mylist.h
*/

#ifndef MY_H_
#define MY_H_
typedef struct possibili
{
    int *possib;
    float best_cost;
    int room_nbr;
    int len;
    int lines;
    int *act_neigh;
    int nbr_nei;
    int **rooms;
    char **read;
    int star;
    int *path;
    int act_p;
    float *cost;
    int n_path;
} possibili_t;
void    no_solution(void);
void init_struct(possibili_t *info);
int error_manager(char **argv);
int solver(char **av);
void get_map(char **av, possibili_t *info);
void exit_error_map(possibili_t *info);
void error_map(possibili_t *info);
void where_room(possibili_t *info);
void path_calc(possibili_t *info);
void init_int(possibili_t *info);
void check_neigh(possibili_t *info, int i);
void path_loop(possibili_t *info);
void check_roleback(possibili_t *info);
void change_read(possibili_t *info);
void clean_int(possibili_t *info, int *innt);
#endif
