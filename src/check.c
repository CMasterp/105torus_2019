/*
** EPITECH PROJECT, 2020
** check errors
** File description:
** checking errors
*/

#include "../include/my.h"

int check_arg(int ac, char **av)
{
    if (my_strlen(av[1]) != 1)
        exit(84);
    for (int i = 2; av[i] != NULL; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if ((av[i][j] < '0' || av[i][j] > '9') &&
                av[i][j] != '-' && av[i][j] != '.')
                exit(84);
        }
    }
    for (int k = 0; av[1][k] != '\0'; k++) {
        if (av[1][k] < '1' || av[1][k] > '3')
            exit(84);
    }
    if (atoi(av[7]) < 0)
        exit(84);
    return (0);
}
