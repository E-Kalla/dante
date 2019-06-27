/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** strr
*/

#include "../my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i += 1;
    }
    return (0);
}
