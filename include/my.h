/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef _MY_H

#define _MY_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct coefficients
{
    double a0;
    double a1;
    double a2;
    double a3;
    double a4;
    double n;
}t_coef;

void usage(void);
int my_strcmp(char *, char *);
int my_strlen(const char *);
int check_arg(int, char **);

#endif
