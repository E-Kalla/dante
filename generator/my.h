/*
** EPITECH PROJECT, 2018
** DANTE STAR
** File description:
** my.h
*/

#define UP 0
#define LEFT 1
#define RIGHT 2
#define DOWN 3

typedef struct lab_s {
    int cursor_x;
    int cursor_y;
    int perfect;
    int width;
    int height;
    char c;
    char **tab;
} t_lab;

int     end(t_lab *lab, int x, int y);
int	    neighbor(t_lab *lab, int y, int x);
int	    neighbor_up(t_lab *lab, int y, int x);
int	    neighbor_down(t_lab *lab, int y, int x);
int	    neighbor_left(t_lab *lab, int y, int x);
int	    neighbor_right(t_lab *lab, int y, int x);
void    secure_lab(t_lab *lab);
void    secure_exit(t_lab *lab);
int		my_neighbor(t_lab *all);
int     random_choice(t_lab *lab, int *x, int *y);
void	random_direction(int *dir);
int	    from_right(t_lab *lab, int *x, int *y);
int	    from_left(t_lab *lab, int *x, int *y);
int	    from_up(t_lab *lab, int *x, int *y);
int	    from_down(t_lab *lab, int *x, int *y);
int     my_put_nbr(int nb);
void    build(t_lab *lab);
int     error_manager(int ac, char **av);
int     my_putstr(char const *str);
void    my_putchar(char n);
int     my_put_nbr(int nb);
void    broke_wall(t_lab *lab);