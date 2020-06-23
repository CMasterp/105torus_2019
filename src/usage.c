/*
** EPITECH PROJECT, 2020
** usage
** File description:
** usage
*/

#include "../include/my.h"

void usage(void)
{
    printf("USAGE\n    ");
    printf("./105torus opt a0 a1 a2 a3 a4 n\n\n");
    printf("DESCRIPTION\n    ");
    printf("opt      method option:\n    ");
    printf("             1 for the bisection method\n    ");
    printf("             2 for Newton’s method\n    ");
    printf("             3 for the secant method\n    ");
    printf("a[0-4]   coefficients of the equation\n    ");
    printf("n        precision (the application of the polynomial ");
    printf("to the solution should\n             ");
    printf("be smaller than 10ˆ-n)");
}
